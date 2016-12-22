/***********************************************
* ZQCustomAction.cpp
*
* @author: zyq
* @date: 16/12/22
* @Description:
*
***********************************************/
#include "ZQCustomAction.h"

using namespace zq;

ZQCustomAction::ZQCustomAction():_listener(0)
{
    
}

ZQCustomAction::~ZQCustomAction()
{
    if (_listener)
    {
        cocos2d::LuaEngine::getInstance()->removeScriptHandler(_listener);
    }
}

ZQCustomAction* ZQCustomAction::create()
{
    ZQCustomAction* customAction = new (std::nothrow) ZQCustomAction();
    customAction->autorelease();
    
    return customAction;
}

void ZQCustomAction::registerScriptListener(cocos2d::LUA_FUNCTION listener)
{
    this->_listener = listener;
}

void ZQCustomAction::unregisterScriptListener()
{
    if (_listener)
    {
        cocos2d::LuaEngine::getInstance()->removeScriptHandler(_listener);
        _listener = 0;
    }
}

bool ZQCustomAction::initWithDuration(float duration)
{
    return cocos2d::ActionInterval::initWithDuration(duration);
}

void ZQCustomAction::startWithTarget(cocos2d::Node *target)
{
    cocos2d::ActionInterval::startWithTarget(target);
    
    if (_listener)
    {
        cocos2d::LuaValueDict dict;
        
        dict["name"] = cocos2d::LuaValue::stringValue("startWithTarget");
        dict["total"] = cocos2d::LuaValue::intValue((int)5);
        
        cocos2d::LuaStack *stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
        stack->clean();
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(_listener, 1);
    }
}

void ZQCustomAction::update(float time)
{
    if (_listener)
    {
        cocos2d::LuaValueDict dict;
        
        dict["name"] = cocos2d::LuaValue::stringValue("update");
        dict["time"] = cocos2d::LuaValue::floatValue(time);
  
        cocos2d::LuaStack *stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
        stack->clean();
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(_listener, 1);
    }

}
