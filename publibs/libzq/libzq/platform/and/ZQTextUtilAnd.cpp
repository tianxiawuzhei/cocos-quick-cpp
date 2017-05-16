#if ANDROID

#include "ZQTextUtilAnd.h"

#include <vector>
#include "jni/JniHelper.h"
#include "log/ZQLogger.h"

using namespace zq;

namespace
{
    struct TextUtilInfo
    {
        int finalWide;
        int finalHigh;
        unsigned char *data;
    };
    
    static TextUtilInfo shared_text_util_info;
    
}

ZQTextUtilAnd* ZQTextUtilAnd::getInstance()
{
    static ZQTextUtilAnd instance;
    return &instance;
}

std::string ZQTextUtilAnd::standardFontName()
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PITextUtilAnd", "standardFontName",
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

cocos2d::Size ZQTextUtilAnd::sizeByFont(const std::string &text, const std::string &font_name, float font_size)
{
    return cocos2d::Size(ZQTextUtilAnd::widthByFont(text, font_name, font_size),
                         ZQTextUtilAnd::heightByFont(text, font_name, font_size));
}

float ZQTextUtilAnd::widthByFont(const std::string &text, const std::string &font_name, float font_size)
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PITextUtilAnd", "widthByFont",
                                                 "(Ljava/lang/String;Ljava/lang/String;F)F"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    jstring jstrText = methodInfo.env->NewStringUTF(text.c_str());
    jstring jstrFont = methodInfo.env->NewStringUTF(font_name.c_str());
    
    float ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID, jstrText, jstrFont, font_size);
    
    methodInfo.env->DeleteLocalRef(jstrText);
    methodInfo.env->DeleteLocalRef(jstrFont);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

float ZQTextUtilAnd::heightByFont(const std::string &text, const std::string &font_name, float font_size)
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PITextUtilAnd", "heightByFont",
                                                 "(Ljava/lang/String;Ljava/lang/String;F)F"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    jstring jstrText = methodInfo.env->NewStringUTF(text.c_str());
    jstring jstrFont = methodInfo.env->NewStringUTF(font_name.c_str());
    
    float ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID, jstrText, jstrFont, font_size);
    
    methodInfo.env->DeleteLocalRef(jstrText);
    methodInfo.env->DeleteLocalRef(jstrFont);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return ret;
}

bool ZQTextUtilAnd::renderByArray(cocos2d::Sprite *sprite, const cocos2d::ValueVector &lines, int width, int height)
{
    throw "using renderByString in And";
}

bool ZQTextUtilAnd::renderByString(cocos2d::Sprite *sprite, const std::string &info, int width, int height)
{
    cocos2d::JniMethodInfo methodInfo;
    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/pinidea/shell/PITextUtilAnd", "render",
                                                 "(Ljava/lang/String;IIZ)Z"))
    {
        ZQLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return false;
    }
    
    jstring jstrInfo = methodInfo.env->NewStringUTF(info.c_str());
    
    bool pot = !cocos2d::Configuration::getInstance()->supportsNPOT();
    bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, jstrInfo, width, height, pot);
    
    methodInfo.env->DeleteLocalRef(jstrInfo);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    if (!ret)
        return ret;
    
    // 创建纹理
    auto finalWide = shared_text_util_info.finalWide;
    auto finalHigh = shared_text_util_info.finalHigh;
    auto length    = finalWide * finalHigh * 4;
    auto data      = shared_text_util_info.data;
    auto texture   = new cocos2d::Texture2D;
    
    texture->initWithData(data, length, cocos2d::Texture2D::PixelFormat::RGBA8888, finalWide, finalHigh, cocos2d::Size(width, height));
    sprite->setTexture(texture);
    
    // 安卓切换前后台需要重建纹理
#if CC_ENABLE_CACHE_TEXTURE_DATA
    cocos2d::VolatileTextureMgr::addDataTexture(texture, data, length, cocos2d::Texture2D::PixelFormat::RGBA8888, cocos2d::Size(finalWide, finalHigh));
#endif
    
    // 清理
    texture->release();
    
    return ret;
}


// ------------------------------------------------------------------
// java渲染成功后，回调C++传回图片数据
extern "C"
{
    JNIEXPORT void JNICALL Java_com_pinidea_shell_PITextUtilAnd_nativeRender(JNIEnv *env, jobject thiz, int finalWide, int finalHigh, int width, int height, jbyteArray pixels)
    {
        unsigned int length = finalWide * finalHigh * 4;
        unsigned char *data = new unsigned char[length];  // VolatileTexture在销毁时会释放data
        memset(data, 0, length);
        
        env->GetByteArrayRegion(pixels, 0, length, (jbyte*)data);
        
        shared_text_util_info.finalWide = finalWide;
        shared_text_util_info.finalHigh = finalHigh;
        shared_text_util_info.data      = data;
    }
}

#endif
