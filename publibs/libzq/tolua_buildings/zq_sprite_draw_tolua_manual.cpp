/*
** Lua binding: zq_sprite_draw_tolua_manual
** Generated automatically by tolua++-1.0.92 on Mon Dec 26 14:05:45 2016.
*/

#include "zq_sprite_draw_tolua_manual.h"
#include "CCLuaEngine.h"

using namespace cocos2d;




#include "2d/CCSprite.h"
using namespace std;
using namespace cocos2d;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Sprite");
 
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"TextureProtocol");
}

/* method: registerDrawScriptHandler of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_zq_sprite_draw_tolua_manual_Sprite_registerDrawScriptHandler00
static int tolua_zq_sprite_draw_tolua_manual_Sprite_registerDrawScriptHandler00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"cc.Sprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerDrawScriptHandler'", NULL);
#endif
  {
   self->registerDrawScriptHandler(listener);
      self->setDrawBeg([listener]() -> void{
          if (listener)
          {
              cocos2d::LuaValueDict dict;
              
              dict["name"] = cocos2d::LuaValue::stringValue("began");
              
              cocos2d::LuaStack *stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
              stack->clean();
              stack->pushLuaValueDict(dict);
              stack->executeFunctionByHandler(listener, 1);
          }

      });
      
      self->setDrawEnd([listener]() -> void{
          if (listener)
          {
              cocos2d::LuaValueDict dict;
              
              dict["name"] = cocos2d::LuaValue::stringValue("end");
              
              cocos2d::LuaStack *stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
              stack->clean();
              stack->pushLuaValueDict(dict);
              stack->executeFunctionByHandler(listener, 1);
          }
          
      });
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerDrawScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterDrawScriptHandler of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_zq_sprite_draw_tolua_manual_Sprite_unregisterDrawScriptHandler00
static int tolua_zq_sprite_draw_tolua_manual_Sprite_unregisterDrawScriptHandler00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"cc.Sprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterDrawScriptHandler'", NULL);
#endif
  {
   self->unregisterDrawScriptHandler();
      self->setDrawBeg(nullptr);
      self->setDrawEnd(nullptr);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterDrawScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_zq_sprite_draw_tolua_manual_open (lua_State* tolua_S)
{
    lua_pushstring(tolua_S,"cc.Sprite");
    lua_rawget(tolua_S,LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S,"registerDrawScriptHandler",tolua_zq_sprite_draw_tolua_manual_Sprite_registerDrawScriptHandler00);
        tolua_function(tolua_S,"unregisterDrawScriptHandler",tolua_zq_sprite_draw_tolua_manual_Sprite_unregisterDrawScriptHandler00);
    }
    lua_pop(tolua_S, 1);
   
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_zq_sprite_draw_tolua_manual (lua_State* tolua_S) {
 return tolua_zq_sprite_draw_tolua_manual_open(tolua_S);
};
#endif

