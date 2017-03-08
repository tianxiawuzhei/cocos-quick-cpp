//
//  ZQLogger.cpp
//  libzq
//
//  Created by staff on 16/11/14.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQLogger.h"
#include "utils/ZQDateUtils.h"
#include "platform/ios/ZQLoggerIOS.h"
#include "platform/mac/ZQLoggerMac.h"
#include "cocos2d.h"
#include "data/ZQFileManage.h"
using namespace zq;

ZQLogger* ZQLogger::getInstance()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return ZQLoggerIOS::getInstance();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    return ZQLoggerMac::getInstance();
#endif
}

ZQLogger::ZQLogger():_file(nullptr)
{
#if COCOS2D_DEBUG == 1
    this->_debug = true;
#else
    this->_debug = false;
#endif
    
    auto fileManage = ZQFileManage::getInstance();
    auto logDir = fileManage->logDir();
    fileManage->createDirectory(logDir);
    auto logFile = logDir + "temp.log";
    
    this->_path = logFile;
    this->_file = fopen(logFile.c_str(), "a+");
}

ZQLogger::~ZQLogger()
{
    if (this->_file)
    {
        fclose(this->_file);
    }
}

std::string ZQLogger::filePath()
{
    return _path;
}

void ZQLogger::write(std::string &message)
{
    if (!this->_file)
        return;
    
    std::lock_guard<std::mutex> lock(_file_mutex);
    auto date = DateUtils::date();
    auto time = DateUtils::time(":", false, true);
    auto text = date + " " + time + "  " + message + "\n";
    fwrite(text.data(), text.size(), 1, _file);
    fflush(_file);
}

void ZQLogger::rename(std::string &file)
{
    std::lock_guard<std::mutex> lock(_file_mutex);

    if (file.empty())
    {
        return;
    }
    
    if (_file)
    {
        fclose(_file);
    }
    
    auto fileManage = ZQFileManage::getInstance();
    auto dirPath = fileManage->dirname_of_path(this->_path, true);
    auto newFile = dirPath + file;
    fileManage->renameFile(this->_path, newFile);
    this->_path = newFile;
    
    this->_file = fopen(this->_path.c_str(), "a+");
    
}

