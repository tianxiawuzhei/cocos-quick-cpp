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

ZQFileManage* ZQFileManage::s_instanceZQFileManage = nullptr;

ZQFileManage* ZQFileManage::getInstance()
{
   if (s_instanceZQFileManage == nullptr)
    {
       s_instanceZQFileManage = new (std::nothrow) ZQFileManage();
       if(!s_instanceZQFileManage->init())
        {
           delete s_instanceZQFileManage;
           s_instanceZQFileManage = nullptr;
           CCLOG("ERROR: Could not init s_instanceZQFileManage");
        }
    }
   
   return s_instanceZQFileManage;
}

ZQFileManage::ZQFileManage()
{
}

ZQFileManage::~ZQFileManage()
{
   
}

bool ZQFileManage::init()
{
   _fileUtils = cocos2d::FileUtils::getInstance();
   if (_fileUtils)
    {
       return true;
    }
   
    return false;
}

std::string ZQFileManage::getStringFromFile(const std::string &filename)
{
    return  _fileUtils->getStringFromFile(filename)
}

Data ZQFileManage::getDataFromFile(const std::string &filename)
{
    return _fileUtils->getDataFromFile(filename);
}

bool ZQFileManage::isFileExist(const std::string &filename)
{
   return _fileUtils->isFileExist(filename);
}

void ZQFileManage::addSearchPath(const std::string &path)
{
    _fileUtils->addSearchPath(path);
}

std::string ZQFileManage::getWritablePath()
{
    return _fileUtils->getWritablePath();
}

