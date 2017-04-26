//
//  ZQFileManage.cpp
//  libzq
//
//  Created by staff on 16/11/4.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQFileManage.h"
#include <string>
#include <stdio.h>
#include "utils/ZQFs.h"
#include "utils/ZQStringUtils.h"
#include "net/ZQHTTPService.h"
#include "tool/ZQMD5.h"
#include "log/ZQLogger.h"

using namespace zq;

namespace
{
    template <typename ...Args>
    inline void ResLog(const char *fmt, Args... args)
    {
#if COCOS2D_DEBUG
        ZQLogD(fmt, args...);
#endif
    }
}

std::string ZQFileManage::_url_res;
std::string ZQFileManage::_url_code;

ZQFileManage* ZQFileManage::getInstance()
{
    static ZQFileManage instance;
    return &instance;
}

ZQFileManage::ZQFileManage()
{
    _fileUtils = cocos2d::FileUtils::getInstance();
    this->prepare();
}

ZQFileManage::~ZQFileManage()
{
    
}

std::string ZQFileManage::load_file(const std::string &filename)
{
    if (filename.empty())
        return "";
    
    std::string path = this->load_disk(filename);
    if (!path.empty())
        return path;
    
    std::string loc = ZQFileManage::cache_path() + filename;
    std::string url = ZQFileManage::url_for_file(filename);
    
    if (!url.empty())
    {
        HTTPService::getInstance()->download(url, loc);
        if (ZQFileManage::file_exist(loc))
        {
            ZQLogD("FileManage load file url: %s", url.c_str());
            return loc;
        }
        else
        {
            ZQLogE("download file not found: %s", filename.c_str());
            ZQFileManage:remove_file(loc);
        }
    }
    
    ZQLogE("load file not found: %s", filename.c_str());
    
    return "";
}

std::string ZQFileManage::load_disk(const std::string &filename)
{
    std::string path = ZQFileManage::cache_path() + filename;
    if (ZQFileManage::file_exist(path))
    {
        return path;
    }
    
    path = filename;
    if (cocos2d::FileUtils::getInstance()->isFileExist(path))
    {
        return path;
    }
    
    return "";
}

std::string ZQFileManage::file_string(const std::string &filename)
{
    cocos2d::Data data = this->file_data(filename);
    if (data.isNull())
        return "";
    
    std::string ret((const char*)data.getBytes(), data.getSize());
    return ret;
}

cocos2d::Data ZQFileManage::file_data(const std::string &filename)
{
    cocos2d::Data ret;
    
    std::string path;
    std::string name(filename);
    
    path = this->load_file(name);
    if (path.empty())
        return ret;
    
    ret = cocos2d::FileUtils::getInstance()->getDataFromFile(path);
    
    return ret;
}

std::string ZQFileManage::getStringFromFile(const std::string &filename)
{
    return  _fileUtils->getStringFromFile(filename);
}

cocos2d::Data ZQFileManage::getDataFromFile(const std::string &filename)
{
    return _fileUtils->getDataFromFile(filename);
}

bool ZQFileManage::isFileExist(const std::string &filename) const
{
   return _fileUtils->isFileExist(filename);
}

void ZQFileManage::addSearchPath(const std::string &path, const bool front)
{
    _fileUtils->addSearchPath(path, front);
}

std::string ZQFileManage::getWritablePath()
{
    return _fileUtils->getWritablePath();
}

bool ZQFileManage::createDirectory(const std::string &filePath)
{
    return _fileUtils->createDirectory(filePath);
}

bool ZQFileManage::removeDirectory(const std::string &filePath)
{
    return _fileUtils->removeDirectory(filePath);
}

bool ZQFileManage::removeFile(const std::string &filePath)
{
    return _fileUtils->removeFile(filePath);
}

bool ZQFileManage::renameFile(const std::string &oldfullpath, const std::string &newfullpath)
{
    return _fileUtils->renameFile(oldfullpath, newfullpath);
}

long ZQFileManage::getFileSize(const std::string &filepath)
{
    return _fileUtils->getFileSize(filepath);
}

void ZQFileManage::prepare()
{
    auto dir_cache = ZQFileManage::cache_path();
    auto dir_temp = ZQFileManage::temp_path();
    auto dir_log = ZQFileManage::log_path();
    
    ZQFileManage::create_folder(dir_cache);
    ZQFileManage::create_folder(dir_temp);
    ZQFileManage::create_folder(dir_log);
    
    ResLog("FileManage cache dir: %s", dir_cache.c_str());
    ResLog("FileManage temp dir: %s", dir_temp.c_str());
    ResLog("FileManage log dir: %s", dir_log.c_str());
    
}

void ZQFileManage::set_url_for_res(const std::string &url)
{
    ZQFileManage::_url_res = url;
}

