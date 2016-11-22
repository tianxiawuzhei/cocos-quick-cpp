//
//  ZQJsonManage.hpp
//  libzq
//
//  Created by staff on 16/11/9.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQJSONMANAGE_HPP_
#define _ZQJSONMANAGE_HPP_

#include <stdio.h>
#include "cocos2d.h"

namespace zq {
    
class ZQJsonManage
{
public:
    static ZQJsonManage* getInstance();

protected:
    ZQJsonManage() = default;
    virtual ~ZQJsonManage() = default;

public:
    /**
     *  Converts the contents of a file to a ValueMap.
     *  @param filename The filename of the file to gets content.
     *  @return ValueMap of the file contents.
     *  @note This method is used internally.
     */
    virtual cocos2d::ValueMap getDictFromFile(const std::string& filename);
    
    
    /** Converts the contents of a file to a ValueMap.
     *  This method is used internally.
     */
    virtual cocos2d::ValueMap getDictFromText(const std::string& text);
    
    
    /**
     *  Converts the contents of a file to a ValueVector.
     *  @param filename The filename of the file to gets content.
     *  @return ValueMap of the file contents.
     *  @note This method is used internally.
     */
    virtual cocos2d::ValueVector getArrayFromFile(const std::string& filename);
    
    
    /** Converts the contents of a file to a ValueVector.
     *  This method is used internally.
     */
    virtual cocos2d::ValueVector getArrayFromText(const std::string& text);
    
    /**
     *  Converts the contents of a file to a ValueVector.
     *  @param filename The filename of the file to gets content.
     *  @return ValueMap of the file contents.
     *  @note This method is used internally.
     */
    virtual cocos2d::Value getValueFromFile(const std::string& filename);
    
    
    /** Converts the contents of a file to a Value.
     *  This method is used internally.
     */
    virtual cocos2d::Value getValueFromText(const std::string& text);

};
    
    
}

#endif /* _ZQJSONMANAGE_HPP_ */
