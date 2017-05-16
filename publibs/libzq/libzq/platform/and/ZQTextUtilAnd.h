#pragma once

#ifdef ANDROID

#include "draw/ZQTextUtil.h"

namespace zq
{
    class ZQTextUtilAnd : public ZQTextUtil
    {
    public:
        static ZQTextUtilAnd* getInstance();
        
    protected:
        ZQTextUtilAnd() = default;
        virtual ~ZQTextUtilAnd() = default;
        
    public:
        virtual std::string standardFontName();
        
        virtual cocos2d::Size sizeByFont(const std::string &text, const std::string &font_name, float font_size);
        
        virtual float widthByFont(const std::string &text, const std::string &font_name, float font_size);
        
        virtual float heightByFont(const std::string &text, const std::string &font_name, float font_size);
        
        virtual bool renderByArray(cocos2d::Sprite *sprite, const cocos2d::ValueVector &lines, int width, int height);
        virtual bool renderByString(cocos2d::Sprite *sprite, const std::string &info, int width, int height);
    };
}

#endif
