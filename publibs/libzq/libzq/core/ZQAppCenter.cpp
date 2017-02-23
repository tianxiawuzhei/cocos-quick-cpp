/***********************************************
* ZQAppCenter.cpp
*
* @author: zyq
* @date: 17/2/22
* @Description:
*
***********************************************/
#include "ZQAppCenter.h"
#include "core/ZQRunLoop.h"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

using namespace zq;
ZQAppCenter* ZQAppCenter::getInstance()
{
    static ZQAppCenter instance;
    return &instance;
}

void ZQAppCenter::start()
{
    if (this->_restart)
        this->_restart = false;
    
    ZQRunLoop::getInstance()->reset();
    
    if (!this->_script_file.empty())
    {
        auto engine = cocos2d::LuaEngine::getInstance();
        engine->executeScriptFile(this->_script_file.c_str());
    }
}

void ZQAppCenter::restart()
{
    this->_restart = true;
    
    auto director = cocos2d::Director::getInstance();
    director->restart();
}

void ZQAppCenter::quit()
{
    
}

bool ZQAppCenter::isRestart()
{
    return this->_restart;
}
