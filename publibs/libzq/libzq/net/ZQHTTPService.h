/***********************************************
* ZQHTTPService.h
*
* @author: zyq
* @date: 17/2/24
* @Description:
*
***********************************************/

#ifndef __ZQHTTPSERVICE_H__
#define __ZQHTTPSERVICE_H__

#include <string>
#include <functional>
#include <mutex>
#include <list>
#include "cocos2d.h"

namespace zq
{
    class HTTPTask;
    typedef void CURL;
    class HTTPService
    {
    public:
        static HTTPService* getInstance();
        
    protected:
        HTTPService();
        virtual ~HTTPService();
        
    public:
        void request(HTTPTask* task);
        
        void download(const std::string &url,
                      const std::string &loc,
                      const std::string &md5 = "",
                      bool async = false,
                      const std::function<void (HTTPTask*)> &callback = nullptr);
        
        void suspend(HTTPTask *task);
    protected:
        void launch(HTTPTask* task);
        void finish(HTTPTask* task);
        
        void spawn(HTTPTask* task, CURL** curl);
        void start(HTTPTask* task, CURL* curl);
        
    private:
        CURL* _sync;
        std::mutex _sync_mutex;
        
        std::mutex _curl_mutex;
        std::list<CURL*> _curl;
    };
    
    class HTTPTask : public cocos2d::Ref
    {
    public:
        static HTTPTask* create();
    
    public:
        HTTPTask();
        virtual ~HTTPTask();
        
    public:
        std::string url() const;
        std::string loc() const;
        std::string tmp() const;
        std::string md5() const;
        
        std::string          toText()  const;
        cocos2d::ValueMap    toDict()  const;
        cocos2d::ValueVector toArray() const;
        
        int  status()  const;
        bool success() const;
        bool running() const;
        bool async()   const;
        bool follow()  const;
        
        float speedByte() const;
        float speedKilo() const;
        float speedMega() const;
        
        double clock() const;
        double total() const;
        
        float progress() const;
        
        int timeout() const;
        int retry() const;
        int count() const;
        
        int limitSpeed() const;
        int limitTime() const;
        
        std::string body() const;
        std::string upload() const;
        
        const cocos2d::ValueMap& post() const;
        const cocos2d::ValueMap& header() const;
        const cocos2d::ValueMap& response() const;
        
        std::string encoding() const;
        
        size_t bufferSize() const;
        const std::vector<unsigned char>& rawBuffer() const;
        CURL* curl() const;
        
        void dump() const;
        
    public:
        void setUrl(const std::string &url);
        void setLoc(const std::string &loc);
        void setMD5(const std::string &md5);
        
        void setStatus(int status);
        void setRunning(bool running);
        void setTimeout(int timeout);
        void setRetry(int retry);
        void setCount(int count);
        void setLowLimit(int speed, int time);
        
        void setAsync(bool async);
        void setFollow(bool follow);
        
        void setSpeed(float speed);
        void setClock(double clock);
        
        void setProgress(float progress);
        
        void setBody(const std::string &body);
        void setUpload(const std::string &path);
        
        void setPost(const std::string &key, const std::string &val);
        void setHeader(const std::string &type, const std::string &value);
        void setEncoding(const std::string &encoding);
        
        void setCallback(const std::function<void (HTTPTask*)> &callback);
        void emitCallback();
        
        void writeFile();
        void renameFile();
        void clearBuffer();
        
        void setCURL(CURL *curl);
        
        void suspend();
        
        void retain();
        void release();
        
    public:
        static size_t curl_header(char *buffer, size_t size, size_t nitems, void *userdata);
        size_t self_header(char *buffer, size_t size, size_t nitems);
        
        static size_t curl_recv(char *ptr, size_t size, size_t nmemb, void *userdata);
        size_t self_recv(char *ptr, size_t size, size_t nmemb);
        
        static int curl_progress(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow);
        int self_progress(double dltotal, double dlnow, double ultotal, double ulnow);
        
    private:
        std::string _url;
        std::string _loc;
        std::string _tmp;
        std::string _md5;
        
        int _status;
        int _timeout;
        int _retry;
        int _count;
        
        int _limit_speed;
        int _limit_time;
        
        bool   _async;
        bool   _follow;
        
        float  _speed;
        double _clock;
        double _total;
        
        bool  _running;
        long  _length;
        float _progress;
        
        std::string _body;
        std::string _upload;
        std::string _encoding;
        
        cocos2d::ValueMap _post;
        cocos2d::ValueMap _header;
        cocos2d::ValueMap _response;
        
        size_t _bytes;
        std::vector<unsigned char> _buffer;
        
        std::function<void (HTTPTask*)> _callback;
        
        bool _suspend;
        
        CURL *_curl;

        
    };
}


#endif /* defined(__ZQHTTPSERVICE_H__) */
