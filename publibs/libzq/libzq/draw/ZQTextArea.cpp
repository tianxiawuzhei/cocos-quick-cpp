/***********************************************
* ZQTextArea.cpp
*
* @author: zyq
* @date: 17/2/16
* @Description:
*
***********************************************/

#include "ZQTextArea.h"
#include "platform/ios/ZQTextAreaIOS.h"
#include "platform/mac/ZQTextAreaMac.h"

using namespace zq;

ZQTextArea::ZQTextArea()
:_maxLength(-1)
,_fontSize(-1)
,_placeholderFontSize(-1)
{
    this->setCascadeOpacityEnabled(true);
}

ZQTextArea* ZQTextArea::create(const cocos2d::Size &size)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    auto node = ZQTextAreaIOS::create();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    auto node = ZQTextAreaMac::create();
#endif
    
    if (node)
    {
        node->setContentSize(size);
    }
    
    return node;}

void ZQTextArea::setMaxLength(int length)
{
    this->_maxLength = length;
}

int ZQTextArea::maxLength()
{
    return this->_maxLength;
}

void ZQTextArea::setFont(const std::string &font_name, float font_size)
{
    this->_fontName = font_name;
    this->_fontSize = font_size;
}

void ZQTextArea::setFontSize(float font_size)
{
    this->setFont(_fontName, font_size);
}

void ZQTextArea::setPlaceholderFont(const std::string &font_name, float font_size)
{
    this->_placeholderFontName = font_name;
    this->_placeholderFontSize = font_size;
}

void ZQTextArea::setPlaceholderFontSize(float font_size)
{
    this->setPlaceholderFont(_placeholderFontName, font_size);
}

void ZQTextArea::setPosition(const cocos2d::Vec2 &position)
{
    cocos2d::Node::setPosition(position);
    this->update();
}

void ZQTextArea::setAnchorPoint(const cocos2d::Vec2& anchorPoint)
{
    cocos2d::Node::setAnchorPoint(anchorPoint);
    this->update();
}

void ZQTextArea::setContentSize(const cocos2d::Size &contentSize)
{
    cocos2d::Node::setContentSize(contentSize);
    this->update();
}

void ZQTextArea::setScaleX(float scaleX)
{
    cocos2d::Node::setScaleX(scaleX);
    this->update();
}

void ZQTextArea::setScaleY(float scaleY)
{
    cocos2d::Node::setScaleY(scaleY);
    this->update();
}

void ZQTextArea::setScale(float scale)
{
    cocos2d::Node::setScale(scale);
    this->update();
}

void ZQTextArea::onEnter()
{
    cocos2d::Node::onEnter();
    this->update();
}


