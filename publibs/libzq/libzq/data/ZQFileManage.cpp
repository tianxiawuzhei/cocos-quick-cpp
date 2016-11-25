//
//  ZQFileManage.cpp
//  libzq
//
//  Created by staff on 16/11/4.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQFileManage.h"
#include <string>

using namespace cocos2d;
using namespace zq;

ZQFileManage* ZQFileManage::getInstance()
{
    static ZQFileManage instance;
    return &instance;
}

ZQFileManage::ZQFileManage()
{
    _fileUtils = cocos2d::FileUtils::getInstance();
}

ZQFileManage::~ZQFileManage()
{
   
}

void ZQFileManage::init()
{
    auto temp = ZQFileManage::tempDir();
    
}

std::string ZQFileManage::getStringFromFile(const std::string &filename)
{
    return  _fileUtils->getStringFromFile(filename);
}

Data ZQFileManage::getDataFromFile(const std::string &filename)
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

std::string ZQFileManage::getFileExtension(const std::string &filePath) const
{
    return _fileUtils->getFileExtension(filePath);
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

std::string ZQFileManage::getFileBaseName(const std::string &filepath)
{
    std::size_t index = filepath.find_last_of("\\/");
    std::string name = "";
    if (index != std::string::npos)
    {
        name = filepath.substr(index+1);
    }
    else
    {
        name = filepath;
    }
    
    return name;
}

std::string ZQFileManage::getDirPath(const std::string &filepath)
{
    std::string dir = "";
    std::size_t index = filepath.find_last_of("/\\");
    if (index != std::string::npos)
    {
        dir = filepath.substr(0, index) + "/";
    }
    
    return dir;
}

std::string ZQFileManage::tempDir()
{
    auto write = _fileUtils->getWritablePath();
    static std::string temp_path;
    if (temp_path.empty())
    {
        temp_path = write + "_temp/";
    }
    
    return temp_path;
}

std::string ZQFileManage::logDir()
{
    auto write = _fileUtils->getWritablePath();
    static std::string log_path;
    if (log_path.empty())
    {
        log_path = write + "_log/";
    }
    
    return log_path;
}

