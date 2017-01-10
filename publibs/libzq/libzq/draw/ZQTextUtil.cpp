/***********************************************
* ZQTextUtil.cpp
*
* @author: zyq
* @date: 17/1/5
* @Description:
*
***********************************************/

#include "ZQTextUtil.h"
#include "ZQTextUtilMac.h"

using namespace zq;

ZQTextUtil* ZQTextUtil::getInstance()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return ZQTextUtilMac::getInstance();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    return ZQTextUtilMac::getInstance();
#endif
}

float ZQTextUtil::widthByFont(const std::string &text, const std::string &font_name, float font_size)
{
    return this->sizeByFont(text, font_name, font_size).width;
}

float ZQTextUtil::heigthByFont(const std::string &text, const std::string &font_name, float font_size)
{
    return this->sizeByFont(text, font_name, font_size).height;
}
