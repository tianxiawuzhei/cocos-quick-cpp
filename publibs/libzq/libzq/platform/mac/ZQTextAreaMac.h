//
//  ZQTextBoxMac.hpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQTEXTAREAMAC_H_
#define _ZQTEXTAREAMAC_H_

#include "ZQTextArea.h"
#include "cocos2d.h"

namespace zq
{
    class ZQTextAreaMac : public ZQTextArea
    {
    public:
        static ZQTextAreaMac* create();
        
    public:
        ZQTextAreaMac();
        virtual ~ZQTextAreaMac();
        
    public:
        virtual void setFont(const std::string &font_name, float font_size);
        
        virtual void setString(const std::string &text);
        
        virtual void setFontSize(float font_size);
        
        virtual void setFontColor(const cocos2d::Color3B &color);
        
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
        
        
    private:
        void* _scrollView;
        void* _view;
        void* _view_delegate;
        float _font_size;
    
    };
}
#endif /* _ZQTEXTAREAMAC_H_ */
