//
//  ZQJsonManage.hpp
//  libzq
//
//  Created by staff on 16/11/9.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQJSONMANAGE_HPP_
#define _ZQJSONMANAGE_HPP_

#include "cocos2d.h"

namespace zq
{
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
        const cocos2d::ValueMap& load_dict(const std::string &filename);
        
        
        /** Converts the contents of a file to a ValueMap.
         *  This method is used internally.
         */
        cocos2d::ValueMap text_dict(const std::string &text);
        
        
        /**
         *  Converts the contents of a file to a ValueVector.
         *  @param filename The filename of the file to gets content.
         *  @return ValueMap of the file contents.
         *  @note This method is used internally.
         */
        const cocos2d::ValueVector& load_array(const std::string &filename);
        
        
        /** Converts the contents of a file to a ValueVector.
         *  This method is used internally.
         */
        cocos2d::ValueVector text_array(const std::string &text);
        
        /**
         *  Converts the contents of a file to a ValueVector.
         *  @param filename The filename of the file to gets content.
         *  @return ValueMap of the file contents.
         *  @note This method is used internally.
         */
    public:
        bool exist(const std::string &filename);
        
        bool cache(const std::string &filename);
        
        void clear(const std::string &filename = "");
        
    protected:
        const cocos2d::Value& read_file(const std::string &filename);
        
        
        /** Converts the contents of a file to a Value.
         *  This method is used internally.
         */
        cocos2d::Value read_text(const std::string &text);
        
    private:
        cocos2d::ValueMap _cache;

    };
}

#endif /* _ZQJSONMANAGE_HPP_ */
