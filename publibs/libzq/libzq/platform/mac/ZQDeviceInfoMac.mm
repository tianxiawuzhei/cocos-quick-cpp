/***********************************************
* ZQDeviceInfo.cpp
*
* @author: zyq
* @date: 17/2/17
* @Description:
*
***********************************************/

#include "ZQDeviceInfoMac.h"
#include <mach/mach.h>
#include <mach/message.h>  // for mach_msg_type_number_t
#include <mach/kern_return.h>  // for kern_return_t
#include <mach/task_info.h>
#include <AppKit/AppKit.h>
#include "cocos2d.h"

using namespace zq;

ZQDeviceInfoMac* ZQDeviceInfoMac::getInstance()
{
    static ZQDeviceInfoMac instance;
    return &instance;
}

unsigned int ZQDeviceInfoMac::memory_used()
{
    kern_return_t error;
    mach_msg_type_number_t outCount;
    mach_task_basic_info_data_t taskinfo;
    
    taskinfo.virtual_size = 0;
    outCount = MACH_TASK_BASIC_INFO_COUNT;
    error = task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&taskinfo, &outCount);
    if (error == KERN_SUCCESS) {
        return (unsigned int)taskinfo.resident_size;
    } else {
        return 0;
    }
}

unsigned int ZQDeviceInfoMac::memory_free()
{
    mach_port_t            host_port = mach_host_self();
    mach_msg_type_number_t host_size = sizeof(vm_statistics_data_t) / sizeof(integer_t);
    
    vm_size_t pagesize = 0;
    vm_statistics_data_t vm_stat = {0};
    
    host_page_size(host_port, &pagesize);
    host_statistics(host_port, HOST_VM_INFO, (host_info_t)&vm_stat, &host_size);
    
    return (unsigned int)(vm_stat.free_count * pagesize);
}

float ZQDeviceInfoMac::cpu_usage()
{
    kern_return_t kr;
    task_info_data_t tinfo;
    mach_msg_type_number_t task_info_count;
    
    task_info_count = TASK_INFO_MAX;
    kr = task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)tinfo, &task_info_count);
    if (kr != KERN_SUCCESS) {
        return -1;
    }
    
    task_basic_info_t      basic_info;
    thread_array_t         thread_list;
    mach_msg_type_number_t thread_count;
    
    thread_info_data_t     thinfo;
    mach_msg_type_number_t thread_info_count;
    
    thread_basic_info_t basic_info_th;
    uint32_t stat_thread = 0; // Mach threads
    
    basic_info = (task_basic_info_t)tinfo;
    
    // get threads in the task
    kr = task_threads(mach_task_self(), &thread_list, &thread_count);
    if (kr != KERN_SUCCESS) {
        return -1;
    }
    if (thread_count > 0)
        stat_thread += thread_count;
    
    long tot_sec = 0;
    long tot_usec = 0;
    float tot_cpu = 0;
    int j;
    
    for (j = 0; j < thread_count; j++)
    {
        thread_info_count = THREAD_INFO_MAX;
        kr = thread_info(thread_list[j], THREAD_BASIC_INFO,
                         (thread_info_t)thinfo, &thread_info_count);
        if (kr != KERN_SUCCESS) {
            return -1;
        }
        
        basic_info_th = (thread_basic_info_t)thinfo;
        
        if (!(basic_info_th->flags & TH_FLAGS_IDLE)) {
            tot_sec = tot_sec + basic_info_th->user_time.seconds + basic_info_th->system_time.seconds;
            tot_usec = tot_usec + basic_info_th->system_time.microseconds + basic_info_th->system_time.microseconds;
            tot_cpu = tot_cpu + basic_info_th->cpu_usage / (float)TH_USAGE_SCALE * 100.0;
        }
        
    } // for each thread
    
    kr = vm_deallocate(mach_task_self(), (vm_offset_t)thread_list, thread_count * sizeof(thread_t));
    if (kr == KERN_SUCCESS)
    {
        return tot_cpu;
    }
    else
    {
        return -1;
    }
}

int ZQDeviceInfoMac::version_cpp()
{
    NSString* version = [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleVersionKey];
    if (version) {
        return [version intValue];
    }
    return -1;
}

std::string ZQDeviceInfoMac::version_short()
{
    NSString* version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    if (version) {
        return [version UTF8String];
    }
    return "";
}

std::string ZQDeviceInfoMac::bundle_id()
{
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"] UTF8String];
}

std::string ZQDeviceInfoMac::bundle_name()
{
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"] UTF8String];
}

bool ZQDeviceInfoMac::open_browser(const std::string &url)
{
    NSString* msg = [NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding];
    NSURL* nsUrl = [NSURL URLWithString:msg];
    return [[NSWorkspace sharedWorkspace] openURL:nsUrl];
}

void ZQDeviceInfoMac::quit_game()
{
    exit(EXIT_SUCCESS);
}

std::string ZQDeviceInfoMac::browser_useragent()
{
    return "";
}

bool ZQDeviceInfoMac::keyboard_exist()
{
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    NSWindow* window = glview->getCocoaWindow();
    
    if ([[window firstResponder] isKindOfClass:[NSTextView class]]
        || [[window firstResponder] isKindOfClass:[NSTextField class]])
    {
        return true;
    }
    
    return false;
}

void ZQDeviceInfoMac::keyboard_close()
{
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    NSWindow* window = glview->getCocoaWindow();
    [window makeFirstResponder:nil];
}

void ZQDeviceInfoMac::clipboard(const std::string &text)
{
    [[NSPasteboard generalPasteboard] setString:[NSString stringWithUTF8String:text.c_str()] forType:NSPasteboardTypeString];
}
