/***********************************************
* ZQCustomAction.h
*
* @author: zyq
* @date: 16/12/22
* @Description:
*
***********************************************/

#ifndef __ZQCUSTOMACTION_H__
#define __ZQCUSTOMACTION_H__

#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

namespace zq
{

class ZQCustomAction : public cocos2d::ActionInterval
{
public:
    ZQCustomAction();
    virtual ~ZQCustomAction();
public:
    static ZQCustomAction* create();
    
    void registerScriptListener(cocos2d::LUA_FUNCTION listener);
    void unregisterScriptListener();
public:
    /** initializes the action */
    bool initWithDuration(float duration);
    
    virtual void startWithTarget(cocos2d::Node *target) override;
    
    /**
     * @param time in seconds
     */
    virtual void update(float time) override;
    
private:
    int _listener;
};

    
}


#endif /* defined(__ZQCUSTOMACTION_H__) */
