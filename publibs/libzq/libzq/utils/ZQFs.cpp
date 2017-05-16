/***********************************************
* ZQFs.cpp
*
* @author: zyq
* @date: 17/3/8
* @Description:
*
***********************************************/

#include "ZQFs.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <algorithm>

using namespace zq;

bool fs::is_separator(char ch)
{
    if (ch == fs::separator())
    {
        return true;
    }
    
    return false;
}

off_t fs::file_size(const std::string &file)
{
    struct ::stat st{};
    return !::stat(file.c_str(), &st) ? st.st_size : 0;
}

std::string fs::dirname(const std::string &path)
{
    std::string dir = "";
    std::size_t index = path.find_last_of("/\\");
    if (index != std::string::npos)
    {
        dir = path.substr(0, index);
    }
    
    return dir;
}

std::string fs::filename(const std::string &path)
{
    std::size_t index = path.find_last_of("/\\");
    if (index != std::string::npos)
    {
        return path.substr(index+1);
    }
    
    return path;

}

std::string fs::extname(const std::string &path)
{
    std::string fname = fs::filename(path);
    std::string::size_type i = fname.find_last_of('.');
    if (i != 0 && i != std::string::npos)
        fname.erase(0, i);
    else
        fname.erase();
    
    std::transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
    
    return fname;
}

std::string fs::basename(const std::string &path)
{
    std::string fname = fs::filename(path);
    std::string::size_type i = fname.find_last_of('.');
    if (i != 0 && i != std::string::npos)
        fname.erase(i, fname.size()-i);
    
    return fname;
}

bool fs::rename(const std::string &path_old, const std::string &path_new)
{
    if (!fs::remove(path_new))
        return false;
    
    if (!fs::create(fs::dirname(path_new)))
        return false;
    
    return !::rename(path_old.c_str(), path_new.c_str());
}

bool fs::copy(const std::string &path_old, const std::string &path_new)
{
    if (fs::is_file(path_old))
    {
        auto folder = fs::dirname(path_new);
        if (folder.empty())
            return false;
        
        if (!fs::create(folder))
            return false;
        
        std::ifstream in(path_old, std::ios_base::binary);
        if (!in)
            return false;
        
        std::ofstream out(path_new, std::ios_base::binary);
        if (!out)
            return false;
        
        out << in.rdbuf();
        out.close();
        in.close();
    }
    else if (fs::is_dir(path_old, true))
    {
        if (!fs::create(path_new))
            return false;
        
        auto size = path_old.size();
        auto success = true;
        
        fs::visit(path_old, [size, &success, path_new] (const std::string &name, bool &stop) {
            auto sub = name.substr(size, name.size() - size);
            
            if (fs::is_file(name))
                success = fs::copy(name, path_new + sub);
            else
                success = fs::create(path_new + sub, 0, false);
            
            stop = !success;
        });
        
        return success;
    }
    
    return false;
}
