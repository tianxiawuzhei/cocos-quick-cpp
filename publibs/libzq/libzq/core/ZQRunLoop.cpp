/***********************************************
* ZQRunLoop.cpp
*
* @author: zyq
* @date: 17/2/22
* @Description:
*
***********************************************/

#include "ZQRunLoop.h"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

using namespace zq;

ZQRunLoop* ZQRunLoop::getInstance()
{
    static ZQRunLoop instance;
    return &instance;
}

ZQRunLoop::ZQRunLoop()
{
    this->reset();
}

ZQRunLoop::~ZQRunLoop()
{
    auto scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->unscheduleUpdate(this);
}

void ZQRunLoop::reset()
{
    this->_queue.clear();
    auto scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->unscheduleUpdate(this);
    scheduler->scheduleUpdate(this, 0, false);
    
    bool debug = false;
#if COCOS2D_DEBUG
    debug = true;
#else
    debug = false;
#endif
    
    auto engine = cocos2d::LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        tolua_module(L,"zq",0);
        tolua_beginmodule(L,"zq");
        lua_pushstring(L,"DEBUG");
        
        tolua_pushboolean(L, debug);
        lua_rawset(L,-3);
        tolua_endmodule(L);
    }
    lua_pop(L, 1);
    
}

void ZQRunLoop::schedule(type_callback callback, void *caller)
{
    if (!callback)
    {
        return;
    }
    
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->_queue.push_back(std::make_pair(caller, callback));
}

void ZQRunLoop::unschedule(void *caller)
{
    std::lock_guard<std::mutex> lock(this->_mutex);
    for (auto it = this->_queue.begin(); it != this->_queue.end();) {
        const auto &cur = it++;
        if (cur->first == caller)
        {
            this->_queue.erase(cur);
        }
        
    }
}

void ZQRunLoop::update(float dt)
{
    if (!this->_queue.size())
    {
        return;
    }
    
    while (this->_queue.size())
    {
        
        type_store pair;
        {
            std::lock_guard<std::mutex> lock(this->_mutex);
            pair = this->_queue.front();
            this->_queue.pop_front();
        }
        
        pair.second();
    }
}
