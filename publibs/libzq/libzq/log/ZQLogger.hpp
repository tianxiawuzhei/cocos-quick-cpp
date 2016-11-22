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

namespace zq {
    
class ZQLogger
{
public:
    ZQLogger* getInstance();
    
protected:
    ZQLogger() = default;
    ~ZQLogger() = default;
    
public:
    virtual bool init();
    
    virtual void error(std::string &message) = 0;
    virtual void debug(std::string &message) = 0;
    
public:
    
    std::string filePath();
    
    void write(std::string &message);
private:
    bool _debug;
    FILE *_file;
    std::string _path;
    std::mutex _file_mutex;
};
    
}

#endif /* _ZQLOGGER_HPP_ */
