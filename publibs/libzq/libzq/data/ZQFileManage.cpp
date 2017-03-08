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

bool ZQFileManage::appendFile(const std::string &path, const uint8_t *data, uint32_t size)
{
    FILE* file = fopen(path.c_str(), "ab");
    if (!file)
    {
        return false;
    }
    
    if (fwrite(data, 1, size, file) != size)
    {
        fclose(file);
        this->removeFile(path);
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
    std::string file_ext;
    size_t dot_pos = path.find_last_of('.');
    size_t last_separator_pos = path.find_last_of("/\\");
    if (dot_pos != std::string::npos)
    {
        if (last_separator_pos != std::string::npos)
        {
            if (dot_pos < last_separator_pos)
            {
                return "";
            }
        }
        
        file_ext = path.substr(dot_pos);
        std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);
    }
    
    return "";
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

