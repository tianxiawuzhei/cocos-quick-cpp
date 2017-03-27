/***********************************************
* ZQDeviceInfoIOS.cpp
*
* @author: zyq
* @date: 17/3/24
* @Description:
*
***********************************************/
#include "ZQDeviceInfoIOS.h"
#include "cocos2d.h"
#include <mach/mach.h>
#include <mach/message.h>  // for mach_msg_type_number_t
#include <mach/kern_return.h>  // for kern_return_t
#include <mach/task_info.h>
#include <cstdlib>

#import <UIKit/UIKit.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#import <AudioToolbox/AudioToolbox.h>
#import "UIDeviceHardware.h"
#import "Reachability.h"

using namespace zq;

ZQDeviceInfoIOS* ZQDeviceInfoIOS::getInstance()
{
    static ZQDeviceInfoIOS instance;
    return &instance;
}

unsigned int ZQDeviceInfoIOS::memory_used()
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

unsigned int ZQDeviceInfoIOS::memory_free()
{
    mach_port_t            host_port = mach_host_self();
    mach_msg_type_number_t host_size = sizeof(vm_statistics_data_t) / sizeof(integer_t);
    
    vm_size_t pagesize = 0;
    vm_statistics_data_t vm_stat = {0};
    
    host_page_size(host_port, &pagesize);
    host_statistics(host_port, HOST_VM_INFO, (host_info_t)&vm_stat, &host_size);
    
    return (unsigned int)(vm_stat.free_count * pagesize);
}

float ZQDeviceInfoIOS::cpu_usage()
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

int ZQDeviceInfoIOS::version_cpp()
{
    return [[[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString*)kCFBundleVersionKey] intValue];
}

std::string ZQDeviceInfoIOS::version_short()
{
    return [[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"] UTF8String];
}

std::string ZQDeviceInfoIOS::device_telecom()
{
    CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
    CTCarrier           *carrier = [info subscriberCellularProvider];
    
    std::string telecom(carrier && [carrier carrierName] ? [[carrier carrierName] UTF8String] : "");
    
    [info release];
    
    return telecom;
}

std::string ZQDeviceInfoIOS::device_hardware()
{
    return [[UIDeviceHardware platformString] UTF8String];
}

std::string ZQDeviceInfoIOS::device_network()
{
    NetworkStatus status = [[[Reachability reachabilityForInternetConnection] autorelease] currentReachabilityStatus];
    if (status == ReachableViaWiFi)
    {
        return "WiFi";
    }
    
    if ([[[UIDevice currentDevice] systemVersion] intValue] >= 7)
    {
        CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
        static NSDictionary    *map  = [[NSDictionary alloc] initWithObjectsAndKeys:
                                        @"2G", CTRadioAccessTechnologyGPRS,
                                        @"2G", CTRadioAccessTechnologyEdge,
                                        
                                        @"3G", CTRadioAccessTechnologyWCDMA,
                                        @"3G", CTRadioAccessTechnologyHSDPA,
                                        @"3G", CTRadioAccessTechnologyHSUPA,
                                        @"3G", CTRadioAccessTechnologyCDMA1x,
                                        @"3G", CTRadioAccessTechnologyCDMAEVDORev0,
                                        @"3G", CTRadioAccessTechnologyCDMAEVDORevA,
                                        @"3G", CTRadioAccessTechnologyCDMAEVDORevB,
                                        @"3G", CTRadioAccessTechnologyeHRPD,
                                        
                                        @"4G", CTRadioAccessTechnologyLTE,
                                        nil];
        
        NSString *key = info.currentRadioAccessTechnology;
        NSString *val = key ? [map objectForKey:key] : @"Unknown";
        
        [info release];
        
        return [val UTF8String];
    }
    
    return "Unknown";
}

std::string ZQDeviceInfoIOS::device_os_version()
{
    return [[[UIDevice currentDevice] systemVersion] UTF8String];
}

std::string ZQDeviceInfoIOS::bundle_id()
{
    return [[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleIdentifier"] UTF8String];
}

std::string ZQDeviceInfoIOS::bundle_name()
{
    return [[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"] UTF8String];
}

bool ZQDeviceInfoIOS::open_browser(const std::string &url)
{
    return [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithUTF8String:url.c_str()]]];
}

void ZQDeviceInfoIOS::quit_game()
{
    std::exit(EXIT_SUCCESS);
}

std::string ZQDeviceInfoIOS::browser_useragent()
{
    static std::string agent;
    
    if (agent.empty())
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            UIWebView *web = [[UIWebView alloc] initWithFrame:CGRectZero];
            NSString  *val = [web stringByEvaluatingJavaScriptFromString:@"navigator.userAgent"];
            
            agent = val ? [val UTF8String] : "";
            
            [web release];
        });
    }
    
    return agent;
}

void ZQDeviceInfoIOS::vibrate()
{
    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
}

void ZQDeviceInfoIOS::keep_awake(bool keep)
{
    [[UIApplication sharedApplication] setIdleTimerDisabled:keep ? YES : NO];
}

bool ZQDeviceInfoIOS::keyboard_exist()
{
    UIView *view = (UIView*)cocos2d::Director::getInstance()->getOpenGLView()->getEAGLView();
    NSArray *subviews = view.subviews;
    
    for (UIView* view in subviews)
    {
        if([view isKindOfClass:[UITextView class]] ||
           [view isKindOfClass:[UITextField class]])
        {
            if ([view isFirstResponder])
            {
                return true;
            }
        }
    }
    
    return false;
}

void ZQDeviceInfoIOS::keyboard_close()
{
    UIView *view = (UIView*)cocos2d::Director::getInstance()->getOpenGLView()->getEAGLView();
    NSArray *subviews = view.subviews;
    
    for (UIView* view in subviews)
    {
        if([view isKindOfClass:[UITextView class]] ||
           [view isKindOfClass:[UITextField class]])
        {
            if ([view isFirstResponder])
            {
                [view resignFirstResponder];
            }
        }
    }
}

void ZQDeviceInfoIOS::clipboard(const std::string &text)
{
    UIPasteboard *pb = [UIPasteboard generalPasteboard];
    [pb setString:[NSString stringWithUTF8String:text.c_str()]];
}
