//
//  ZQTextBoxMac.hpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//
#pragma once

#ifdef ANDROID

#include "draw/ZQTextArea.h"
#include "cocos2d.h"

namespace zq
{
    class ZQTextAreaAnd : public ZQTextArea
    {
    public:
        static ZQTextAreaAnd* create();
        
    public:
        ZQTextAreaAnd();
        virtual ~ZQTextAreaAnd();
        
    public:
        virtual void setFont(const std::string &font_name, float font_size);
        virtual void setFontColor(const cocos2d::Color3B &color);
        virtual void setString(const std::string &text);
        
        virtual void setPlaceholderFont(const std::string &font_name, float font_size);
        virtual void setPlaceholderFontColor(const cocos2d::Color4B &color);
        virtual void setPlaceHolder(const std::string &text);
        
        virtual void setKeyboardDefault() {}
        virtual void setKeyboardURL() {}
        virtual void setKeyboardNumber() {}
        virtual void setKeyboardEmail() {}
        
        virtual void setAlignmentLeft();
        virtual void setAlignmentCenter();
        virtual void setAlignmentRight();
        
        virtual void setMaxLength(int length);
        
        virtual void focus();
        
        virtual void update();
        
        virtual void openKeyboard();
        
    public:
        virtual std::string getString();
        
    public:
        virtual void setVisible(bool visible);
        virtual void setOpacity(GLubyte opacity);
        virtual void setParent(cocos2d::Node *parent);
        
    public:
        virtual void keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info);
        
        virtual void keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info);
        
    private:
        jobject _temp;
        jobject _view;
        jclass  _info;
    
    };
}

#endif
