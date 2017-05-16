/***********************************************
* ZQTextUtil.cpp
*
* @author: zyq
* @date: 17/1/5
* @Description:
*
***********************************************/

#include "ZQTextUtil.h"
#include "platform/mac/ZQTextUtilMac.h"
#include "platform/ios/ZQTextUtilIOS.h"
#include "platform/and/ZQTextUtilAnd.h"

using namespace zq;

ZQTextUtil* ZQTextUtil::getInstance()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return ZQTextUtilIOS::getInstance();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    return ZQTextUtilMac::getInstance();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return ZQTextUtilAnd::getInstance();
#endif
}
