//
//  ZQTextBoxMac.cpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//
#ifdef ANDROID

#include "ZQTextAreaAnd.h"
#include "jni/JniHelper.h"
#include "ui/CocosGUI.h"

using namespace zq;

// Cache
static std::map<jobject, ZQTextAreaAnd*> g_textarea;

ZQTextAreaAnd::ZQTextAreaAnd()
: _view(nullptr)
, _info(nullptr)
{
    auto env = cocos2d::JniHelper::getEnv();
    auto loc = env->FindClass("com/pinidea/shell/PITextAreaAnd");
    auto cls = (jclass)env->NewGlobalRef(loc);
    auto beg = env->GetMethodID(cls, "<init>", "()V");
    auto tmp = env->NewObject(cls, beg);
    auto obj = env->NewGlobalRef(tmp);
    
    this->_temp = tmp;
    this->_view = obj;
    this->_info = cls;
    
    g_textarea[tmp] = this;
    
    env->DeleteLocalRef(tmp);
    env->DeleteLocalRef(loc);
}

ZQTextAreaAnd::~ZQTextAreaAnd()
{
    auto env = cocos2d::JniHelper::getEnv();
    env->DeleteGlobalRef(this->_view);
    env->DeleteGlobalRef(this->_info);
    
    auto it = g_textarea.find(this->_temp);
    if (it != g_textarea.end())
        g_textarea.erase(it);
}

ZQTextAreaAnd* ZQTextAreaAnd::create()
{
    auto view = new ZQTextAreaAnd();
    view->autorelease();
    return view;
}

void ZQTextAreaAnd::setFont(const std::string &font_name, float font_size)
{
    ZQTextArea::setFont(font_name, font_size);
    auto font = SizeApplyAffineTransform(cocos2d::Size(0, font_size), this->getNodeToWorldAffineTransform()).height;
    
    auto env = cocos2d::JniHelper::getEnv();
    
    auto mid = env->GetMethodID(this->_info, "setFontSize", "(F)V");
    env->CallVoidMethod(this->_view, mid, font);
}

void ZQTextAreaAnd::setString(const std::string &text)
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setString", "(Ljava/lang/String;)V");
    
    jstring str = env->NewStringUTF(text.c_str());
    
    env->CallVoidMethod(this->_view, mid, str);
    
    env->DeleteLocalRef(str);
}

void ZQTextAreaAnd::setFontColor(const cocos2d::Color3B &color)
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setFontColor", "(III)V");
    
    env->CallVoidMethod(this->_view, mid, color.r, color.g, color.b);
}

void ZQTextAreaAnd::setPlaceholderFont(const std::string &font_name, float font_size)
{
    ZQTextArea::setPlaceholderFont(font_name, font_size);
}

void ZQTextAreaAnd::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
   
}

void ZQTextAreaAnd::setPlaceHolder(const std::string &text)
{
    
}

void ZQTextAreaAnd::setMaxLength(int length)
{
    ZQTextArea::setMaxLength(length);
}

void ZQTextAreaAnd::setAlignmentLeft()
{
    
}

void ZQTextAreaAnd::setAlignmentCenter()
{
    
}

void ZQTextAreaAnd::setAlignmentRight()
{
    
}

void ZQTextAreaAnd::focus()
{
    
}

void ZQTextAreaAnd::update()
{
    if (!this->isRunning())
        return;
    
    auto ratio = 1.0;
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    auto font  = SizeApplyAffineTransform(cocos2d::Size(0, this->_fontSize), this->getNodeToWorldAffineTransform()).height;
    
    auto env = cocos2d::JniHelper::getEnv();
    
    auto mid = env->GetMethodID(this->_info, "setFontSize", "(F)V");
    env->CallVoidMethod(this->_view, mid, font);
    
    mid = env->GetMethodID(this->_info, "update", "(FFFF)V");
    env->CallVoidMethod(this->_view, mid, (float)(rect.origin.x / ratio), (float)(rect.origin.y / ratio), (float)(rect.size.width / ratio), (float)(rect.size.height / ratio));
}

std::string ZQTextAreaAnd::getString()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "getString", "()Ljava/lang/String;");
    
    auto ret = (jstring)env->CallObjectMethod(this->_view, mid);
    auto str = env->GetStringUTFChars(ret, 0);
    
    std::string text(str);
    
    env->ReleaseStringUTFChars(ret, str);
    env->DeleteLocalRef(ret);
    
    return text;
}

void ZQTextAreaAnd::openKeyboard()
{
    
}

void ZQTextAreaAnd::setParent(cocos2d::Node *parent)
{
    ZQTextArea::setParent(parent);
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setParent", "(Z)V");
    
    if (parent == nullptr)
    {
        env->CallVoidMethod(this->_view, mid, false);
    }
    else
    {
        env->CallVoidMethod(this->_view, mid, true);
        this->update();
    }
}

void ZQTextAreaAnd::setVisible(bool visible)
{
    ZQTextArea::setVisible(visible);
    
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setVisible", "(Z)V");
    
    env->CallVoidMethod(this->_view, mid, visible);
}

void ZQTextAreaAnd::setOpacity(GLubyte opacity)
{
    ZQTextArea::setOpacity(opacity);
    
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setOpacity", "(I)V");
    
    env->CallVoidMethod(this->_view, mid, (int)opacity);
}

void ZQTextAreaAnd::keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info)
{
    return;
}

void ZQTextAreaAnd::keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info)
{
    return;
}

#endif

