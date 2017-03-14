/***********************************************
* ZQHTTPService.cpp
*
* @author: zyq
* @date: 17/2/24
* @Description:
*
***********************************************/

#include "ZQHTTPService.h"
#include <thread>
#include <functional>
#include <chrono>
#include <sys/stat.h>
#include "tool/ZQDeviceInfo.h"
#include "data/ZQJsonManage.h"
#include "data/ZQFileManage.h"
#include "core/ZQRunLoop.h"
#include "log/ZQLogger.h"
#include "curl/curl.h"

using namespace zq;

HTTPService* HTTPService::getInstance()
{
    static HTTPService instance;
    return &instance;
}

HTTPService::HTTPService()
: _sync(nullptr)
{
    curl_global_init(CURL_GLOBAL_ALL);
}

HTTPService::~HTTPService()
{
    curl_global_cleanup();
    
    if (this->_sync)
        curl_easy_cleanup(this->_sync);
}

void HTTPService::request(HTTPTask* task)
{
    if (task->async())
    {
        task->retain();
        std::thread(std::bind(&HTTPService::launch, this, task)).detach();
    }
    else
    {
        {
            std::lock_guard<std::mutex> lock(this->_sync_mutex);
            this->spawn(task, &this->_sync);
            this->start(task, this->_sync);
        }
    }
}

void HTTPService::download(const std::string &url, const std::string &loc, const std::string &md5,
                           bool async, const std::function<void (HTTPTask*)> &callback)
{
    auto task = new HTTPTask;
    task->setUrl(url);
    task->setLoc(loc);
    task->setMD5(md5);
    task->setAsync(async);
    task->setCallback(callback);
    
    this->request(task);
    
    task->release();
}

void HTTPService::suspend(HTTPTask *task)
{
    task->suspend();
    task->setCallback(nullptr);
}

void HTTPService::launch(HTTPTask *task)
{
    CURL *handle = nullptr;
    {
        std::lock_guard<std::mutex> lock(this->_curl_mutex);
        if (this->_curl.size())
        {
            handle = this->_curl.front();
            this->_curl.pop_front();
        }
        
        this->spawn(task, &handle);
    }
    
    this->start(task, handle);
    
    {
        std::lock_guard<std::mutex> lock(this->_curl_mutex);
        this->_curl.push_back(handle);
    }
    
    ZQRunLoop::getInstance()->schedule(std::bind(&HTTPService::finish, this, task), this);
    
}

void HTTPService::finish(HTTPTask *task)
{
    task->emitCallback();
    
    task->release();
}

void HTTPService::spawn(HTTPTask *task, CURL **curl)
{
    if (!*curl)
        *curl = curl_easy_init();
    
    CURL *handle = *curl;
    
    curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, HTTPTask::curl_header);
    curl_easy_setopt(handle, CURLOPT_HEADERDATA, (void*)task);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, HTTPTask::curl_recv);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, (void*)task);
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(handle, CURLOPT_PROGRESSFUNCTION, HTTPTask::curl_progress);
    curl_easy_setopt(handle, CURLOPT_PROGRESSDATA, (void*)task);
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(handle, CURLOPT_COOKIEFILE, "");
}

void HTTPService::start(HTTPTask *task, CURL *curl)
{
    auto data_body   = task->body();
    auto data_upload = task->upload();
    auto data_post   = task->post();
    auto data_header = task->header();
    
    std::string post;
    if (!data_post.empty())
    {
        for (auto &pair : data_post)
            post += pair.first + "=" + pair.second.asString() + "&";
        
        post.erase(post.end() - 1);  // remove last '&'
    }
    
    if (!data_body.empty())
    {
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data_body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data_body.size());
    }
    else if (!data_post.empty())
    {
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, post.size());
    }
    
    struct curl_slist *header = nullptr;
    for (auto &it : data_header)
    {
        std::string item(it.first + ": " + it.second.asString());
        header = curl_slist_append(header, item.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
    
    FILE* handle = !data_upload.empty() ? fopen(data_upload.c_str(), "rb") : nullptr;
    if (handle)
    {
        struct stat info = {0};
        stat(data_upload.c_str(), &info);
        
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, handle);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)info.st_size);
    }
    
    curl_easy_setopt(curl, CURLOPT_URL, task->url().c_str());
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, task->limitSpeed());
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, task->limitTime());
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, task->timeout());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, task->follow() ? 1L : 0L);
    
    auto encoding = task->encoding();
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, !encoding.empty() ? encoding.c_str() : nullptr);
    
    // count
    task->setCount(task->count() + 1);
    
    // buffer
    task->clearBuffer();
    
    // curl
    task->setCURL(curl);
    
    task->setClock(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0);
    
    
    long status = 0;
    int try_num = task->retry() + 1;
    CURLcode error = CURLE_OK;
    while (try_num > 0)
    {
        off_t resume = 0;
        
        if (!task->tmp().empty())
        {
            struct stat st = {0};
            if (stat(task->tmp().c_str(), &st) == 0)
                resume = st.st_size;
        }
        
        curl_easy_setopt(curl, CURLOPT_RESUME_FROM, resume);
        
        task->setRunning(true);
        error = curl_easy_perform(curl);
        task->setRunning(false);
        
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
        
        if ((error == CURLE_OK) || (error == CURLE_ABORTED_BY_CALLBACK))
        {
            break;
        }
        else
        {
            task->clearBuffer();
        }
        
        --try_num;
    }
    
    if (handle)
    {
        fclose(handle);
        handle = nullptr;
    }
    
    task->setCURL(nullptr);
    if (error != CURLE_OK)
    {
        status = 0;
        task->clearBuffer();
    }
    
    task->setStatus((int)status);
    
    auto clock_end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0;
    double off = clock_end - task->clock();
    task->setProgress(1.0);
    if (off)
    {
        task->setSpeed(task->bufferSize() / off);
    }
    
    if (!status)
    {
        
    }
    else if (task->success() || status == 416)
    {
        task->renameFile();
    }
    
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 0L);
    curl_easy_setopt(curl, CURLOPT_READDATA, nullptr);
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)0);
    
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
    
    curl_easy_setopt(curl, CURLOPT_POST, 0L);
    curl_slist_free_all(header);
    
}


