//
//  ZQPlistManage.hpp
//  libzq
//
//  Created by staff on 16/11/11.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQPLISTMANAGE_HPP_
#define _ZQPLISTMANAGE_HPP_

#include "cocos2d.h"

namespace zq {

class ZQPlistManage
{
public:
    static ZQPlistManage* getInstance();
    
protected:
    ZQPlistManage() = default;
    virtual ~ZQPlistManage() = default;

public:
    /**
     *  Converts the contents of a file to a ValueMap.
     *  @param filename The filename of the file to gets content.
     *  @return ValueMap of the file contents.
     *  @note This method is used internally.
     */
    cocos2d::ValueMap getDictFromFile(const std::string &filename);
    
    
    /** Converts the contents of a file to a ValueMap.
     *  This method is used internally.
     */
    cocos2d::ValueMap getDictFromText(const std::string &text);
    
    
    /**
     *  Converts the contents of a file to a ValueVector.
     *  @param filename The filename of the file to gets content.
     *  @return ValueMap of the file contents.
     *  @note This method is used internally.
     */
    cocos2d::ValueVector getArrayFromFile(const std::string &filename);
    
    
    /** Converts the contents of a file to a ValueVector.
     *  This method is used internally.
     */
    cocos2d::ValueVector getArrayFromText(const std::string &text);
    
    /**
     *  Converts the contents of a file to a ValueVector.
     *  @param filename The filename of the file to gets content.
     *  @return ValueMap of the file contents.
     *  @note This method is used internally.
     */
    cocos2d::Value getValueFromFile(const std::string &filename);
    
    
    /** Converts the contents of a file to a Value.
     *  This method is used internally.
     */
    cocos2d::Value getValueFromText(const std::string &text);
    
};
    
}

#endif /* _ZQPLISTMANAGE_HPP_ */
