//
//  ZQFileManage.hpp
//  libzq
//
//  Created by staff on 16/11/4.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQFileManage_hpp_
#define _ZQFileManage_hpp_

#include <stdio.h>
#include "cocos2d.h"

namespace zq {
    
class ZQFileManage
{
public:
   static ZQFileManage* getInstance();
    
protected:
   ZQFileManage();
   virtual ~ZQFileManage();
   
   bool init();
   
public:
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
    void addSearchPath(const std::string & path, const bool front=false);
    
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
    
private:
    cocos2d::FileUtils* _fileUtils;
};
    
}
#endif /* _ZQFileManage_hpp_ */
