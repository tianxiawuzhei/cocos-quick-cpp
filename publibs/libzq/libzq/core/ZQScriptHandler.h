/***********************************************
* ZQScriptHandler.h
*
* @author: zyq
* @date: 17/2/21
* @Description:
*
***********************************************/
#ifndef __ZQSCRIPTHANDLER_H__
#define __ZQSCRIPTHANDLER_H__

#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

namespace zq {
    class ZQScriptHandler
    {
    public:
        ZQScriptHandler();
        virtual ~ZQScriptHandler();
        
    public:
        void registerScriptListener(cocos2d::LUA_FUNCTION listener);
        void unregisterScriptListener();
        
    public:
        bool valid();
        void emit(const std::string &func_name, const cocos2d::LuaValueDict &extra = cocos2d::LuaValueDict());
        void emitInCocosThread(const std::string &func_name, const cocos2d::LuaValueDict &extra = cocos2d::LuaValueDict());
    private:
        int _listener;
    };
}




#endif /* defined(__ZQSCRIPTHANDLER_H__) */
