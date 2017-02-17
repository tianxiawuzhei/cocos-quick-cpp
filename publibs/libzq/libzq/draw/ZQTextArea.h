/***********************************************
* ZQTextArea.h
*
* @author: zyq
* @date: 17/2/16
* @Description:
*
***********************************************/

#ifndef __ZQTEXTAREA_H__
#define __ZQTEXTAREA_H__

#include "cocos2d.h"
namespace zq
{
    class ZQTextArea : public cocos2d::Node, cocos2d::IMEDelegate
    {
    public:
        static ZQTextArea* create(const cocos2d::Size &size = cocos2d::Size());
    
    protected:
        ZQTextArea();
        virtual ~ZQTextArea() = default;
    
    public:
        virtual void setFont(const std::string &font_name, float font_size) = 0;
        
        virtual void setString(const std::string &text) = 0;
        
        virtual void setFontSize(float font_size) = 0;
        
        virtual void setFontColor(const cocos2d::Color3B &color) = 0;
        
        /**
         * Set the font color of the placeholder text when the edit box is empty.
         */
        virtual void setPlaceholderFontColor(const cocos2d::Color4B &color) = 0;
        
        /**
         * Set a text in the edit box that acts as a placeholder when an
         */
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
        virtual void keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info){}
        
        virtual void keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info){}
        
    protected:
        int _maxLength;
        float _adjustHeight;
    
    };
}



#endif /* defined(__ZQTEXTAREA_H__) */
