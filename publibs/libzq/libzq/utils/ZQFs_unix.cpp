//
//  ZQFs_unix.cpp
//  libzq
//
//  Created by staff on 17/3/8.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//

#include "ZQFs.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

using namespace zq;

char fs::separator()
{
    return '/';
}

bool fs::is_exist(const std::string &path)
{
    return !::access(path.c_str(), F_OK);
}

bool fs::is_dir(const std::string &path, bool strict)
{
    // strip off any trailing separator because that will cause the stat function to fail
    std::string tmp = path;
    if (!tmp.empty() && fs::is_separator(tmp[path.size()-1]))
        tmp.erase(path.size()-1,1);
    
    struct ::stat st{};
    auto ok = strict ? !::lstat(tmp.c_str(), &st) : !::stat(tmp.c_str(), &st);
    return ok && S_ISDIR(st.st_mode);
}

bool fs::is_file(const std::string &path, bool strict)
{
    struct ::stat st{};
    auto ok = strict ? !::lstat(path.c_str(), &st) : !::stat(path.c_str(), &st);
    return ok && S_ISREG(st.st_mode);
}

bool fs::create(const std::string &dir, std::uint16_t mode, bool recursive)
{
    if (!mode)
        mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
    
    if (!fs::is_dir(dir))
    {
        if (recursive)
        {
            auto success = true;
            auto dirname = fs::dirname(dir);
            if (!dirname.empty())
                success = fs::create(dirname, mode, recursive);
            
            return !::mkdir(dir.c_str(), mode) && success ? true : false;
            
        }
        else
        {
            return !::mkdir(dir.c_str(), mode);
        }
    }
    else
    {
        return true;
    }
}

bool fs::remove(const std::string &path)
{
    if (fs::is_file(path))
    {
        return !::remove(path.c_str());
    }
    else
    {
        DIR *dir = opendir(path.c_str());
        dirent *cur = nullptr;
        
        if (!dir)
            return true;
        
        auto ok = true;
        auto sep = fs::separator();
        while ((cur = ::readdir(dir)))
        {
            std::string name(cur->d_name);
            if ((name == ".") || (name == ".."))
                continue;
            
            std::string full(*(path.end()-1) == sep ? path + name : path + sep + name);
            if (fs::is_dir(full))
                ok = fs::remove(full) && ok;
            else
                ok = !::remove(full.c_str()) && ok;
        }
        
        ::closedir(dir);
        
        if (ok)
            ok = !::rmdir(path.c_str());
        
        return ok;
    }
}

void fs::visit(const std::string &directory, std::function<void (const std::string &, bool &)> callback, bool recursive)
{
    DIR *dir = ::opendir(directory.c_str());
    dirent *cur = nullptr;
    
    if (!dir)
        return;
    
    auto sep = fs::separator();
    auto stop = false;
    
    while ((cur = ::readdir(dir)))
    {
        std::string name(cur->d_name);
        
        if ((name == ".") || (name == ".."))
            continue;
        
        std::string full(*(directory.end() - 1) == sep ? directory + name : directory + sep + name);
        
        callback(full, stop);
        if (stop)
            break;
        
        if (recursive && fs::is_dir(full))
            fs::visit(full, callback, recursive);
    }
    
    ::closedir(dir);
}

