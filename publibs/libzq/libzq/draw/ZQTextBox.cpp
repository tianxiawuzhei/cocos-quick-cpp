/***********************************************
* ZQTextBox.cpp
*
* @author: zyq
* @date: 17/1/20
* @Description:
*
***********************************************/
#include "ZQTextBox.h"
#include "ZQTextBoxMac.h"

using namespace zq;
ZQTextBox* ZQTextBox::create(const cocos2d::Size &size)
{
    auto node = ZQTextBoxMac::create();
    if (node)
    {
        node->setContentSize(size);
    }
    
    return node;
}

ZQTextBox::ZQTextBox()
:_maxLength(-1)
,_fontSize(-1)
,_placeholderFontSize(-1)
{
    this->setCascadeOpacityEnabled(true);
}

void ZQTextBox::setMaxLength(int length)
{
    this->_maxLength = length;
}

int ZQTextBox::maxLength()
{
    return this->_maxLength;
}

void ZQTextBox::setFont(const std::string &font_name, float font_size)
{
    this->_fontName = font_name;
    this->_fontSize = font_size;
}

void ZQTextBox::setFontSize(float font_size)
{
    this->setFont(_fontName, font_size);
}

void ZQTextBox::setPlaceholderFont(const std::string &font_name, float font_size)
{
    this->_placeholderFontName = font_name;
    this->_placeholderFontSize = font_size;
}

void ZQTextBox::setPlaceholderFontSize(float font_size)
{
    this->setPlaceholderFont(_placeholderFontName, font_size);
}

void ZQTextBox::setPosition(const cocos2d::Vec2 &position)
{
    cocos2d::Node::setPosition(position);
    this->update();
}

void ZQTextBox::setAnchorPoint(const cocos2d::Vec2& anchorPoint)
{
    cocos2d::Node::setAnchorPoint(anchorPoint);
    this->update();
}

void ZQTextBox::setContentSize(const cocos2d::Size &contentSize)
{
    cocos2d::Node::setContentSize(contentSize);
    this->update();
}

void ZQTextBox::setScaleX(float scaleX)
{
    cocos2d::Node::setScaleX(scaleX);
    this->update();
}

void ZQTextBox::setScaleY(float scaleY)
{
    cocos2d::Node::setScaleY(scaleY);
    this->update();
}

void ZQTextBox::setScale(float scale)
{
    cocos2d::Node::setScale(scale);
    this->update();
}

void ZQTextBox::onEnter()
{
    cocos2d::Node::onEnter();
    this->update();
}


