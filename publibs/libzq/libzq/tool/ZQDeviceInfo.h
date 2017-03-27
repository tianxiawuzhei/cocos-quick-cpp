/***********************************************
* ZQDeviceInfo.h
*
* @author: zyq
* @date: 17/2/17
* @Description:
*
***********************************************/

#ifndef __ZQDEVICEINFO_H__
#define __ZQDEVICEINFO_H__

#include <string>
namespace zq
{
    class ZQDeviceInfo
    {
    public:
        static ZQDeviceInfo* getInstance();
    
    protected:
        ZQDeviceInfo() = default;
        virtual ~ZQDeviceInfo() = default;
        
    public:
        virtual unsigned int memory_all();
        virtual unsigned int memory_used() = 0;
        virtual unsigned int memory_free() = 0;
        
        virtual bool os_is_mac();
        virtual bool os_is_ios();
        virtual bool os_is_android();
        virtual bool os_is_mobile();
        
        virtual int cpu_core();
        virtual float cpu_usage() = 0;
        
        virtual int version_cpp() = 0;
        virtual std::string version_short() = 0;
        
        virtual std::string device_uuid();
        virtual std::string device_telecom()  = 0;
        virtual std::string device_hardware() = 0;
        virtual std::string device_network()  = 0;
        virtual std::string device_os_version() = 0;

        virtual std::string bundle_id() = 0;
        virtual std::string bundle_name() = 0;
        
        virtual std::string uuid();
        
        virtual bool open_browser(const std::string &url) = 0;
        
        virtual void quit_game() = 0;
        
        virtual std::string browser_useragent() = 0;
        
        virtual void vibrate() = 0;
        
        virtual void keep_awake(bool keep) = 0;
        
        virtual bool keyboard_exist() = 0;
        virtual void keyboard_close() = 0;
        
        virtual void clipboard(const std::string &text) = 0;
        

        
    };
}



#endif /* defined(__ZQDEVICEINFO_H__) */
