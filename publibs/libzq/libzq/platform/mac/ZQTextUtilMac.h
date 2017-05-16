/***********************************************
* ZQTextUtilMac.h
*
* @author: zyq
* @date: 17/1/5
* @Description:
*
***********************************************/

#ifndef __ZQTEXTUTILMAC_H__
#define __ZQTEXTUTILMAC_H__

#include "draw/ZQTextUtil.h"

namespace zq
{
    class ZQTextUtilMac : public ZQTextUtil
    {
    public:
        static ZQTextUtilMac* getInstance();
        
    protected:
        ZQTextUtilMac() = default;
        virtual ~ZQTextUtilMac() = default;
        
    public:
        virtual std::string standardFontName();
        
        virtual cocos2d::Size sizeByFont(const std::string &text, const std::string &font_name, float font_size);
        
        virtual bool renderByArray(cocos2d::Sprite *sprite, const cocos2d::ValueVector &lines, int width, int height);
        virtual bool renderByString(cocos2d::Sprite *sprite, const std::string &info, int width, int height);
        
    };
}


#endif /* defined(__ZQTEXTUTILMAC_H__) */
