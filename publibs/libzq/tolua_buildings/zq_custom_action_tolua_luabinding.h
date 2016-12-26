
#ifndef __ZQ_CUSTOM_ACTION_TOLUA_LUABINDING_H_
#define __ZQ_CUSTOM_ACTION_TOLUA_LUABINDING_H_

extern "C" {
#include "lua.h"
#include "tolua++.h"
}
#include "tolua_fix.h"

TOLUA_API int luaopen_zq_custom_action_tolua_luabinding(lua_State* tolua_S);

#endif // __ZQ_CUSTOM_ACTION_TOLUA_LUABINDING_H_
