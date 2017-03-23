/***********************************************
* ZQLuaLoader.h
*
* @author: zyq
* @date: 17/3/22
* @Description:
*
***********************************************/

#ifndef __ZQLuaLoader_H__
#define __ZQLuaLoader_H__

#include "cocos2d.h"

extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
    
    extern int zq_lua_loader(lua_State *L);
}

#endif /* defined(__ZQLuaLoader_H__) */
