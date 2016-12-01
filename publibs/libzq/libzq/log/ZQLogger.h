//
//  ZQLogger.hpp
//  libzq
//
//  Created by staff on 16/11/14.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQLOGGER_HPP_
#define _ZQLOGGER_HPP_

#include <string>
#include <mutex>
#include "utils/ZQStringUtils.h"

namespace zq {
    
class ZQLogger
{
public:
    static ZQLogger* getInstance();
    
protected:
    ZQLogger();
    virtual ~ZQLogger();
    
public:
    virtual void error(const std::string &message) = 0;
    virtual void debug(const std::string &message) = 0;
    
public:
    
    std::string filePath();
    
    void write(std::string &message);
    
    void rename(std::string &file);
    
protected:
    bool _debug;
    
private:
    FILE *_file;
    std::string _path;
    std::mutex _file_mutex;
};
    
}

template <typename ...Args>
inline void ZQLogD(const char *format, Args... args)
{
    zq::ZQLogger::getInstance()->debug(zq::StringUtils::format(format, args...));
}

template <typename ...Args>
inline void ZQLogE(const char *format, Args... args)
{
    zq::ZQLogger::getInstance()->error(zq::StringUtils::format(format, args...));
}

#endif /* _ZQLOGGER_HPP_ */
