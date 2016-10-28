//
//  lua_zq_visit_lua_manual.cpp
//  libzq
//
//  Created by staff on 16/10/26.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "lua_zq_visit_lua_manual.hpp"

#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "CCLuaEngine.h"

USING_NS_CC;

static int tolua_cocos2d_Node_registerVisitScriptHandler(lua_State* tolua_S)
{
    if (NULL == tolua_S)
        return 0;
    
    int argc = 0;
    Node* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Node",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<cocos2d::Node*>(tolua_tousertype(tolua_S,1,0));
#if COCOS2D_DEBUG >= 1
    if (nullptr == self) {
        tolua_error(tolua_S,"invalid 'self' in function 'tolua_cocos2d_Node_registerVisitScriptHandler'\n", NULL);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 1)
     {
#if COCOS2D_DEBUG >= 1
        if(!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err))
            goto tolua_lerror;
#endif
        
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S,2,0);
        ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, ScriptHandlerMgr::HandlerType::EVENT_NODE_VISIT_DRAW);
        
        return 0;
     }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n", "cc.Node:registerVisitScriptHandler",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_cocos2d_Node_registerVisitScriptHandler'.",&tolua_err);
    return 0;
#endif
}

static int tolua_cocos2d_Node_unregisterVisitScriptHandler(lua_State* tolua_S)
{
    if (NULL == tolua_S)
        return 0;
    
    int argc = 0;
    Node* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Node",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<cocos2d::Node*>(tolua_tousertype(tolua_S,1,0));
#if COCOS2D_DEBUG >= 1
    if (nullptr == self) {
        tolua_error(tolua_S,"invalid 'self' in function 'tolua_cocos2d_Node_unregisterVisitScriptHandler'\n", NULL);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 0)
     {
        ScriptHandlerMgr::getInstance()->removeObjectHandler((void*)self, ScriptHandlerMgr::HandlerType::EVENT_NODE_VISIT_DRAW);
        return 0;
     }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n", "cc.Node:unregisterVisitScriptHandler", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_cocos2d_Node_unregisterVisitScriptHandler'.",&tolua_err);
    return 0;
#endif
}

static void extendNodeVisit(lua_State* tolua_S)
{
    lua_pushstring(tolua_S,"cc.Node");
    lua_rawget(tolua_S,LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
     {
        lua_pushstring(tolua_S,"registerVisitScriptHandler");
        lua_pushcfunction(tolua_S,tolua_cocos2d_Node_registerVisitScriptHandler);
        lua_rawset(tolua_S,-3);
        lua_pushstring(tolua_S,"unregisterVisitScriptHandler");
        lua_pushcfunction(tolua_S,tolua_cocos2d_Node_unregisterVisitScriptHandler);
        lua_rawset(tolua_S, -3);
     }
    lua_pop(tolua_S, 1);
}

int register_visit_node_manual(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    
    extendNodeVisit(tolua_S);
    
    return 0;
}
