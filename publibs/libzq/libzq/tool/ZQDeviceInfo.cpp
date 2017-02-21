/***********************************************
* ZQDeviceInfo.cpp
*
* @author: zyq
* @date: 17/2/17
* @Description:
*
***********************************************/

#include "ZQDeviceInfo.h"
#include <thread>
#include "platform/CCPlatformConfig.h"

using namespace zq;

ZQDeviceInfo* ZQDeviceInfo::getInstance()
{
    return nullptr;
}

unsigned int ZQDeviceInfo::memory_all()
{
    return this->memory_used() + this->memory_free();
}

bool ZQDeviceInfo::os_is_mac()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    return true;
#else
    return false;
#endif
}

bool ZQDeviceInfo::os_is_ios()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return true;
#else
    return false;
#endif
}

bool ZQDeviceInfo::os_is_android()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return true;
#else
    return false;
#endif
}

int ZQDeviceInfo::cpu_core()
{
    return std::thread::hardware_concurrency();
}

std::string ZQDeviceInfo::device_uuid()
{
    return "";
}

std::string ZQDeviceInfo::uuid()
{
    return "";
}

