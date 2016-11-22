//
//  ZQFileManage.cpp
//  libzq
//
//  Created by staff on 16/11/4.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQFileManage.hpp"
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

