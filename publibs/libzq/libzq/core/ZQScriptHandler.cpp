/***********************************************
* ZQScriptHandler.cpp
*
* @author: zyq
* @date: 17/2/21
* @Description:
*
***********************************************/
#include "ZQScriptHandler.h"
#include "ZQLogger.h"

using namespace zq;

ZQScriptHandler::ZQScriptHandler()
:_listener(0)
{
    
}

ZQScriptHandler::~ZQScriptHandler()
{
    if (this->_listener)
    {
        cocos2d::LuaEngine::getInstance()->removeScriptHandler(this->_listener);
    }
}

void ZQScriptHandler::registerScriptListener(cocos2d::LUA_FUNCTION listener)
{
    this->_listener = listener;
}

void ZQScriptHandler::unregisterScriptListener()
{
    if (_listener)
    {
        cocos2d::LuaEngine::getInstance()->removeScriptHandler(this->_listener);
        this->_listener = 0;
    }
}

bool ZQScriptHandler::valid()
{
    if (this->_listener != 0)
    {
        return true;
    }

    return false;
}

void ZQScriptHandler::emit(const std::string &func_name, const cocos2d::LuaValueDict &extra)
{
    if (!this->_listener)
    {
        ZQLogE("ZQScriptHandler: listener is null func_name : %s ", func_name.c_str());
    }
    
    cocos2d::LuaValueDict dict;
    
    dict["name"] = cocos2d::LuaValue::stringValue(func_name);
    dict["extra"] = cocos2d::LuaValue::dictValue(extra);
    
    cocos2d::LuaStack *stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
    stack->clean();
    stack->pushLuaValueDict(dict);
    stack->executeFunctionByHandler(_listener, 1);
}

void ZQScriptHandler::emitInCocosThread(const std::string &func_name, const cocos2d::LuaValueDict &extra)
{
    auto scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->performFunctionInCocosThread([this, func_name, extra](){
        this->emit(func_name, extra);
    });
}
