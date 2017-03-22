/***********************************************
* ZQLaunchScene.cpp
*
* @author: zyq
* @date: 17/2/23
* @Description:
*
***********************************************/
#include "ZQLaunchScene.h"
#include "core/ZQAppCenter.h"
#include "tool/ZQDeviceInfo.h"

using namespace zq;

ZQLaunchScene* ZQLaunchScene::create()
{
    ZQLaunchScene *ret = new (std::nothrow) ZQLaunchScene();
    if (ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

ZQLaunchScene::ZQLaunchScene()
:_ratio(1.0)
{
    
}

ZQLaunchScene::~ZQLaunchScene()
{
    
}

void ZQLaunchScene::onEnterTransitionDidFinish()
{
    this->show();
    this->scheduleOnce([] (float dt) {
        ZQAppCenter::getInstance()->start();
    }, 0.1, "launch");
    
}

void ZQLaunchScene::show()
{
    this->_screenSize = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
    this->_winSize = cocos2d::Director::getInstance()->getWinSize();
    this->_ratio = this->_winSize.height / 640.0;
    
    auto white = cocos2d::LayerColor::create(cocos2d::Color4B(255, 255, 255, 255));
    this->addChild(white);
    
    cocos2d::Sprite *splash = nullptr;
    if (ZQDeviceInfo::getInstance()->os_is_ios())
    {
        if ((this->_screenSize.width == 960) && (this->_screenSize.height == 640))
        {
            // iPhone4, 4s
            splash = cocos2d::Sprite::create("Default@2x.png");
        }
        else if ((this->_screenSize.width == 1136) && (this->_screenSize.height == 640))
        {
            // iPhone5, 5s
            splash = cocos2d::Sprite::create("Default-568h@2x.png");
        }
        else if ((this->_screenSize.width == 1334) && (this->_screenSize.height == 750))
        {
            // iPhone6, 6s
            splash = cocos2d::Sprite::create("Default-375w-667h@2x~iphone.png");
        }
        else if ((this->_screenSize.width == 2208) && (this->_screenSize.height == 1242))
        {
            // iPhone6 Plus, 6s Plus
            splash = cocos2d::Sprite::create("Default@3x.png");
        }
        else if ((this->_screenSize.width == 1024) && (this->_screenSize.height == 768))
        {
            // iPad1, 2
            splash = cocos2d::Sprite::create("Default~ipad.png");
        }
        else if ((this->_screenSize.width == 2048) && (this->_screenSize.height == 1536))
        {
            // iPad3, Air, Retina, Mini
            splash = cocos2d::Sprite::create("Default@2x~ipad.png");
        }
    }
    
    if (!splash)
    {
        splash = cocos2d::Sprite::create("Default-568h@2x.png");
        if (splash)
        {
            splash->setScale(this->_ratio);
        }
    }
    
    if (splash)
    {
        splash->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
        splash->setPosition(cocos2d::Vec2(this->_winSize.width/2, this->_winSize.height/2));
        splash->setRotation(-90);
        this->addChild(splash);
    }
}
