/***********************************************
* ZQDeviceInfo.h
*
* @author: zyq
* @date: 17/2/17
* @Description:
*
***********************************************/

#ifndef __ZQDEVICEINFOMAC_H__
#define __ZQDEVICEINFOMAC_H__

#include "ZQDeviceInfo.h"

namespace zq
{
    class ZQDeviceInfoMac : public ZQDeviceInfo
    {
    public:
        static ZQDeviceInfoMac* getInstance();
    
    protected:
        ZQDeviceInfoMac() = default;
        virtual ~ZQDeviceInfoMac() = default;
        
    public:
        virtual unsigned int memory_used();
        virtual unsigned int memory_free();
        
        virtual float cpu_usage();
        
        virtual int version_cpp();
        virtual std::string version_short();
        
        virtual std::string device_telecom() {return "";}
        virtual std::string device_hardware() {return "";}
        virtual std::string device_network() {return "";}

        virtual std::string bundle_id();
        virtual std::string bundle_name();
        
        virtual bool open_browser(const std::string &url);
        
        virtual void quit_game();
        
        virtual std::string browser_useragent();
        
        virtual void vibrate() {}
        
        virtual void keep_awake(bool keep) {}
        
        virtual bool keyboard_exist();
        virtual void keyboard_close();
        
        virtual void clipboard(const std::string &text);

    };
}


#endif /* defined(__ZQDEVICEINFOMAC_H__) */