HTTPTask::HTTPTask()
: _status(0)
, _timeout(10)
, _retry(2)
, _count(0)
, _async(false)
, _follow(true)
, _speed(0)
, _running(false)
, _length(0)
, _clock(0)
, _total(0)
, _progress(0)
, _limit_speed(500)
, _limit_time(10)
, _bytes(0)
, _suspend(false)
, _curl(nullptr)
{
    std::string ua(ZQDeviceInfo::getInstance()->browser_useragent());
    if (!ua.empty())
        this->setHeader("User-Agent", ua);
}


HTTPTask::~HTTPTask()
{
    
}

std::string HTTPTask::url() const
{
    return this->_url;
}

std::string HTTPTask::loc() const
{
    return this->_loc;
}

std::string HTTPTask::tmp() const
{
    return this->_tmp;
}

std::string HTTPTask::md5() const
{
    return this->_md5;
}

std::string HTTPTask::toText() const
{
    return std::string((char*)&this->_buffer[0], this->_buffer.size());
}

cocos2d::ValueMap HTTPTask::toDict() const
{
    return ZQJsonManage::getInstance()->text_dict(this->toText());
}

cocos2d::ValueVector HTTPTask::toArray() const
{
    return ZQJsonManage::getInstance()->text_array(this->toText());
}

int HTTPTask::status() const
{
    return this->_status;
}

bool HTTPTask::success() const
{
    return (this->_status == 200)
    || (this->_status == 206);
}

bool HTTPTask::running() const
{
    return this->_running;
}

bool HTTPTask::async() const
{
    return this->_async;
}

bool HTTPTask::follow() const
{
    return this->_follow;
}

float HTTPTask::speedByte() const
{
    return this->_speed;
}

float HTTPTask::speedKilo() const
{
    return this->_speed / 1024.0;
}

float HTTPTask::speedMega() const
{
    return this->_speed / 1048576.0;
}

double HTTPTask::clock() const
{
    return this->_clock;
}

double HTTPTask::total() const
{
    return this->_total;
}

int HTTPTask::timeout() const
{
    return this->_timeout;
}

int HTTPTask::retry() const
{
    return this->_retry;
}

int HTTPTask::count() const
{
    return this->_count;
}

int HTTPTask::limitSpeed() const
{
    return this->_limit_speed;
}

int HTTPTask::limitTime() const
{
    return this->_limit_time;
}

std::string HTTPTask::body() const
{
    return this->_body;
}

std::string HTTPTask::upload() const
{
    return this->_upload;
}

const cocos2d::ValueMap& HTTPTask::post() const
{
    return this->_post;
}

const cocos2d::ValueMap& HTTPTask::header() const
{
    return this->_header;
}

const cocos2d::ValueMap& HTTPTask::response() const
{
    return this->_response;
}

std::string HTTPTask::encoding() const
{
    return this->_encoding;
}

size_t HTTPTask::bufferSize() const
{
    return this->_bytes;
}

const std::vector<unsigned char>& HTTPTask::rawBuffer() const
{
    return this->_buffer;
}

CURL* HTTPTask::curl() const
{
    return this->_curl;
}

void HTTPTask::dump() const
{
    
}

float HTTPTask::progress() const
{
    return this->_progress;
}

void HTTPTask::setUrl(const std::string &url)
{
    this->_url = url;
}

void HTTPTask::setLoc(const std::string &loc)
{
    this->_loc = loc;
    this->_tmp = ZQFileManage::temp_path() + ZQFileManage::basename_of_path(loc);
}

void HTTPTask::setMD5(const std::string &md5)
{
    this->_md5 = md5;
}

void HTTPTask::setStatus(int status)
{
    this->_status = status;
}

void HTTPTask::setRunning(bool running)
{
    this->_running = running;
    
    if (running)
    {
        struct stat st = {0};
        bool     exist = (stat(this->_tmp.c_str(), &st) == 0) ? true : false;
        
        if (exist)
            this->_length = (long)st.st_size;
    }
}

