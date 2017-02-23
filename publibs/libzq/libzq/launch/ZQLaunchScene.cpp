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
    this->_window = this->getContentSize();
    this->_ratio = this->_window.height / 640.0;
    
    auto white = cocos2d::LayerColor::create(cocos2d::Color4B(255, 255, 255, 255));
    this->addChild(white);
    
    
}
