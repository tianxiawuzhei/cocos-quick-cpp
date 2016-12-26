
#ifndef __ZQ_SPRITE_DRAW_TOLUA_MANUAL_H_
#define __ZQ_SPRITE_DRAW_TOLUA_MANUAL_H_

extern "C" {
#include "lua.h"
#include "tolua++.h"
}
#include "tolua_fix.h"

TOLUA_API int luaopen_zq_sprite_draw_tolua_manual(lua_State* tolua_S);

#endif // __ZQ_SPRITE_DRAW_TOLUA_MANUAL_H_
