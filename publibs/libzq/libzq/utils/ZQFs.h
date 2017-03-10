/***********************************************
* ZQFs.h
*
* @author: zyq
* @date: 17/3/8
* @Description:
*
***********************************************/

#ifndef __ZQFS_H__
#define __ZQFS_H__

#include <string>
#include <functional>

namespace zq
{
    class fs
    {
    public:
        /*
            
        */
        static char separator();
        
        static bool is_separator(char ch);
    public:
        static bool is_exist(const std::string &path);
        
        static bool is_dir(const std::string &path, bool strict = false);
        
        static bool is_file(const std::string &path, bool strict = false);
        
        static off_t file_size(const std::string &file);
       
    public:
        static std::string dirname(const std::string &path);
        static std::string filename(const std::string &path);
        static std::string extname(const std::string &path);
        static std::string basename(const std::string &path);
        
    public:
        static bool create(const std::string &dir, std::uint16_t mode = 0, bool recursive = true);
        
        static bool rename(const std::string &path_old, const std::string &path_new);
        
        static bool remove(const std::string &path);
        
        static bool copy(const std::string &path_old, const std::string &path_new);
        
    public:
        static void visit(const std::string &directory,
                          std::function<void (const std::string &path, bool &stop)> callback,
                          bool recursive = true);
        
    };
}



#endif /* defined(__ZQFS_H__) */
