//
//  ZQLoggerIos.cpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//
#ifdef ANDROID

#include "ZQLoggerAnd.h"
#include "jni/JniHelper.h"
using namespace zq;

ZQLoggerAnd* ZQLoggerAnd::getInstance()
{
    static ZQLoggerAnd instance;
    return &instance;
}

void ZQLoggerAnd::error(const std::string &message)
{
    std::string temp("[ERROR] " + message);
    
    __android_log_print(ANDROID_LOG_ERROR, "cocos2d-x debug info",  "%s", temp.c_str());
    
    this->write(temp);
}

void ZQLoggerAnd::debug(const std::string &message)
{
    if (!this->_debug)
        return;
    
    std::string temp("[DEBUG] " + message);
    
    __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info",  "%s", temp.c_str());
    
    this->write(temp);
}

#endif
