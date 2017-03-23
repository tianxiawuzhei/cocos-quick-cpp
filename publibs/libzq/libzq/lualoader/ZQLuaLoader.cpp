/***********************************************
* ZQLuaLoader.cpp
*
* @author: zyq
* @date: 17/3/22
* @Description:
*
***********************************************/

#include "ZQLuaLoader.h"
#include "data/ZQFileManage.h"
#include "log/ZQLogger.h"
#include "scripting/lua-bindings/manual/CCLuaStack.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

int zq_lua_loader(lua_State *L)
{
    static const std::string LUA_FILE_EXT = ".lua";
    
    std::string filename(luaL_checkstring(L, 1));
    size_t pos = filename.rfind(LUA_FILE_EXT);
    if (pos != std::string::npos)
    {
        filename = filename.substr(0, pos);
    }
    
    pos = filename.find_first_of(".");
    while (pos != std::string::npos)
    {
        filename.replace(pos, 1, "/");
        pos = filename.find_first_of(".");
    }
    
    std::string lua_filename = filename + LUA_FILE_EXT;
    
    cocos2d::Data data = zq::ZQFileManage::getInstance()->file_data(lua_filename);
    if (!data.isNull())
    {
        cocos2d::LuaStack* stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
        stack->luaLoadBuffer(L, (char*)data.getBytes(), (int)data.getSize(), lua_filename.c_str());
        return 1;
    }
    else
    {
        ZQLogE("lua file load fail : %s", lua_filename.c_str());
        return 0;
    }
}
