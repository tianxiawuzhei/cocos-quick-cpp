//
//  ZQFileManage.hpp
//  libzq
//
//  Created by staff on 16/11/4.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQFILEMANAGE_H_
#define _ZQFILEMANAGE_H_

#include <stdio.h>
#include <string>
#include "cocos2d.h"

namespace zq
{
    
    class ZQFileManage
    {
    public:
        static ZQFileManage* getInstance();

    protected:
        ZQFileManage();
        virtual ~ZQFileManage();

    public:
        std::string load_file(const std::string &filename);
        std::string load_disk(const std::string &filename);
        
        std::string file_string(const std::string &filename);
        cocos2d::Data file_data(const std::string &filename);
        
        /**
        *  Gets string from a file.
        */
        virtual std::string getStringFromFile(const std::string& filename);

        /**
        *  Creates binary data from a file.
        *  @return A data object.
        */
        virtual cocos2d::Data getDataFromFile(const std::string& filename);

        /**
        *  Checks whether a file exists.
        *
        *  @note If a relative path was passed in, it will be inserted a default root path at the beginning.
        *  @param filename The path of the file, it could be a relative or absolute path.
        *  @return True if the file exists, false if not.
        */
        virtual bool isFileExist(const std::string& filename) const;

        /**
        * Add search path.
        *
        * @since v2.1
        */
        void addSearchPath(const std::string &path, const bool front=false);

        /**
        *  Gets the writable path.
        *  @return  The path that can be write/read a file in
        */
        virtual std::string getWritablePath();

        /**
        *  Gets filename extension is a suffix (separated from the base filename by a dot) in lower case.
        *  Examples of filename extensions are .png, .jpeg, .exe, .dmg and .txt.
        *  @param filePath The path of the file, it could be a relative or absolute path.
        *  @return suffix for filename in lower case or empty if a dot not found.
        */
        virtual std::string getFileExtension(const std::string& filePath) const;

        /**
        *  Creates a directory.
        *
        *  @param dirPath The path of the directory, it must be an absolute path.
        *  @return True if the directory have been created successfully, false if not.
        */
        virtual bool createDirectory(const std::string& dirPath);

        /**
        *  Removes a directory.
        *
        *  @param dirPath  The full path of the directory, it must be an absolute path.
        *  @return True if the directory have been removed successfully, false if not.
        */
        virtual bool removeDirectory(const std::string& dirPath);

        /**
        *  Removes a file.
        *
        *  @param filepath The full path of the file, it must be an absolute path.
        *  @return True if the file have been removed successfully, false if not.
        */
        virtual bool removeFile(const std::string &filepath);

        /**
        *  Renames a file under the given directory.
        *
        *  @param oldfullpath  The current fullpath of the file. Includes path and name.
        *  @param newfullpath  The new fullpath of the file. Includes path and name.
        *  @return True if the file have been renamed successfully, false if not.
        */
        virtual bool renameFile(const std::string &oldfullpath, const std::string &newfullpath);

        /**
        *  Retrieve the file size.
        *
        *  @note If a relative path was passed in, it will be inserted a default root path at the beginning.
        *  @param filepath The path of the file, it could be a relative or absolute path.
        *  @return The file size.
        */
        virtual long getFileSize(const std::string &filepath);

    public:
        void prepare();
        
    public:
        static std::string set_url_for_res(const std::string &url);
        static std::string set_url_for_code(const std::string &url);
        
        static std::string url_for_res();
        static std::string url_for_code();
        static std::string url_for_file(const std::string &filename);
        
    public:
        static bool dir_exist(const std::string &path, bool create = false);
        static bool file_exist(const std::string &path, const std::string &md5 = "", bool remove_if_fail = false);
        static uint32_t file_size(const std::string &path);
        
        static bool create_folder(const std::string &path);
        static bool rebuild_folder(const std::string &path);
        
        static bool remove_file(const std::string &path);
        static bool rename_file(const std::string &old_path, const std::string &new_path);
        
    public:
        static bool write_file(const std::string &path, const uint8_t *data, uint32_t size);
        static bool append_file(const std::string &path, const uint8_t *data, uint32_t size);
        
    public:
        static std::string dirname_of_path(const std::string &path, bool with_slash = false);
        static std::string extname_of_path(const std::string &path, bool with_dot = true);
        static std::string basename_of_path(const std::string &path, bool with_ext = true);
        
    public:
        static std::string log_path();
        static std::string temp_path();
        static std::string cache_path();
        
    private:
        static std::string _url_res;
        static std::string _url_code;

    private:
        cocos2d::FileUtils* _fileUtils;
    
    };
    
}
#endif /* _ZQFILEMANAGE_H_ */
