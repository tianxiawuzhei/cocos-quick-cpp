/***********************************************
* ZQTextBox.h
*
* @author: zyq
* @date: 17/1/20
* @Description:
*
***********************************************/

#ifndef __ZQTEXTBOX_H__
#define __ZQTEXTBOX_H__

#include "cocos2d.h"

namespace zq
{
    class ZQTextBox : public cocos2d::Node, cocos2d::IMEDelegate
    {
    public:
        static ZQTextBox* create(const cocos2d::Size &size = cocos2d::Size());
        
    protected:
        ZQTextBox();
        virtual ~ZQTextBox() = default;
        
    public:
        virtual void setFont(const std::string &font_name, float font_size);
        virtual void setFontSize(float font_size);
        virtual void setFontColor(const cocos2d::Color3B &color) = 0;
        virtual void setString(const std::string &text) = 0;
        
        virtual void setPlaceholderFont(const std::string &font_name, float font_size);
        virtual void setPlaceholderFontSize(float font_size);
        virtual void setPlaceholderFontColor(const cocos2d::Color4B &color) = 0;
        virtual void setPlaceHolder(const std::string &text) = 0;
        
        virtual void setKeyboardDefault()   = 0;
        virtual void setKeyboardURL()       = 0;
        virtual void setKeyboardNumber()    = 0;
        virtual void setKeyboardEmail()     = 0;
        
        virtual void setAlignmentLeft()   = 0;
        virtual void setAlignmentCenter() = 0;
        virtual void setAlignmentRight()  = 0;
        
        virtual void setMaxLength(int length);
        
        virtual void focus() = 0;
        
        virtual void update() = 0;
        
        virtual void openKeyboard() = 0;
        
    public:
        virtual std::string getString() = 0;
        
        virtual int maxLength();
    
    public:        
        virtual void setPosition(const cocos2d::Vec2 &position);
        virtual void setAnchorPoint(const cocos2d::Vec2& anchorPoint);
        virtual void setContentSize(const cocos2d::Size &contentSize);
        
        virtual void setScaleX(float scaleX);
        virtual void setScaleY(float scaleY);
        virtual void setScale(float scale);
        
        virtual void onEnter();
    
    public:
        virtual void keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info){};
        
        virtual void keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info){};
      
    protected:
        std::string _fontName;
        std::string _placeholderFontName;
        
        float _fontSize;
        float _placeholderFontSize;
    protected:
        int _maxLength;
        float _adjustHeight;
    };
}


#endif /* defined(__ZQTEXTBOX_H__) */
