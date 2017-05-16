/***********************************************
* ZQTextUtil.h
*
* @author: zyq
* @date: 17/1/5
* @Description:
*
***********************************************/

#ifndef __ZQTEXTUTIL_H__
#define __ZQTEXTUTIL_H__

#include "cocos2d.h"

namespace zq
{

class ZQTextUtil
{
public:
    static ZQTextUtil* getInstance();
    
protected:
    ZQTextUtil() = default;
    virtual ~ZQTextUtil() = default;
    
public:
    virtual std::string standardFontName() = 0;
    
    virtual cocos2d::Size sizeByFont(const std::string &text, const std::string &font_name, float font_size) = 0;
    
    virtual float widthByFont(const std::string &text, const std::string &font_name, float font_size) = 0;
    
    virtual float heightByFont(const std::string &text, const std::string &font_name, float font_size) = 0;
    
    virtual bool renderByArray(cocos2d::Sprite *sprite, const cocos2d::ValueVector &lines, int width, int height) = 0;
    virtual bool renderByString(cocos2d::Sprite *sprite, const std::string &info, int width, int height) = 0;
};
    
}


#endif /* defined(__ZQTEXTUTIL_H__) */
