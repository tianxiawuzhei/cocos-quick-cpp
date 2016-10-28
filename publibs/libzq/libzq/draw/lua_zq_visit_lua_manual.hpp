//
//  lua_zq_visit_lua_manual.hpp
//  libzq
//
//  Created by staff on 16/10/26.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _LUA_ZQ_VISIT_LUA_MANUAL_HPP_
#define _LUA_ZQ_VISIT_LUA_MANUAL_HPP_

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "cocos2d.h"

TOLUA_API int register_visit_node_manual(lua_State* tolua_S);

#endif /* _LUA_ZQ_VISIT_LUA_MANUAL_HPP_ */