void HTTPTask::setTimeout(int timeout)
{
    this->_timeout = timeout;
}

void HTTPTask::setRetry(int retry)
{
    this->_retry = retry;
}

void HTTPTask::setCount(int count)
{
    this->_count = count;
}

void HTTPTask::setLowLimit(int speed, int time)
{
    this->_limit_speed = speed;
    this->_limit_time = time;
}

void HTTPTask::setAsync(bool async)
{
    this->_async = async;
}

void HTTPTask::setFollow(bool follow)
{
    this->_follow = follow;
}

void HTTPTask::setSpeed(float speed)
{
    this->_speed = speed;
}

void HTTPTask::setClock(double clock)
{
    this->_clock = clock;
}

void HTTPTask::setProgress(float progress)
{
    this->_progress = progress;
}

void HTTPTask::setBody(const std::string &body)
{
    this->_body = body;
    
    if (this->_header.find("Content-Type") == this->_header.end())
        this->setHeader("Content-Type", "text/plain;charset=UTF-8");
}

void HTTPTask::setUpload(const std::string &path)
{
    this->_upload = path;
}

void HTTPTask::setPost(const std::string &key, const std::string &value)
{
    this->_post[key] = value;
    
    if (this->_header.find("Expect") == this->_header.end())
        this->setHeader("Expect", "");
}

void HTTPTask::setHeader(const std::string &type, const std::string &value)
{
    this->_header[type] = value;
}

void HTTPTask::setEncoding(const std::string &encoding)
{
    this->_encoding = encoding;
}

void HTTPTask::setCallback(const std::function<void (HTTPTask *)> &callback)
{
    this->_callback = callback;
}

void HTTPTask::emitCallback()
{
    if (this->_callback)
    {
        this->_callback(this);
    }
}

void HTTPTask::writeFile()
{
    long status = 0;
    curl_easy_getinfo(this->_curl, CURLINFO_RESPONSE_CODE, &status);
    this->setStatus((int)status);
    
    if (!this->success() || this->_tmp.empty() || this->_loc.empty() || this->_buffer.empty() || this->_suspend)
        return;
    
    if (ZQFileManage::append_file(this->_tmp, &this->_buffer[0], (uint32_t)this->_buffer.size()))
    {
        this->_buffer.clear();
    }
    
}

void HTTPTask::renameFile()
{
    if (this->_tmp.empty() || this->_loc.empty() || !ZQFileManage::file_exist(this->_tmp))
        return;
    
    ZQFileManage::rename_file(this->_tmp, this->_loc);
    
    if (!this->_md5.empty() && ZQFileManage::file_exist(this->_loc, this->_md5, true))
        ZQLogE("HTTPTask write file md5 error: %s, %s, %s", this->_url.c_str(), this->_loc.c_str(), this->_md5.c_str());
}

void HTTPTask::clearBuffer()
{
    this->_bytes = 0;
    this->_buffer.clear();
}

void HTTPTask::setCURL(CURL *curl)
{
    this->_curl = curl;
}

void HTTPTask::suspend()
{
    this->_suspend = true;
}

void HTTPTask::retain()
{
    cocos2d::Ref::retain();
}

void HTTPTask::release()
{
    cocos2d::Ref::release();
}

size_t HTTPTask::curl_header(char *buffer, size_t size, size_t nitems, void *userdata)
{
    if (size*nitems == 0)
        return 0;
    
    return ((HTTPTask*)userdata)->self_header(buffer, size, nitems);
}

size_t HTTPTask::self_header(char *buffer, size_t size, size_t nitems)
{
    return size*nitems;
}

size_t HTTPTask::curl_recv(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    return ((HTTPTask*)userdata)->self_recv(ptr, size, nmemb);
}

size_t HTTPTask::self_recv(char *ptr, size_t size, size_t nmemb)
{
    size_t size_recv = size*nmemb;
    size_t size_buff = this->_buffer.size();
    
    this->_bytes += size_recv;
    this->_buffer.resize(size_recv + size_buff);
    std::copy(ptr, ptr + size_recv, this->_buffer.begin() + size_buff);
    
    this->writeFile();
    
    return size_recv;
}

int HTTPTask::curl_progress(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    return ((HTTPTask*)clientp)->self_progress(dltotal, dlnow, ultotal, ulnow);
}

int HTTPTask::self_progress(double dltotal, double dlnow, double ultotal, double ulnow)
{
    if (this->_suspend)
        return CURL_READFUNC_ABORT;
    
    if (!dltotal)
        return 0;
    
    if (this->_status == 301 || this->_status == 302)
        return 0;
    
    this->_total = dltotal;
    
    if (dlnow)
    {
        dlnow += this->_length;
        dltotal += this->_length;
        
        if (dltotal)
            this->setProgress(dlnow / dltotal);
    }
    
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0 - this->clock();
    
    if (time > 0)
        this->setSpeed(dlnow / time);
    
    return 0;
}
