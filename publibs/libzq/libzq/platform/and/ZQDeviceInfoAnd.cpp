/***********************************************
* @author: zyq
* @date: 17/3/24
* @Description:
*
***********************************************/

#ifdef ANDROID
#include "ZQDeviceInfoAnd.h"
#include "log/ZQLogger.h"
#include "cocos2d.h"
#include "jni/JniHelper.h"

using namespace zq;

ZQDeviceInfoAnd* ZQDeviceInfoAnd::getInstance()
{
    static ZQDeviceInfoAnd instance;
    return &instance;
}

unsigned int ZQDeviceInfoAnd::memory_used()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "memory_used",
                                                 "()I"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    int ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

unsigned int ZQDeviceInfoAnd::memory_free()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "memory_free",
                                                 "()I"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    int ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

float ZQDeviceInfoAnd::cpu_usage()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "cpu_usage",
                                                 "()F"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    float ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

int ZQDeviceInfoAnd::version_cpp()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "version_cpp",
                                                 "()I"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    int ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

std::string ZQDeviceInfoAnd::version_short()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "version_short",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

std::string ZQDeviceInfoAnd::device_telecom()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "device_telecom",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

std::string ZQDeviceInfoAnd::device_hardware()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "device_hardware",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

std::string ZQDeviceInfoAnd::device_network()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "device_network",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;

}

std::string ZQDeviceInfoAnd::device_os_version()
{
    return "";
}

std::string ZQDeviceInfoAnd::bundle_id()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "bundle_id",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

std::string ZQDeviceInfoAnd::bundle_name()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "bundle_name",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

bool ZQDeviceInfoAnd::open_browser(const std::string &url)
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "open_browser",
                                                 "(Ljava/lang/String;)V"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return false;
    }
    
    jstring jstrInfo = methodInfo.env->NewStringUTF(url.c_str());
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jstrInfo);
    
    methodInfo.env->DeleteLocalRef(jstrInfo);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return true;
}

void ZQDeviceInfoAnd::quit_game()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "quit_game",
                                                 "()V"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

std::string ZQDeviceInfoAnd::browser_useragent()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "browser_useragent",
                                                 "()Ljava/lang/String;"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string ret(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

void ZQDeviceInfoAnd::vibrate()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "vibrate",
                                                 "()V"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void ZQDeviceInfoAnd::keep_awake(bool keep)
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "keep_awake",
                                                 "(Z)V"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, keep);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

bool ZQDeviceInfoAnd::keyboard_exist()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "keyboard_exist",
                                                 "()Z"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return false;
    }
    
    bool exist = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return exist;
}

void ZQDeviceInfoAnd::keyboard_close()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "keyboard_close",
                                                 "()V"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void ZQDeviceInfoAnd::clipboard(const std::string &text)
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PIDeviceInfoAnd", "clipboard",
                                                 "(Ljava/lang/String;)V"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    jstring jstrInfo = methodInfo.env->NewStringUTF(text.c_str());
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jstrInfo);
    
    methodInfo.env->DeleteLocalRef(jstrInfo);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

#endif
