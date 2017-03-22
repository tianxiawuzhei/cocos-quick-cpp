/***********************************************
* ZQLaunchScene.h
*
* @author: zyq
* @date: 17/2/23
* @Description:
*
************************************************/

#ifndef __ZQLAUNCHSCENE_H__
#define __ZQLAUNCHSCENE_H__

#include "cocos2d.h"

namespace zq
{
    class ZQLaunchScene : public cocos2d::Scene
    {
    public:
        static ZQLaunchScene* create();
        
    public:
        ZQLaunchScene();
        virtual ~ZQLaunchScene();
        
    public:
        virtual void onEnterTransitionDidFinish();
        void show();
        
    private:
        cocos2d::Size _screenSize;
        cocos2d::Size _winSize;
        float _ratio;
    };
}


#endif /* defined(__ZQLAUNCHSCENE_H__) */
