/*
** Lua binding: zq_quick_tolua_luabinding
** Generated automatically by tolua++-1.0.92 on Thu Dec 22 19:12:37 2016.
*/

#include "zq_quick_tolua_luabinding.h"
#include "CCLuaEngine.h"

using namespace cocos2d;




#include "draw/ZQCustomAction.h"
using namespace std;
using namespace cocos2d;
using namespace zq;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"cc.ActionInterval");
 
 tolua_usertype(tolua_S,"ZQCustomAction");
}

/* method: registerScriptListener of class  ZQCustomAction */
#ifndef TOLUA_DISABLE_tolua_zq_quick_tolua_luabinding_ZQCustomAction_registerScriptListener00
static int tolua_zq_quick_tolua_luabinding_ZQCustomAction_registerScriptListener00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zq.ZQCustomAction",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZQCustomAction* self = (ZQCustomAction*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptListener'", NULL);
#endif
  {
   self->registerScriptListener(listener);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerScriptListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterScriptListener of class  ZQCustomAction */
#ifndef TOLUA_DISABLE_tolua_zq_quick_tolua_luabinding_ZQCustomAction_unregisterScriptListener00
static int tolua_zq_quick_tolua_luabinding_ZQCustomAction_unregisterScriptListener00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zq.ZQCustomAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ZQCustomAction* self = (ZQCustomAction*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterScriptListener'", NULL);
#endif
  {
   self->unregisterScriptListener();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterScriptListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_zq_quick_tolua_luabinding_open (lua_State* tolua_S)
{
    lua_pushstring(tolua_S, "zq.ZQCustomAction");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S,"registerScriptListener",tolua_zq_quick_tolua_luabinding_ZQCustomAction_registerScriptListener00);
        tolua_function(tolua_S,"unregisterScriptListener",tolua_zq_quick_tolua_luabinding_ZQCustomAction_unregisterScriptListener00);
    }
    lua_pop(tolua_S, 1);

 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_zq_quick_tolua_luabinding (lua_State* tolua_S) {
 return tolua_zq_quick_tolua_luabinding_open(tolua_S);
};
#endif

