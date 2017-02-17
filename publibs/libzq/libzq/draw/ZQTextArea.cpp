/***********************************************
* ZQTextArea.cpp
*
* @author: zyq
* @date: 17/2/16
* @Description:
*
***********************************************/

#include "ZQTextArea.h"
#include "ZQTextAreaMac.h"

using namespace zq;

ZQTextArea::ZQTextArea()
:_maxLength(-1)
{
    this->setCascadeOpacityEnabled(true);
}

ZQTextArea* ZQTextArea::create(const cocos2d::Size &size)
{
    auto view = ZQTextAreaMac::create();
    if (view)
    {
        view->setContentSize(size);
    }
    
    return view;
}

void ZQTextArea::setMaxLength(int length)
{
    this->_maxLength = length;
}

int ZQTextArea::maxLength()
{
    return this->_maxLength;
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