void ZQFileManage::set_url_for_code(const std::string &url)
{
    ZQFileManage::_url_code = url;
}

std::string ZQFileManage::url_for_res()
{
    return ZQFileManage::_url_res;
}

std::string ZQFileManage::url_for_code()
{
    return ZQFileManage::_url_code;
}

std::string ZQFileManage::url_for_file(const std::string &filename)
{
    std::string ext(ZQFileManage::extname_of_path(filename));
    std::string url;
    if (ext == ".lua")
    {
        url = ZQFileManage::url_for_code();
    }
    else
    {
        url = ZQFileManage::url_for_res();
    }
    
    if (!url.empty())
    {
        url += filename + StringUtils::format("?%d", time(nullptr)/1800);
    }
    
    return url;
}

bool ZQFileManage::dir_exist(const std::string &path, bool create)
{
    bool exist = fs::is_dir(path);
    
    if (!exist && create)
        return ZQFileManage::create_folder(path);
    
    return exist;
}

bool ZQFileManage::file_exist(const std::string &path, const std::string &md5, bool remove_if_fail)
{
    bool exist = fs::is_file(path);
    
    if (exist && !md5.empty())
    {
        std::string hash = MD5::digest_file(path);
        exist = hash == md5 ? true : false;
        if (!exist)
        {
            if (remove_if_fail)
            {
                ZQFileManage::remove_file(path);
            }
        }
    }
    
    return exist;
}

uint32_t ZQFileManage::file_size(const std::string &path)
{
    return static_cast<uint32_t>(fs::file_size(path));
}

bool ZQFileManage::create_folder(const std::string &path)
{
    return fs::create(path);
}

bool ZQFileManage::rebuild_folder(const std::string &path)
{
    if (!fs::remove(path))
        return false;
    
    return fs::create(path);
}

bool ZQFileManage::remove_file(const std::string &path)
{
    return fs::remove(path);
}

bool ZQFileManage::rename_file(const std::string &old_path, const std::string &new_path)
{
    return fs::rename(old_path, new_path);
}

bool ZQFileManage::write_file(const std::string &path, const uint8_t *data, uint32_t size)
{
    ZQFileManage::create_folder(ZQFileManage::dirname_of_path(path));
    
    FILE* file = fopen(path.c_str(), "wb");
    
    if (!file)
    {
        return false;
    }
    
    if (fwrite(data, 1, size, file) != size)
    {
        fclose(file);
        ZQFileManage::remove_file(path);
        return false;
    }
    else
    {
        fclose(file);
    }
    
    return true;
}

bool ZQFileManage::append_file(const std::string &path, const uint8_t *data, uint32_t size)
{
    FILE* file = fopen(path.c_str(), "ab");
    if (!file)
    {
        return false;
    }
    
    if (fwrite(data, 1, size, file) != size)
    {
        fclose(file);
        ZQFileManage::remove_file(path);
        return false;
    }
    else
    {
        fclose(file);
    }
    
    return true;
}

std::string ZQFileManage::dirname_of_path(const std::string &path, bool with_slash)
{
    std::string dir = "";
    std::size_t index = path.find_last_of("/\\");
    if (index != std::string::npos)
    {
        dir = path.substr(0, index);
    }
    
    if (!dir.empty())
    {
        if (with_slash)
            return dir + "/";
    }
        
    return dir;
}

std::string ZQFileManage::extname_of_path(const std::string &path, bool with_dot)
{
    auto ext = fs::extname(path);
    return with_dot || ext.empty() ? ext : ext.substr(1);
}

std::string ZQFileManage::basename_of_path(const std::string &path, bool with_ext)
{
    std::string basename = "";
    size_t last_separator_pos = path.find_last_of("\\/");
    if (std::string::npos != last_separator_pos)
    {
        basename = path.substr(last_separator_pos+1);
    }
    
    if (!with_ext)
    {
        size_t dot_pos = basename.rfind('.');
        if (std::string::npos != dot_pos)
        {
            basename = basename.substr(0, dot_pos);
        }

    }
    
    return basename;
}

std::string ZQFileManage::temp_path()
{
    static std::string temp_path;
    if (temp_path.empty())
    {
        temp_path = cocos2d::FileUtils::getInstance()->getWritablePath() + "_temp/";
    }
    
    return temp_path;
}

std::string ZQFileManage::log_path()
{
    static std::string log_path;
    if (log_path.empty())
    {
        log_path = cocos2d::FileUtils::getInstance()->getWritablePath() + "_log/";
    }
    
    return log_path;
}

std::string ZQFileManage::cache_path()
{
    static std::string cache_path;
    if (cache_path.empty())
    {
        cache_path = cocos2d::FileUtils::getInstance()->getWritablePath() + "_cache/";
    }
    
    return cache_path;
}

