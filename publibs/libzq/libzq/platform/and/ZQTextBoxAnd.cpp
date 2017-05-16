//
//  ZQTextBoxMac.cpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//
#ifdef ANDROID

#include "ZQTextBoxAnd.h"
#include "jni/JniHelper.h"
#include "ui/CocosGUI.h"

using namespace zq;

// Cache
static std::map<jobject, ZQTextBoxAnd*> g_TextBox;

ZQTextBoxAnd::ZQTextBoxAnd()
: _view(nullptr)
, _info(nullptr)
, _size(23)
{
    auto env = cocos2d::JniHelper::getEnv();
    auto loc = env->FindClass("com/pinidea/shell/PITextBoxAnd");
    auto cls = (jclass)env->NewGlobalRef(loc);
    auto beg = env->GetMethodID(cls, "<init>", "()V");
    auto tmp = env->NewObject(cls, beg);
    auto obj = env->NewGlobalRef(tmp);
    
    this->_temp = tmp;
    this->_view = obj;
    this->_info = cls;
    
    g_TextBox[tmp] = this;
    
    env->DeleteLocalRef(tmp);
    env->DeleteLocalRef(loc);
}

ZQTextBoxAnd::~ZQTextBoxAnd()
{
    auto env = cocos2d::JniHelper::getEnv();
    env->DeleteGlobalRef(this->_view);
    env->DeleteGlobalRef(this->_info);
    
    auto it = g_TextBox.find(this->_temp);
    if (it != g_TextBox.end())
        g_TextBox.erase(it);
}

ZQTextBoxAnd* ZQTextBoxAnd::create()
{
    auto view = new ZQTextBoxAnd();
    view->autorelease();
    return view;
}

void ZQTextBoxAnd::setFont(const std::string &font_name, float font_size)
{
    ZQTextBox::setFont(font_name, font_size);
    auto font = SizeApplyAffineTransform(cocos2d::Size(0, font_size), this->getNodeToWorldAffineTransform()).height;
    auto env = cocos2d::JniHelper::getEnv();
    
    auto mid = env->GetMethodID(this->_info, "setFontSize", "(F)V");
    env->CallVoidMethod(this->_view, mid, font);
}

void ZQTextBoxAnd::setString(const std::string &text)
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setString", "(Ljava/lang/String;)V");
    
    jstring str = env->NewStringUTF(text.c_str());
    
    env->CallVoidMethod(this->_view, mid, str);
    
    env->DeleteLocalRef(str);
}

void ZQTextBoxAnd::setFontColor(const cocos2d::Color3B &color)
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setFontColor", "(III)V");
    
    env->CallVoidMethod(this->_view, mid, color.r, color.g, color.b);
}

void ZQTextBoxAnd::setPlaceholderFont(const std::string &font_name, float font_size)
{
//    ZQTextBox::setPlaceholderFont(font_name, font_size);
//    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
//    UIFont* font = constructFont(font_name.c_str(), fontSize, [(UIView*)this->_view frame]);
//    [(UITextField*)this->_view ccui_setPlaceholderFont:font];
}

void ZQTextBoxAnd::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
//    [(UITextField*)this->_view ccui_set:[UIColor colorWithRed:color.r / 255.0
//                                                                             green:color.g / 255.0
//                                                                              blue:color.b / 255.0
//                                                                             alpha:color.a]];
}

void ZQTextBoxAnd::setPlaceHolder(const std::string &text)
{
    
}

void ZQTextBoxAnd::setMaxLength(int length)
{
    ZQTextBox::setMaxLength(length);
//    [((UITextField*)this->_view) ccui_setMaxLength:length];
}

void ZQTextBoxAnd::setKeyboardDefault()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setKeyboardDefault", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::setKeyboardURL()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setKeyboardURL", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::setKeyboardNumber()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setKeyboardNumber", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::setKeyboardEmail()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setKeyboardEmail", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::setAlignmentLeft()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setAlignmentLeft", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::setAlignmentCenter()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setAlignmentCenter", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::setAlignmentRight()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setAlignmentRight", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::focus()
{
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "focus", "()V");
    
    env->CallVoidMethod(this->_view, mid);
}

void ZQTextBoxAnd::update()
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

std::string ZQTextBoxAnd::getString()
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

void ZQTextBoxAnd::openKeyboard()
{
    
}

void ZQTextBoxAnd::setParent(cocos2d::Node *parent)
{
    ZQTextBox::setParent(parent);
    
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

void ZQTextBoxAnd::setVisible(bool visible)
{
    ZQTextBox::setVisible(visible);
    
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setVisible", "(Z)V");
    
    env->CallVoidMethod(this->_view, mid, visible);
}

void ZQTextBoxAnd::setOpacity(GLubyte opacity)
{
    ZQTextBox::setOpacity(opacity);
    
    auto env = cocos2d::JniHelper::getEnv();
    auto mid = env->GetMethodID(this->_info, "setOpacity", "(I)V");
    
    env->CallVoidMethod(this->_view, mid, (int)opacity);
}

void ZQTextBoxAnd::keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info)
{
    return;
}

void ZQTextBoxAnd::keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info)
{
    return;
}

#endif

