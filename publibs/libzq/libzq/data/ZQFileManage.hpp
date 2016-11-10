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
   
   static void destroyInstance();
   
   ZQFileManage();
   ~ZQFileManage();
   
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
    

    
protected:
    static ZQFileManage* s_instanceZQFileManage;
   
private:
    cocos2d::FileUtils* _fileUtils;
};
    
}
#endif /* _ZQFileManage_hpp_ */
