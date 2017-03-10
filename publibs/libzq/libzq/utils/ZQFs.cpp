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
        fname.erase(0, i+1);
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
