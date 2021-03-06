#include "lua_zq_auto.hpp"
#include "ZQLibExt.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_zq_DateUtils_getMilliseconds(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.DateUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_DateUtils_getMilliseconds'", nullptr);
            return 0;
        }
        double ret = zq::DateUtils::getMilliseconds();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.DateUtils:getMilliseconds",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_DateUtils_getMilliseconds'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_DateUtils_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DateUtils)");
    return 0;
}

int lua_register_zq_DateUtils(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.DateUtils");
    tolua_cclass(tolua_S,"DateUtils","zq.DateUtils","",nullptr);

    tolua_beginmodule(tolua_S,"DateUtils");
        tolua_function(tolua_S,"getMilliseconds", lua_zq_DateUtils_getMilliseconds);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::DateUtils).name();
    g_luaType[typeName] = "zq.DateUtils";
    g_typeCast["DateUtils"] = "zq.DateUtils";
    return 1;
}

int lua_zq_ZQLogger_debug(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQLogger* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQLogger",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQLogger*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQLogger_debug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQLogger:debug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQLogger_debug'", nullptr);
            return 0;
        }
        cobj->debug(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQLogger:debug",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQLogger_debug'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQLogger_write(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQLogger* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQLogger",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQLogger*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQLogger_write'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQLogger:write");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQLogger_write'", nullptr);
            return 0;
        }
        cobj->write(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQLogger:write",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQLogger_write'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQLogger_rename(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQLogger* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQLogger",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQLogger*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQLogger_rename'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQLogger:rename");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQLogger_rename'", nullptr);
            return 0;
        }
        cobj->rename(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQLogger:rename",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQLogger_rename'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQLogger_filePath(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQLogger* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQLogger",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQLogger*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQLogger_filePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQLogger_filePath'", nullptr);
            return 0;
        }
        std::string ret = cobj->filePath();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQLogger:filePath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQLogger_filePath'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQLogger_error(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQLogger* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQLogger",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQLogger*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQLogger_error'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQLogger:error");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQLogger_error'", nullptr);
            return 0;
        }
        cobj->error(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQLogger:error",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQLogger_error'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQLogger_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQLogger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQLogger_getInstance'", nullptr);
            return 0;
        }
        zq::ZQLogger* ret = zq::ZQLogger::getInstance();
        object_to_luaval<zq::ZQLogger>(tolua_S, "zq.ZQLogger",(zq::ZQLogger*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQLogger:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQLogger_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQLogger_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQLogger)");
    return 0;
}

int lua_register_zq_ZQLogger(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQLogger");
    tolua_cclass(tolua_S,"ZQLogger","zq.ZQLogger","",nullptr);

    tolua_beginmodule(tolua_S,"ZQLogger");
        tolua_function(tolua_S,"debug",lua_zq_ZQLogger_debug);
        tolua_function(tolua_S,"write",lua_zq_ZQLogger_write);
        tolua_function(tolua_S,"rename",lua_zq_ZQLogger_rename);
        tolua_function(tolua_S,"filePath",lua_zq_ZQLogger_filePath);
        tolua_function(tolua_S,"error",lua_zq_ZQLogger_error);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQLogger_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQLogger).name();
    g_luaType[typeName] = "zq.ZQLogger";
    g_typeCast["ZQLogger"] = "zq.ZQLogger";
    return 1;
}

int lua_zq_ZQFileManage_isFileExist(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_isFileExist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:isFileExist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_isFileExist'", nullptr);
            return 0;
        }
        bool ret = cobj->isFileExist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:isFileExist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_isFileExist'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_file_string(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_file_string'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:file_string");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_file_string'", nullptr);
            return 0;
        }
        std::string ret = cobj->file_string(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:file_string",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_file_string'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_removeDirectory(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_removeDirectory'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:removeDirectory");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_removeDirectory'", nullptr);
            return 0;
        }
        bool ret = cobj->removeDirectory(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:removeDirectory",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_removeDirectory'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_prepare(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_prepare'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_prepare'", nullptr);
            return 0;
        }
        cobj->prepare();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:prepare",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_prepare'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_getFileSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_getFileSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:getFileSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getFileSize'", nullptr);
            return 0;
        }
        long ret = cobj->getFileSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:getFileSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getFileSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_removeFile(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_removeFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:removeFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_removeFile'", nullptr);
            return 0;
        }
        bool ret = cobj->removeFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:removeFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_removeFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_renameFile(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_renameFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:renameFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQFileManage:renameFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_renameFile'", nullptr);
            return 0;
        }
        bool ret = cobj->renameFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:renameFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_renameFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_getStringFromFile(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_getStringFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:getStringFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getStringFromFile'", nullptr);
            return 0;
        }
        std::string ret = cobj->getStringFromFile(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:getStringFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getStringFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_addSearchPath(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_addSearchPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:addSearchPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_addSearchPath'", nullptr);
            return 0;
        }
        cobj->addSearchPath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:addSearchPath");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.ZQFileManage:addSearchPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_addSearchPath'", nullptr);
            return 0;
        }
        cobj->addSearchPath(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:addSearchPath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_addSearchPath'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_load_disk(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_load_disk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:load_disk");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_load_disk'", nullptr);
            return 0;
        }
        std::string ret = cobj->load_disk(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:load_disk",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_load_disk'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_createDirectory(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_createDirectory'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:createDirectory");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_createDirectory'", nullptr);
            return 0;
        }
        bool ret = cobj->createDirectory(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:createDirectory",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_createDirectory'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_load_file(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_load_file'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:load_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_load_file'", nullptr);
            return 0;
        }
        std::string ret = cobj->load_file(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:load_file",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_load_file'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_getWritablePath(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQFileManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQFileManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_getWritablePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getWritablePath'", nullptr);
            return 0;
        }
        std::string ret = cobj->getWritablePath();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:getWritablePath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getWritablePath'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQFileManage_url_for_file(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:url_for_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_url_for_file'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::url_for_file(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:url_for_file",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_url_for_file'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_dir_exist(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:dir_exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_dir_exist'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::dir_exist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:dir_exist");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.ZQFileManage:dir_exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_dir_exist'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::dir_exist(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:dir_exist",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_dir_exist'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_file_exist(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:file_exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_file_exist'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::file_exist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:file_exist");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQFileManage:file_exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_file_exist'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::file_exist(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        bool arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:file_exist");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQFileManage:file_exist");
        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "zq.ZQFileManage:file_exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_file_exist'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::file_exist(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:file_exist",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_file_exist'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_create_folder(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:create_folder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_create_folder'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::create_folder(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:create_folder",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_create_folder'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getInstance'", nullptr);
            return 0;
        }
        zq::ZQFileManage* ret = zq::ZQFileManage::getInstance();
        object_to_luaval<zq::ZQFileManage>(tolua_S, "zq.ZQFileManage",(zq::ZQFileManage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_url_for_res(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_url_for_res'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::url_for_res();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:url_for_res",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_url_for_res'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_dirname_of_path(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:dirname_of_path");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_dirname_of_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::dirname_of_path(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:dirname_of_path");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.ZQFileManage:dirname_of_path");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_dirname_of_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::dirname_of_path(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:dirname_of_path",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_dirname_of_path'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_url_for_code(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_url_for_code'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::url_for_code();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:url_for_code",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_url_for_code'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_append_file(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        const unsigned char* arg1;
        unsigned int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:append_file");
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "zq.ZQFileManage:append_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_append_file'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::append_file(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:append_file",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_append_file'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_basename_of_path(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:basename_of_path");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_basename_of_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::basename_of_path(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:basename_of_path");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.ZQFileManage:basename_of_path");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_basename_of_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::basename_of_path(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:basename_of_path",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_basename_of_path'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_temp_path(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_temp_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::temp_path();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:temp_path",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_temp_path'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_set_url_for_res(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:set_url_for_res");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_set_url_for_res'", nullptr);
            return 0;
        }
        zq::ZQFileManage::set_url_for_res(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:set_url_for_res",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_set_url_for_res'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_extname_of_path(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:extname_of_path");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_extname_of_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::extname_of_path(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:extname_of_path");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.ZQFileManage:extname_of_path");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_extname_of_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::extname_of_path(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:extname_of_path",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_extname_of_path'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_log_path(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_log_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::log_path();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:log_path",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_log_path'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_write_file(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        const unsigned char* arg1;
        unsigned int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:write_file");
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "zq.ZQFileManage:write_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_write_file'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::write_file(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:write_file",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_write_file'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_cache_path(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_cache_path'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::cache_path();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:cache_path",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_cache_path'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_file_size(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:file_size");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_file_size'", nullptr);
            return 0;
        }
        unsigned int ret = zq::ZQFileManage::file_size(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:file_size",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_file_size'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_rename_file(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:rename_file");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQFileManage:rename_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_rename_file'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::rename_file(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:rename_file",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_rename_file'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_rebuild_folder(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:rebuild_folder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_rebuild_folder'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::rebuild_folder(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:rebuild_folder",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_rebuild_folder'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_remove_file(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:remove_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_remove_file'", nullptr);
            return 0;
        }
        bool ret = zq::ZQFileManage::remove_file(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:remove_file",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_remove_file'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_set_url_for_code(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQFileManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:set_url_for_code");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_set_url_for_code'", nullptr);
            return 0;
        }
        zq::ZQFileManage::set_url_for_code(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:set_url_for_code",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_set_url_for_code'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQFileManage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQFileManage)");
    return 0;
}

int lua_register_zq_ZQFileManage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQFileManage");
    tolua_cclass(tolua_S,"ZQFileManage","zq.ZQFileManage","",nullptr);

    tolua_beginmodule(tolua_S,"ZQFileManage");
        tolua_function(tolua_S,"isFileExist",lua_zq_ZQFileManage_isFileExist);
        tolua_function(tolua_S,"file_string",lua_zq_ZQFileManage_file_string);
        tolua_function(tolua_S,"removeDirectory",lua_zq_ZQFileManage_removeDirectory);
        tolua_function(tolua_S,"prepare",lua_zq_ZQFileManage_prepare);
        tolua_function(tolua_S,"getFileSize",lua_zq_ZQFileManage_getFileSize);
        tolua_function(tolua_S,"removeFile",lua_zq_ZQFileManage_removeFile);
        tolua_function(tolua_S,"renameFile",lua_zq_ZQFileManage_renameFile);
        tolua_function(tolua_S,"getStringFromFile",lua_zq_ZQFileManage_getStringFromFile);
        tolua_function(tolua_S,"addSearchPath",lua_zq_ZQFileManage_addSearchPath);
        tolua_function(tolua_S,"load_disk",lua_zq_ZQFileManage_load_disk);
        tolua_function(tolua_S,"createDirectory",lua_zq_ZQFileManage_createDirectory);
        tolua_function(tolua_S,"load_file",lua_zq_ZQFileManage_load_file);
        tolua_function(tolua_S,"getWritablePath",lua_zq_ZQFileManage_getWritablePath);
        tolua_function(tolua_S,"url_for_file", lua_zq_ZQFileManage_url_for_file);
        tolua_function(tolua_S,"dir_exist", lua_zq_ZQFileManage_dir_exist);
        tolua_function(tolua_S,"file_exist", lua_zq_ZQFileManage_file_exist);
        tolua_function(tolua_S,"create_folder", lua_zq_ZQFileManage_create_folder);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQFileManage_getInstance);
        tolua_function(tolua_S,"url_for_res", lua_zq_ZQFileManage_url_for_res);
        tolua_function(tolua_S,"dirname_of_path", lua_zq_ZQFileManage_dirname_of_path);
        tolua_function(tolua_S,"url_for_code", lua_zq_ZQFileManage_url_for_code);
        tolua_function(tolua_S,"append_file", lua_zq_ZQFileManage_append_file);
        tolua_function(tolua_S,"basename_of_path", lua_zq_ZQFileManage_basename_of_path);
        tolua_function(tolua_S,"temp_path", lua_zq_ZQFileManage_temp_path);
        tolua_function(tolua_S,"set_url_for_res", lua_zq_ZQFileManage_set_url_for_res);
        tolua_function(tolua_S,"extname_of_path", lua_zq_ZQFileManage_extname_of_path);
        tolua_function(tolua_S,"log_path", lua_zq_ZQFileManage_log_path);
        tolua_function(tolua_S,"write_file", lua_zq_ZQFileManage_write_file);
        tolua_function(tolua_S,"cache_path", lua_zq_ZQFileManage_cache_path);
        tolua_function(tolua_S,"file_size", lua_zq_ZQFileManage_file_size);
        tolua_function(tolua_S,"rename_file", lua_zq_ZQFileManage_rename_file);
        tolua_function(tolua_S,"rebuild_folder", lua_zq_ZQFileManage_rebuild_folder);
        tolua_function(tolua_S,"remove_file", lua_zq_ZQFileManage_remove_file);
        tolua_function(tolua_S,"set_url_for_code", lua_zq_ZQFileManage_set_url_for_code);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQFileManage).name();
    g_luaType[typeName] = "zq.ZQFileManage";
    g_typeCast["ZQFileManage"] = "zq.ZQFileManage";
    return 1;
}

int lua_zq_ZQJsonManage_clear(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_clear'", nullptr);
            return 0;
        }
        cobj->clear(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_cache(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_cache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:cache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_cache'", nullptr);
            return 0;
        }
        bool ret = cobj->cache(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:cache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_cache'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_load_array(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_load_array'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:load_array");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_load_array'", nullptr);
            return 0;
        }
        const cocos2d::ValueVector& ret = cobj->load_array(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:load_array",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_load_array'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_text_dict(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_text_dict'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:text_dict");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_text_dict'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->text_dict(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:text_dict",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_text_dict'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_exist(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_exist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_exist'", nullptr);
            return 0;
        }
        bool ret = cobj->exist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:exist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_exist'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_load_dict(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_load_dict'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:load_dict");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_load_dict'", nullptr);
            return 0;
        }
        const cocos2d::ValueMap& ret = cobj->load_dict(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:load_dict",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_load_dict'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_text_array(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQJsonManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQJsonManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_text_array'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:text_array");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_text_array'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->text_array(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:text_array",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_text_array'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQJsonManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getInstance'", nullptr);
            return 0;
        }
        zq::ZQJsonManage* ret = zq::ZQJsonManage::getInstance();
        object_to_luaval<zq::ZQJsonManage>(tolua_S, "zq.ZQJsonManage",(zq::ZQJsonManage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQJsonManage:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQJsonManage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQJsonManage)");
    return 0;
}

int lua_register_zq_ZQJsonManage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQJsonManage");
    tolua_cclass(tolua_S,"ZQJsonManage","zq.ZQJsonManage","",nullptr);

    tolua_beginmodule(tolua_S,"ZQJsonManage");
        tolua_function(tolua_S,"clear",lua_zq_ZQJsonManage_clear);
        tolua_function(tolua_S,"cache",lua_zq_ZQJsonManage_cache);
        tolua_function(tolua_S,"load_array",lua_zq_ZQJsonManage_load_array);
        tolua_function(tolua_S,"text_dict",lua_zq_ZQJsonManage_text_dict);
        tolua_function(tolua_S,"exist",lua_zq_ZQJsonManage_exist);
        tolua_function(tolua_S,"load_dict",lua_zq_ZQJsonManage_load_dict);
        tolua_function(tolua_S,"text_array",lua_zq_ZQJsonManage_text_array);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQJsonManage_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQJsonManage).name();
    g_luaType[typeName] = "zq.ZQJsonManage";
    g_typeCast["ZQJsonManage"] = "zq.ZQJsonManage";
    return 1;
}

int lua_zq_ZQPlistManage_alias(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_alias'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Value arg0;
        std::string arg1;

        ok &= luaval_to_ccvalue(tolua_S, 2, &arg0, "zq.ZQPlistManage:alias");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQPlistManage:alias");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_alias'", nullptr);
            return 0;
        }
        cobj->alias(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:alias",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_alias'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_clear(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_clear'", nullptr);
            return 0;
        }
        cobj->clear(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_cache(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_cache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:cache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_cache'", nullptr);
            return 0;
        }
        bool ret = cobj->cache(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:cache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_cache'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_load_array(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_load_array'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:load_array");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_load_array'", nullptr);
            return 0;
        }
        const cocos2d::ValueVector& ret = cobj->load_array(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:load_array",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_load_array'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_read_text(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_read_text'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:read_text");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_read_text'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->read_text(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:read_text",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_read_text'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_text_dict(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_text_dict'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:text_dict");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_text_dict'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->text_dict(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:text_dict",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_text_dict'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_exist(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_exist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_exist'", nullptr);
            return 0;
        }
        bool ret = cobj->exist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:exist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_exist'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_load_dict(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_load_dict'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:load_dict");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_load_dict'", nullptr);
            return 0;
        }
        const cocos2d::ValueMap& ret = cobj->load_dict(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:load_dict",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_load_dict'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_read_file(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_read_file'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:read_file");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_read_file'", nullptr);
            return 0;
        }
        const cocos2d::Value& ret = cobj->read_file(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:read_file",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_read_file'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_text_array(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQPlistManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQPlistManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_text_array'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:text_array");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_text_array'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->text_array(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:text_array",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_text_array'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQPlistManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getInstance'", nullptr);
            return 0;
        }
        zq::ZQPlistManage* ret = zq::ZQPlistManage::getInstance();
        object_to_luaval<zq::ZQPlistManage>(tolua_S, "zq.ZQPlistManage",(zq::ZQPlistManage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQPlistManage:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQPlistManage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQPlistManage)");
    return 0;
}

int lua_register_zq_ZQPlistManage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQPlistManage");
    tolua_cclass(tolua_S,"ZQPlistManage","zq.ZQPlistManage","",nullptr);

    tolua_beginmodule(tolua_S,"ZQPlistManage");
        tolua_function(tolua_S,"alias",lua_zq_ZQPlistManage_alias);
        tolua_function(tolua_S,"clear",lua_zq_ZQPlistManage_clear);
        tolua_function(tolua_S,"cache",lua_zq_ZQPlistManage_cache);
        tolua_function(tolua_S,"load_array",lua_zq_ZQPlistManage_load_array);
        tolua_function(tolua_S,"read_text",lua_zq_ZQPlistManage_read_text);
        tolua_function(tolua_S,"text_dict",lua_zq_ZQPlistManage_text_dict);
        tolua_function(tolua_S,"exist",lua_zq_ZQPlistManage_exist);
        tolua_function(tolua_S,"load_dict",lua_zq_ZQPlistManage_load_dict);
        tolua_function(tolua_S,"read_file",lua_zq_ZQPlistManage_read_file);
        tolua_function(tolua_S,"text_array",lua_zq_ZQPlistManage_text_array);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQPlistManage_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQPlistManage).name();
    g_luaType[typeName] = "zq.ZQPlistManage";
    g_typeCast["ZQPlistManage"] = "zq.ZQPlistManage";
    return 1;
}

int lua_zq_ZQImageLoader_load_image(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageLoader_load_image'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:load_image");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_load_image'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->load_image(arg0);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:load_image");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQImageLoader:load_image");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_load_image'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->load_image(arg0, arg1);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageLoader:load_image",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageLoader_load_image'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageLoader_exist(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageLoader_exist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_exist'", nullptr);
            return 0;
        }
        bool ret = cobj->exist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:exist");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQImageLoader:exist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_exist'", nullptr);
            return 0;
        }
        bool ret = cobj->exist(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageLoader:exist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageLoader_exist'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageLoader_clear(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageLoader_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_clear'", nullptr);
            return 0;
        }
        cobj->clear(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:clear");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQImageLoader:clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_clear'", nullptr);
            return 0;
        }
        cobj->clear(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageLoader:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageLoader_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageLoader_cache(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageLoader_cache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:cache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_cache'", nullptr);
            return 0;
        }
        bool ret = cobj->cache(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageLoader:cache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageLoader_cache'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageLoader_load_frame(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageLoader_load_frame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageLoader:load_frame");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQImageLoader:load_frame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_load_frame'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->load_frame(arg0, arg1);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageLoader:load_frame",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageLoader_load_frame'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageLoader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQImageLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageLoader_getInstance'", nullptr);
            return 0;
        }
        zq::ZQImageLoader* ret = zq::ZQImageLoader::getInstance();
        object_to_luaval<zq::ZQImageLoader>(tolua_S, "zq.ZQImageLoader",(zq::ZQImageLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQImageLoader:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageLoader_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQImageLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQImageLoader)");
    return 0;
}

int lua_register_zq_ZQImageLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQImageLoader");
    tolua_cclass(tolua_S,"ZQImageLoader","zq.ZQImageLoader","",nullptr);

    tolua_beginmodule(tolua_S,"ZQImageLoader");
        tolua_function(tolua_S,"load_image",lua_zq_ZQImageLoader_load_image);
        tolua_function(tolua_S,"exist",lua_zq_ZQImageLoader_exist);
        tolua_function(tolua_S,"clear",lua_zq_ZQImageLoader_clear);
        tolua_function(tolua_S,"cache",lua_zq_ZQImageLoader_cache);
        tolua_function(tolua_S,"load_frame",lua_zq_ZQImageLoader_load_frame);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQImageLoader_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQImageLoader).name();
    g_luaType[typeName] = "zq.ZQImageLoader";
    g_typeCast["ZQImageLoader"] = "zq.ZQImageLoader";
    return 1;
}

int lua_zq_ZQCCBILoader_load(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQCCBILoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQCCBILoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQCCBILoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQCCBILoader_load'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQCCBILoader:load");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCCBILoader_load'", nullptr);
            return 0;
        }
        bool ret = cobj->load(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQCCBILoader:load");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.ZQCCBILoader:load");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCCBILoader_load'", nullptr);
            return 0;
        }
        bool ret = cobj->load(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQCCBILoader:load",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCCBILoader_load'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQCCBILoader_clear(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQCCBILoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQCCBILoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQCCBILoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQCCBILoader_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCCBILoader_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQCCBILoader:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCCBILoader_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQCCBILoader_readNodeGraphFromFile(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQCCBILoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQCCBILoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQCCBILoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQCCBILoader_readNodeGraphFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocosbuilder::CCBReader* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQCCBILoader:readNodeGraphFromFile");

        ok &= luaval_to_object<cocosbuilder::CCBReader>(tolua_S, 3, "cc.CCBReader",&arg1, "zq.ZQCCBILoader:readNodeGraphFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCCBILoader_readNodeGraphFromFile'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->readNodeGraphFromFile(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQCCBILoader:readNodeGraphFromFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCCBILoader_readNodeGraphFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQCCBILoader_createCCBReader(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQCCBILoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCCBILoader_createCCBReader'", nullptr);
            return 0;
        }
        cocosbuilder::CCBReader* ret = zq::ZQCCBILoader::createCCBReader();
        object_to_luaval<cocosbuilder::CCBReader>(tolua_S, "cc.CCBReader",(cocosbuilder::CCBReader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQCCBILoader:createCCBReader",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCCBILoader_createCCBReader'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQCCBILoader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQCCBILoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCCBILoader_getInstance'", nullptr);
            return 0;
        }
        zq::ZQCCBILoader* ret = zq::ZQCCBILoader::getInstance();
        object_to_luaval<zq::ZQCCBILoader>(tolua_S, "zq.ZQCCBILoader",(zq::ZQCCBILoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQCCBILoader:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCCBILoader_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQCCBILoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQCCBILoader)");
    return 0;
}

int lua_register_zq_ZQCCBILoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQCCBILoader");
    tolua_cclass(tolua_S,"ZQCCBILoader","zq.ZQCCBILoader","",nullptr);

    tolua_beginmodule(tolua_S,"ZQCCBILoader");
        tolua_function(tolua_S,"load",lua_zq_ZQCCBILoader_load);
        tolua_function(tolua_S,"clear",lua_zq_ZQCCBILoader_clear);
        tolua_function(tolua_S,"readNodeGraphFromFile",lua_zq_ZQCCBILoader_readNodeGraphFromFile);
        tolua_function(tolua_S,"createCCBReader", lua_zq_ZQCCBILoader_createCCBReader);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQCCBILoader_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQCCBILoader).name();
    g_luaType[typeName] = "zq.ZQCCBILoader";
    g_typeCast["ZQCCBILoader"] = "zq.ZQCCBILoader";
    return 1;
}

int lua_zq_ZQCustomAction_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQCustomAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQCustomAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQCustomAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQCustomAction_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQCustomAction:initWithDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCustomAction_initWithDuration'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithDuration(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQCustomAction:initWithDuration",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCustomAction_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQCustomAction_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQCustomAction",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCustomAction_create'", nullptr);
            return 0;
        }
        zq::ZQCustomAction* ret = zq::ZQCustomAction::create();
        object_to_luaval<zq::ZQCustomAction>(tolua_S, "zq.ZQCustomAction",(zq::ZQCustomAction*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQCustomAction:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCustomAction_create'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQCustomAction_constructor(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQCustomAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQCustomAction_constructor'", nullptr);
            return 0;
        }
        cobj = new zq::ZQCustomAction();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"zq.ZQCustomAction");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQCustomAction:ZQCustomAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQCustomAction_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_zq_ZQCustomAction_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQCustomAction)");
    return 0;
}

int lua_register_zq_ZQCustomAction(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQCustomAction");
    tolua_cclass(tolua_S,"ZQCustomAction","zq.ZQCustomAction","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"ZQCustomAction");
        tolua_function(tolua_S,"new",lua_zq_ZQCustomAction_constructor);
        tolua_function(tolua_S,"initWithDuration",lua_zq_ZQCustomAction_initWithDuration);
        tolua_function(tolua_S,"create", lua_zq_ZQCustomAction_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQCustomAction).name();
    g_luaType[typeName] = "zq.ZQCustomAction";
    g_typeCast["ZQCustomAction"] = "zq.ZQCustomAction";
    return 1;
}

int lua_zq_ZQTextUtil_standardFontName(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextUtil_standardFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_standardFontName'", nullptr);
            return 0;
        }
        std::string ret = cobj->standardFontName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextUtil:standardFontName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_standardFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextUtil_widthByFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextUtil_widthByFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextUtil:widthByFont");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQTextUtil:widthByFont");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "zq.ZQTextUtil:widthByFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_widthByFont'", nullptr);
            return 0;
        }
        double ret = cobj->widthByFont(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextUtil:widthByFont",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_widthByFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextUtil_sizeByFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextUtil_sizeByFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextUtil:sizeByFont");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQTextUtil:sizeByFont");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "zq.ZQTextUtil:sizeByFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_sizeByFont'", nullptr);
            return 0;
        }
        cocos2d::Size ret = cobj->sizeByFont(arg0, arg1, arg2);
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextUtil:sizeByFont",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_sizeByFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextUtil_renderByArray(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextUtil_renderByArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        cocos2d::Sprite* arg0;
        cocos2d::ValueVector arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "zq.ZQTextUtil:renderByArray");

        ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1, "zq.ZQTextUtil:renderByArray");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "zq.ZQTextUtil:renderByArray");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "zq.ZQTextUtil:renderByArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_renderByArray'", nullptr);
            return 0;
        }
        bool ret = cobj->renderByArray(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextUtil:renderByArray",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_renderByArray'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextUtil_heigthByFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextUtil_heigthByFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextUtil:heigthByFont");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQTextUtil:heigthByFont");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "zq.ZQTextUtil:heigthByFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_heigthByFont'", nullptr);
            return 0;
        }
        double ret = cobj->heigthByFont(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextUtil:heigthByFont",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_heigthByFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextUtil_renderByString(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextUtil_renderByString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        cocos2d::Sprite* arg0;
        std::string arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "zq.ZQTextUtil:renderByString");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQTextUtil:renderByString");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "zq.ZQTextUtil:renderByString");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "zq.ZQTextUtil:renderByString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_renderByString'", nullptr);
            return 0;
        }
        bool ret = cobj->renderByString(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextUtil:renderByString",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_renderByString'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextUtil_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQTextUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextUtil_getInstance'", nullptr);
            return 0;
        }
        zq::ZQTextUtil* ret = zq::ZQTextUtil::getInstance();
        object_to_luaval<zq::ZQTextUtil>(tolua_S, "zq.ZQTextUtil",(zq::ZQTextUtil*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQTextUtil:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextUtil_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQTextUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQTextUtil)");
    return 0;
}

int lua_register_zq_ZQTextUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQTextUtil");
    tolua_cclass(tolua_S,"ZQTextUtil","zq.ZQTextUtil","",nullptr);

    tolua_beginmodule(tolua_S,"ZQTextUtil");
        tolua_function(tolua_S,"standardFontName",lua_zq_ZQTextUtil_standardFontName);
        tolua_function(tolua_S,"widthByFont",lua_zq_ZQTextUtil_widthByFont);
        tolua_function(tolua_S,"sizeByFont",lua_zq_ZQTextUtil_sizeByFont);
        tolua_function(tolua_S,"renderByArray",lua_zq_ZQTextUtil_renderByArray);
        tolua_function(tolua_S,"heigthByFont",lua_zq_ZQTextUtil_heigthByFont);
        tolua_function(tolua_S,"renderByString",lua_zq_ZQTextUtil_renderByString);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQTextUtil_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQTextUtil).name();
    g_luaType[typeName] = "zq.ZQTextUtil";
    g_typeCast["ZQTextUtil"] = "zq.ZQTextUtil";
    return 1;
}

int lua_zq_ZQTextBox_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setAnchorPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "zq.ZQTextBox:setAnchorPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setAnchorPoint'", nullptr);
            return 0;
        }
        cobj->setAnchorPoint(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setAnchorPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setAnchorPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_getString(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_getString'", nullptr);
            return 0;
        }
        std::string ret = cobj->getString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_maxLength(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_maxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_maxLength'", nullptr);
            return 0;
        }
        int ret = cobj->maxLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:maxLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_maxLength'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_focus(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_focus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_focus'", nullptr);
            return 0;
        }
        cobj->focus();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:focus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_focus'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setScale(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextBox:setScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setScale'", nullptr);
            return 0;
        }
        cobj->setScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setScale'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setKeyboardEmail(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setKeyboardEmail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setKeyboardEmail'", nullptr);
            return 0;
        }
        cobj->setKeyboardEmail();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setKeyboardEmail",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setKeyboardEmail'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "zq.ZQTextBox:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setString(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextBox:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_openKeyboard(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_openKeyboard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_openKeyboard'", nullptr);
            return 0;
        }
        cobj->openKeyboard();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:openKeyboard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_openKeyboard'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setPlaceholderFontSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setPlaceholderFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextBox:setPlaceholderFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setPlaceholderFontSize'", nullptr);
            return 0;
        }
        cobj->setPlaceholderFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setPlaceholderFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setPlaceholderFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_keyboardWillShow(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_keyboardWillShow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::IMEKeyboardNotificationInfo arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR IMEKeyboardNotificationInfo
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_keyboardWillShow'", nullptr);
            return 0;
        }
        cobj->keyboardWillShow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:keyboardWillShow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_keyboardWillShow'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setPlaceholderFontColor(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setPlaceholderFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "zq.ZQTextBox:setPlaceholderFontColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setPlaceholderFontColor'", nullptr);
            return 0;
        }
        cobj->setPlaceholderFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setPlaceholderFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setPlaceholderFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setFontColor(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "zq.ZQTextBox:setFontColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setFontColor'", nullptr);
            return 0;
        }
        cobj->setFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_keyboardWillHide(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_keyboardWillHide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::IMEKeyboardNotificationInfo arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR IMEKeyboardNotificationInfo
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_keyboardWillHide'", nullptr);
            return 0;
        }
        cobj->keyboardWillHide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:keyboardWillHide",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_keyboardWillHide'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setScaleY(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextBox:setScaleY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setScaleY'", nullptr);
            return 0;
        }
        cobj->setScaleY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setScaleY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setScaleX(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextBox:setScaleX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setScaleX'", nullptr);
            return 0;
        }
        cobj->setScaleX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setScaleX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setAlignmentRight(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setAlignmentRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setAlignmentRight'", nullptr);
            return 0;
        }
        cobj->setAlignmentRight();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setAlignmentRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setAlignmentRight'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_update(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_update'", nullptr);
            return 0;
        }
        cobj->update();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:update",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_update'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setAlignmentCenter(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setAlignmentCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setAlignmentCenter'", nullptr);
            return 0;
        }
        cobj->setAlignmentCenter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setAlignmentCenter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setAlignmentCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setAlignmentLeft(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setAlignmentLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setAlignmentLeft'", nullptr);
            return 0;
        }
        cobj->setAlignmentLeft();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setAlignmentLeft",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setAlignmentLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setPlaceholderFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setPlaceholderFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextBox:setPlaceholderFont");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "zq.ZQTextBox:setPlaceholderFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setPlaceholderFont'", nullptr);
            return 0;
        }
        cobj->setPlaceholderFont(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setPlaceholderFont",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setPlaceholderFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextBox:setFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setFontSize'", nullptr);
            return 0;
        }
        cobj->setFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setPlaceHolder(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setPlaceHolder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextBox:setPlaceHolder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setPlaceHolder'", nullptr);
            return 0;
        }
        cobj->setPlaceHolder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setPlaceHolder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setPlaceHolder'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "zq.ZQTextBox:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setKeyboardDefault(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setKeyboardDefault'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setKeyboardDefault'", nullptr);
            return 0;
        }
        cobj->setKeyboardDefault();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setKeyboardDefault",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setKeyboardDefault'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setKeyboardNumber(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setKeyboardNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setKeyboardNumber'", nullptr);
            return 0;
        }
        cobj->setKeyboardNumber();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setKeyboardNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setKeyboardNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setMaxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "zq.ZQTextBox:setMaxLength");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setMaxLength'", nullptr);
            return 0;
        }
        cobj->setMaxLength(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setMaxLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setMaxLength'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextBox:setFont");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "zq.ZQTextBox:setFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setFont'", nullptr);
            return 0;
        }
        cobj->setFont(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setFont",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_setKeyboardURL(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextBox_setKeyboardURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_setKeyboardURL'", nullptr);
            return 0;
        }
        cobj->setKeyboardURL();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextBox:setKeyboardURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_setKeyboardURL'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextBox_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQTextBox",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0, "zq.ZQTextBox:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextBox_create'", nullptr);
            return 0;
        }
        zq::ZQTextBox* ret = zq::ZQTextBox::create(arg0);
        object_to_luaval<zq::ZQTextBox>(tolua_S, "zq.ZQTextBox",(zq::ZQTextBox*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQTextBox:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextBox_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQTextBox_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQTextBox)");
    return 0;
}

int lua_register_zq_ZQTextBox(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQTextBox");
    tolua_cclass(tolua_S,"ZQTextBox","zq.ZQTextBox","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ZQTextBox");
        tolua_function(tolua_S,"setAnchorPoint",lua_zq_ZQTextBox_setAnchorPoint);
        tolua_function(tolua_S,"onEnter",lua_zq_ZQTextBox_onEnter);
        tolua_function(tolua_S,"getString",lua_zq_ZQTextBox_getString);
        tolua_function(tolua_S,"maxLength",lua_zq_ZQTextBox_maxLength);
        tolua_function(tolua_S,"focus",lua_zq_ZQTextBox_focus);
        tolua_function(tolua_S,"setScale",lua_zq_ZQTextBox_setScale);
        tolua_function(tolua_S,"setKeyboardEmail",lua_zq_ZQTextBox_setKeyboardEmail);
        tolua_function(tolua_S,"setContentSize",lua_zq_ZQTextBox_setContentSize);
        tolua_function(tolua_S,"setString",lua_zq_ZQTextBox_setString);
        tolua_function(tolua_S,"openKeyboard",lua_zq_ZQTextBox_openKeyboard);
        tolua_function(tolua_S,"setPlaceholderFontSize",lua_zq_ZQTextBox_setPlaceholderFontSize);
        tolua_function(tolua_S,"keyboardWillShow",lua_zq_ZQTextBox_keyboardWillShow);
        tolua_function(tolua_S,"setPlaceholderFontColor",lua_zq_ZQTextBox_setPlaceholderFontColor);
        tolua_function(tolua_S,"setFontColor",lua_zq_ZQTextBox_setFontColor);
        tolua_function(tolua_S,"keyboardWillHide",lua_zq_ZQTextBox_keyboardWillHide);
        tolua_function(tolua_S,"setScaleY",lua_zq_ZQTextBox_setScaleY);
        tolua_function(tolua_S,"setScaleX",lua_zq_ZQTextBox_setScaleX);
        tolua_function(tolua_S,"setAlignmentRight",lua_zq_ZQTextBox_setAlignmentRight);
        tolua_function(tolua_S,"update",lua_zq_ZQTextBox_update);
        tolua_function(tolua_S,"setAlignmentCenter",lua_zq_ZQTextBox_setAlignmentCenter);
        tolua_function(tolua_S,"setAlignmentLeft",lua_zq_ZQTextBox_setAlignmentLeft);
        tolua_function(tolua_S,"setPlaceholderFont",lua_zq_ZQTextBox_setPlaceholderFont);
        tolua_function(tolua_S,"setFontSize",lua_zq_ZQTextBox_setFontSize);
        tolua_function(tolua_S,"setPlaceHolder",lua_zq_ZQTextBox_setPlaceHolder);
        tolua_function(tolua_S,"setPosition",lua_zq_ZQTextBox_setPosition);
        tolua_function(tolua_S,"setKeyboardDefault",lua_zq_ZQTextBox_setKeyboardDefault);
        tolua_function(tolua_S,"setKeyboardNumber",lua_zq_ZQTextBox_setKeyboardNumber);
        tolua_function(tolua_S,"setMaxLength",lua_zq_ZQTextBox_setMaxLength);
        tolua_function(tolua_S,"setFont",lua_zq_ZQTextBox_setFont);
        tolua_function(tolua_S,"setKeyboardURL",lua_zq_ZQTextBox_setKeyboardURL);
        tolua_function(tolua_S,"create", lua_zq_ZQTextBox_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQTextBox).name();
    g_luaType[typeName] = "zq.ZQTextBox";
    g_typeCast["ZQTextBox"] = "zq.ZQTextBox";
    return 1;
}

int lua_zq_ZQTextArea_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setAnchorPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "zq.ZQTextArea:setAnchorPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setAnchorPoint'", nullptr);
            return 0;
        }
        cobj->setAnchorPoint(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setAnchorPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setAnchorPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_getString(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_getString'", nullptr);
            return 0;
        }
        std::string ret = cobj->getString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_maxLength(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_maxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_maxLength'", nullptr);
            return 0;
        }
        int ret = cobj->maxLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:maxLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_maxLength'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_focus(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_focus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_focus'", nullptr);
            return 0;
        }
        cobj->focus();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:focus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_focus'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setScale(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextArea:setScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setScale'", nullptr);
            return 0;
        }
        cobj->setScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setScale'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setKeyboardEmail(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setKeyboardEmail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setKeyboardEmail'", nullptr);
            return 0;
        }
        cobj->setKeyboardEmail();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setKeyboardEmail",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setKeyboardEmail'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "zq.ZQTextArea:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setString(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextArea:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_openKeyboard(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_openKeyboard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_openKeyboard'", nullptr);
            return 0;
        }
        cobj->openKeyboard();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:openKeyboard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_openKeyboard'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setPlaceholderFontSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setPlaceholderFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextArea:setPlaceholderFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setPlaceholderFontSize'", nullptr);
            return 0;
        }
        cobj->setPlaceholderFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setPlaceholderFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setPlaceholderFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_keyboardWillShow(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_keyboardWillShow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::IMEKeyboardNotificationInfo arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR IMEKeyboardNotificationInfo
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_keyboardWillShow'", nullptr);
            return 0;
        }
        cobj->keyboardWillShow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:keyboardWillShow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_keyboardWillShow'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setPlaceholderFontColor(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setPlaceholderFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "zq.ZQTextArea:setPlaceholderFontColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setPlaceholderFontColor'", nullptr);
            return 0;
        }
        cobj->setPlaceholderFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setPlaceholderFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setPlaceholderFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setFontColor(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "zq.ZQTextArea:setFontColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setFontColor'", nullptr);
            return 0;
        }
        cobj->setFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_keyboardWillHide(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_keyboardWillHide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::IMEKeyboardNotificationInfo arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR IMEKeyboardNotificationInfo
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_keyboardWillHide'", nullptr);
            return 0;
        }
        cobj->keyboardWillHide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:keyboardWillHide",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_keyboardWillHide'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setScaleY(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextArea:setScaleY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setScaleY'", nullptr);
            return 0;
        }
        cobj->setScaleY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setScaleY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setScaleX(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextArea:setScaleX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setScaleX'", nullptr);
            return 0;
        }
        cobj->setScaleX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setScaleX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setAlignmentRight(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setAlignmentRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setAlignmentRight'", nullptr);
            return 0;
        }
        cobj->setAlignmentRight();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setAlignmentRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setAlignmentRight'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_update(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_update'", nullptr);
            return 0;
        }
        cobj->update();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:update",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_update'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setAlignmentCenter(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setAlignmentCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setAlignmentCenter'", nullptr);
            return 0;
        }
        cobj->setAlignmentCenter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setAlignmentCenter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setAlignmentCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setAlignmentLeft(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setAlignmentLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setAlignmentLeft'", nullptr);
            return 0;
        }
        cobj->setAlignmentLeft();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setAlignmentLeft",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setAlignmentLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setPlaceholderFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setPlaceholderFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextArea:setPlaceholderFont");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "zq.ZQTextArea:setPlaceholderFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setPlaceholderFont'", nullptr);
            return 0;
        }
        cobj->setPlaceholderFont(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setPlaceholderFont",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setPlaceholderFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "zq.ZQTextArea:setFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setFontSize'", nullptr);
            return 0;
        }
        cobj->setFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setPlaceHolder(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setPlaceHolder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextArea:setPlaceHolder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setPlaceHolder'", nullptr);
            return 0;
        }
        cobj->setPlaceHolder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setPlaceHolder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setPlaceHolder'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "zq.ZQTextArea:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setKeyboardDefault(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setKeyboardDefault'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setKeyboardDefault'", nullptr);
            return 0;
        }
        cobj->setKeyboardDefault();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setKeyboardDefault",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setKeyboardDefault'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setKeyboardNumber(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setKeyboardNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setKeyboardNumber'", nullptr);
            return 0;
        }
        cobj->setKeyboardNumber();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setKeyboardNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setKeyboardNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setMaxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "zq.ZQTextArea:setMaxLength");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setMaxLength'", nullptr);
            return 0;
        }
        cobj->setMaxLength(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setMaxLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setMaxLength'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setFont(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setFont'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQTextArea:setFont");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "zq.ZQTextArea:setFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setFont'", nullptr);
            return 0;
        }
        cobj->setFont(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setFont",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setFont'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_setKeyboardURL(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQTextArea* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQTextArea*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQTextArea_setKeyboardURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_setKeyboardURL'", nullptr);
            return 0;
        }
        cobj->setKeyboardURL();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQTextArea:setKeyboardURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_setKeyboardURL'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQTextArea_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQTextArea",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0, "zq.ZQTextArea:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQTextArea_create'", nullptr);
            return 0;
        }
        zq::ZQTextArea* ret = zq::ZQTextArea::create(arg0);
        object_to_luaval<zq::ZQTextArea>(tolua_S, "zq.ZQTextArea",(zq::ZQTextArea*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQTextArea:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQTextArea_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQTextArea_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQTextArea)");
    return 0;
}

int lua_register_zq_ZQTextArea(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQTextArea");
    tolua_cclass(tolua_S,"ZQTextArea","zq.ZQTextArea","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ZQTextArea");
        tolua_function(tolua_S,"setAnchorPoint",lua_zq_ZQTextArea_setAnchorPoint);
        tolua_function(tolua_S,"onEnter",lua_zq_ZQTextArea_onEnter);
        tolua_function(tolua_S,"getString",lua_zq_ZQTextArea_getString);
        tolua_function(tolua_S,"maxLength",lua_zq_ZQTextArea_maxLength);
        tolua_function(tolua_S,"focus",lua_zq_ZQTextArea_focus);
        tolua_function(tolua_S,"setScale",lua_zq_ZQTextArea_setScale);
        tolua_function(tolua_S,"setKeyboardEmail",lua_zq_ZQTextArea_setKeyboardEmail);
        tolua_function(tolua_S,"setContentSize",lua_zq_ZQTextArea_setContentSize);
        tolua_function(tolua_S,"setString",lua_zq_ZQTextArea_setString);
        tolua_function(tolua_S,"openKeyboard",lua_zq_ZQTextArea_openKeyboard);
        tolua_function(tolua_S,"setPlaceholderFontSize",lua_zq_ZQTextArea_setPlaceholderFontSize);
        tolua_function(tolua_S,"keyboardWillShow",lua_zq_ZQTextArea_keyboardWillShow);
        tolua_function(tolua_S,"setPlaceholderFontColor",lua_zq_ZQTextArea_setPlaceholderFontColor);
        tolua_function(tolua_S,"setFontColor",lua_zq_ZQTextArea_setFontColor);
        tolua_function(tolua_S,"keyboardWillHide",lua_zq_ZQTextArea_keyboardWillHide);
        tolua_function(tolua_S,"setScaleY",lua_zq_ZQTextArea_setScaleY);
        tolua_function(tolua_S,"setScaleX",lua_zq_ZQTextArea_setScaleX);
        tolua_function(tolua_S,"setAlignmentRight",lua_zq_ZQTextArea_setAlignmentRight);
        tolua_function(tolua_S,"update",lua_zq_ZQTextArea_update);
        tolua_function(tolua_S,"setAlignmentCenter",lua_zq_ZQTextArea_setAlignmentCenter);
        tolua_function(tolua_S,"setAlignmentLeft",lua_zq_ZQTextArea_setAlignmentLeft);
        tolua_function(tolua_S,"setPlaceholderFont",lua_zq_ZQTextArea_setPlaceholderFont);
        tolua_function(tolua_S,"setFontSize",lua_zq_ZQTextArea_setFontSize);
        tolua_function(tolua_S,"setPlaceHolder",lua_zq_ZQTextArea_setPlaceHolder);
        tolua_function(tolua_S,"setPosition",lua_zq_ZQTextArea_setPosition);
        tolua_function(tolua_S,"setKeyboardDefault",lua_zq_ZQTextArea_setKeyboardDefault);
        tolua_function(tolua_S,"setKeyboardNumber",lua_zq_ZQTextArea_setKeyboardNumber);
        tolua_function(tolua_S,"setMaxLength",lua_zq_ZQTextArea_setMaxLength);
        tolua_function(tolua_S,"setFont",lua_zq_ZQTextArea_setFont);
        tolua_function(tolua_S,"setKeyboardURL",lua_zq_ZQTextArea_setKeyboardURL);
        tolua_function(tolua_S,"create", lua_zq_ZQTextArea_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQTextArea).name();
    g_luaType[typeName] = "zq.ZQTextArea";
    g_typeCast["ZQTextArea"] = "zq.ZQTextArea";
    return 1;
}

int lua_zq_ZQScriptHandler_valid(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQScriptHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQScriptHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQScriptHandler*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQScriptHandler_valid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQScriptHandler_valid'", nullptr);
            return 0;
        }
        bool ret = cobj->valid();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQScriptHandler:valid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQScriptHandler_valid'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQScriptHandler_constructor(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQScriptHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQScriptHandler_constructor'", nullptr);
            return 0;
        }
        cobj = new zq::ZQScriptHandler();
        tolua_pushusertype(tolua_S,(void*)cobj,"zq.ZQScriptHandler");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQScriptHandler:ZQScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQScriptHandler_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_zq_ZQScriptHandler_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQScriptHandler)");
    return 0;
}

int lua_register_zq_ZQScriptHandler(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQScriptHandler");
    tolua_cclass(tolua_S,"ZQScriptHandler","zq.ZQScriptHandler","",nullptr);

    tolua_beginmodule(tolua_S,"ZQScriptHandler");
        tolua_function(tolua_S,"new",lua_zq_ZQScriptHandler_constructor);
        tolua_function(tolua_S,"valid",lua_zq_ZQScriptHandler_valid);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQScriptHandler).name();
    g_luaType[typeName] = "zq.ZQScriptHandler";
    g_typeCast["ZQScriptHandler"] = "zq.ZQScriptHandler";
    return 1;
}

int lua_zq_ZQAppEvent_androidShouldReset(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppEvent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppEvent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppEvent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppEvent_androidShouldReset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppEvent_androidShouldReset'", nullptr);
            return 0;
        }
        cobj->androidShouldReset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppEvent:androidShouldReset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppEvent_androidShouldReset'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppEvent_applicationDidEnterBackground(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppEvent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppEvent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppEvent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppEvent_applicationDidEnterBackground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppEvent_applicationDidEnterBackground'", nullptr);
            return 0;
        }
        cobj->applicationDidEnterBackground();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppEvent:applicationDidEnterBackground",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppEvent_applicationDidEnterBackground'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppEvent_applicationWillEnterForeground(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppEvent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppEvent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppEvent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppEvent_applicationWillEnterForeground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppEvent_applicationWillEnterForeground'", nullptr);
            return 0;
        }
        cobj->applicationWillEnterForeground();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppEvent:applicationWillEnterForeground",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppEvent_applicationWillEnterForeground'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppEvent_applicationDidFinishLaunching(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppEvent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppEvent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppEvent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppEvent_applicationDidFinishLaunching'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppEvent_applicationDidFinishLaunching'", nullptr);
            return 0;
        }
        cobj->applicationDidFinishLaunching();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppEvent:applicationDidFinishLaunching",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppEvent_applicationDidFinishLaunching'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppEvent_applicationDidReceiveMemoryWarning(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppEvent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppEvent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppEvent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppEvent_applicationDidReceiveMemoryWarning'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppEvent_applicationDidReceiveMemoryWarning'", nullptr);
            return 0;
        }
        cobj->applicationDidReceiveMemoryWarning();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppEvent:applicationDidReceiveMemoryWarning",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppEvent_applicationDidReceiveMemoryWarning'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppEvent_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQAppEvent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppEvent_getInstance'", nullptr);
            return 0;
        }
        zq::ZQAppEvent* ret = zq::ZQAppEvent::getInstance();
        object_to_luaval<zq::ZQAppEvent>(tolua_S, "zq.ZQAppEvent",(zq::ZQAppEvent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQAppEvent:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppEvent_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQAppEvent_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQAppEvent)");
    return 0;
}

int lua_register_zq_ZQAppEvent(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQAppEvent");
    tolua_cclass(tolua_S,"ZQAppEvent","zq.ZQAppEvent","zq.ZQScriptHandler",nullptr);

    tolua_beginmodule(tolua_S,"ZQAppEvent");
        tolua_function(tolua_S,"androidShouldReset",lua_zq_ZQAppEvent_androidShouldReset);
        tolua_function(tolua_S,"applicationDidEnterBackground",lua_zq_ZQAppEvent_applicationDidEnterBackground);
        tolua_function(tolua_S,"applicationWillEnterForeground",lua_zq_ZQAppEvent_applicationWillEnterForeground);
        tolua_function(tolua_S,"applicationDidFinishLaunching",lua_zq_ZQAppEvent_applicationDidFinishLaunching);
        tolua_function(tolua_S,"applicationDidReceiveMemoryWarning",lua_zq_ZQAppEvent_applicationDidReceiveMemoryWarning);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQAppEvent_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQAppEvent).name();
    g_luaType[typeName] = "zq.ZQAppEvent";
    g_typeCast["ZQAppEvent"] = "zq.ZQAppEvent";
    return 1;
}

int lua_zq_ZQAppCenter_isRestart(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppCenter_isRestart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppCenter_isRestart'", nullptr);
            return 0;
        }
        bool ret = cobj->isRestart();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppCenter:isRestart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppCenter_isRestart'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppCenter_start(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppCenter_start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppCenter_start'", nullptr);
            return 0;
        }
        cobj->start();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppCenter:start",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppCenter_start'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppCenter_restart(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppCenter_restart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppCenter_restart'", nullptr);
            return 0;
        }
        cobj->restart();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppCenter:restart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppCenter_restart'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppCenter_quit(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQAppCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQAppCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQAppCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQAppCenter_quit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppCenter_quit'", nullptr);
            return 0;
        }
        cobj->quit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQAppCenter:quit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppCenter_quit'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQAppCenter_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQAppCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQAppCenter_getInstance'", nullptr);
            return 0;
        }
        zq::ZQAppCenter* ret = zq::ZQAppCenter::getInstance();
        object_to_luaval<zq::ZQAppCenter>(tolua_S, "zq.ZQAppCenter",(zq::ZQAppCenter*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQAppCenter:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQAppCenter_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQAppCenter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQAppCenter)");
    return 0;
}

int lua_register_zq_ZQAppCenter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQAppCenter");
    tolua_cclass(tolua_S,"ZQAppCenter","zq.ZQAppCenter","",nullptr);

    tolua_beginmodule(tolua_S,"ZQAppCenter");
        tolua_function(tolua_S,"isRestart",lua_zq_ZQAppCenter_isRestart);
        tolua_function(tolua_S,"start",lua_zq_ZQAppCenter_start);
        tolua_function(tolua_S,"restart",lua_zq_ZQAppCenter_restart);
        tolua_function(tolua_S,"quit",lua_zq_ZQAppCenter_quit);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQAppCenter_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQAppCenter).name();
    g_luaType[typeName] = "zq.ZQAppCenter";
    g_typeCast["ZQAppCenter"] = "zq.ZQAppCenter";
    return 1;
}

int lua_zq_Locale_setup(lua_State* tolua_S)
{
    int argc = 0;
    zq::Locale* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.Locale",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::Locale*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_Locale_setup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.Locale:setup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_Locale_setup'", nullptr);
            return 0;
        }
        cobj->setup(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.Locale:setup");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "zq.Locale:setup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_Locale_setup'", nullptr);
            return 0;
        }
        cobj->setup(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.Locale:setup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_Locale_setup'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_Locale_translate(lua_State* tolua_S)
{
    int argc = 0;
    zq::Locale* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.Locale",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::Locale*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_Locale_translate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.Locale:translate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_Locale_translate'", nullptr);
            return 0;
        }
        std::string ret = cobj->translate(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.Locale:translate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_Locale_translate'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_Locale_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.Locale",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_Locale_getInstance'", nullptr);
            return 0;
        }
        zq::Locale* ret = zq::Locale::getInstance();
        object_to_luaval<zq::Locale>(tolua_S, "zq.Locale",(zq::Locale*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.Locale:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_Locale_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_Locale_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Locale)");
    return 0;
}

int lua_register_zq_Locale(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.Locale");
    tolua_cclass(tolua_S,"Locale","zq.Locale","",nullptr);

    tolua_beginmodule(tolua_S,"Locale");
        tolua_function(tolua_S,"setup",lua_zq_Locale_setup);
        tolua_function(tolua_S,"translate",lua_zq_Locale_translate);
        tolua_function(tolua_S,"getInstance", lua_zq_Locale_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::Locale).name();
    g_luaType[typeName] = "zq.Locale";
    g_typeCast["Locale"] = "zq.Locale";
    return 1;
}

int lua_zq_ZQDeviceInfo_cpu_usage(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_cpu_usage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_cpu_usage'", nullptr);
            return 0;
        }
        double ret = cobj->cpu_usage();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:cpu_usage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_cpu_usage'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_device_uuid(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_device_uuid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_device_uuid'", nullptr);
            return 0;
        }
        std::string ret = cobj->device_uuid();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:device_uuid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_device_uuid'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_os_is_android(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_os_is_android'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_os_is_android'", nullptr);
            return 0;
        }
        bool ret = cobj->os_is_android();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:os_is_android",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_os_is_android'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_memory_all(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_memory_all'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_memory_all'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->memory_all();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:memory_all",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_memory_all'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_version_cpp(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_version_cpp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_version_cpp'", nullptr);
            return 0;
        }
        int ret = cobj->version_cpp();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:version_cpp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_version_cpp'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_os_is_ios(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_os_is_ios'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_os_is_ios'", nullptr);
            return 0;
        }
        bool ret = cobj->os_is_ios();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:os_is_ios",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_os_is_ios'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_device_network(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_device_network'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_device_network'", nullptr);
            return 0;
        }
        std::string ret = cobj->device_network();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:device_network",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_device_network'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_cpu_core(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_cpu_core'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_cpu_core'", nullptr);
            return 0;
        }
        int ret = cobj->cpu_core();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:cpu_core",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_cpu_core'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_bundle_id(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_bundle_id'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_bundle_id'", nullptr);
            return 0;
        }
        std::string ret = cobj->bundle_id();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:bundle_id",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_bundle_id'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_device_hardware(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_device_hardware'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_device_hardware'", nullptr);
            return 0;
        }
        std::string ret = cobj->device_hardware();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:device_hardware",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_device_hardware'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_uuid(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_uuid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_uuid'", nullptr);
            return 0;
        }
        std::string ret = cobj->uuid();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:uuid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_uuid'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_vibrate(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_vibrate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_vibrate'", nullptr);
            return 0;
        }
        cobj->vibrate();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:vibrate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_vibrate'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_clipboard(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_clipboard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQDeviceInfo:clipboard");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_clipboard'", nullptr);
            return 0;
        }
        cobj->clipboard(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:clipboard",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_clipboard'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_bundle_name(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_bundle_name'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_bundle_name'", nullptr);
            return 0;
        }
        std::string ret = cobj->bundle_name();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:bundle_name",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_bundle_name'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_memory_used(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_memory_used'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_memory_used'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->memory_used();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:memory_used",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_memory_used'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_memory_free(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_memory_free'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_memory_free'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->memory_free();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:memory_free",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_memory_free'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_os_is_mobile(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_os_is_mobile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_os_is_mobile'", nullptr);
            return 0;
        }
        bool ret = cobj->os_is_mobile();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:os_is_mobile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_os_is_mobile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_browser_useragent(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_browser_useragent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_browser_useragent'", nullptr);
            return 0;
        }
        std::string ret = cobj->browser_useragent();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:browser_useragent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_browser_useragent'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_keyboard_exist(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_keyboard_exist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_keyboard_exist'", nullptr);
            return 0;
        }
        bool ret = cobj->keyboard_exist();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:keyboard_exist",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_keyboard_exist'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_device_telecom(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_device_telecom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_device_telecom'", nullptr);
            return 0;
        }
        std::string ret = cobj->device_telecom();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:device_telecom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_device_telecom'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_os_is_mac(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_os_is_mac'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_os_is_mac'", nullptr);
            return 0;
        }
        bool ret = cobj->os_is_mac();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:os_is_mac",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_os_is_mac'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_open_browser(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_open_browser'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQDeviceInfo:open_browser");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_open_browser'", nullptr);
            return 0;
        }
        bool ret = cobj->open_browser(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:open_browser",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_open_browser'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_quit_game(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_quit_game'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_quit_game'", nullptr);
            return 0;
        }
        cobj->quit_game();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:quit_game",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_quit_game'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_keyboard_close(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_keyboard_close'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_keyboard_close'", nullptr);
            return 0;
        }
        cobj->keyboard_close();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:keyboard_close",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_keyboard_close'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_device_os_version(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_device_os_version'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_device_os_version'", nullptr);
            return 0;
        }
        std::string ret = cobj->device_os_version();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:device_os_version",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_device_os_version'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_version_short(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_version_short'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_version_short'", nullptr);
            return 0;
        }
        std::string ret = cobj->version_short();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:version_short",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_version_short'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_keep_awake(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQDeviceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQDeviceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQDeviceInfo_keep_awake'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "zq.ZQDeviceInfo:keep_awake");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_keep_awake'", nullptr);
            return 0;
        }
        cobj->keep_awake(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQDeviceInfo:keep_awake",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_keep_awake'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQDeviceInfo_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQDeviceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQDeviceInfo_getInstance'", nullptr);
            return 0;
        }
        zq::ZQDeviceInfo* ret = zq::ZQDeviceInfo::getInstance();
        object_to_luaval<zq::ZQDeviceInfo>(tolua_S, "zq.ZQDeviceInfo",(zq::ZQDeviceInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQDeviceInfo:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQDeviceInfo_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQDeviceInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQDeviceInfo)");
    return 0;
}

int lua_register_zq_ZQDeviceInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQDeviceInfo");
    tolua_cclass(tolua_S,"ZQDeviceInfo","zq.ZQDeviceInfo","",nullptr);

    tolua_beginmodule(tolua_S,"ZQDeviceInfo");
        tolua_function(tolua_S,"cpu_usage",lua_zq_ZQDeviceInfo_cpu_usage);
        tolua_function(tolua_S,"device_uuid",lua_zq_ZQDeviceInfo_device_uuid);
        tolua_function(tolua_S,"os_is_android",lua_zq_ZQDeviceInfo_os_is_android);
        tolua_function(tolua_S,"memory_all",lua_zq_ZQDeviceInfo_memory_all);
        tolua_function(tolua_S,"version_cpp",lua_zq_ZQDeviceInfo_version_cpp);
        tolua_function(tolua_S,"os_is_ios",lua_zq_ZQDeviceInfo_os_is_ios);
        tolua_function(tolua_S,"device_network",lua_zq_ZQDeviceInfo_device_network);
        tolua_function(tolua_S,"cpu_core",lua_zq_ZQDeviceInfo_cpu_core);
        tolua_function(tolua_S,"bundle_id",lua_zq_ZQDeviceInfo_bundle_id);
        tolua_function(tolua_S,"device_hardware",lua_zq_ZQDeviceInfo_device_hardware);
        tolua_function(tolua_S,"uuid",lua_zq_ZQDeviceInfo_uuid);
        tolua_function(tolua_S,"vibrate",lua_zq_ZQDeviceInfo_vibrate);
        tolua_function(tolua_S,"clipboard",lua_zq_ZQDeviceInfo_clipboard);
        tolua_function(tolua_S,"bundle_name",lua_zq_ZQDeviceInfo_bundle_name);
        tolua_function(tolua_S,"memory_used",lua_zq_ZQDeviceInfo_memory_used);
        tolua_function(tolua_S,"memory_free",lua_zq_ZQDeviceInfo_memory_free);
        tolua_function(tolua_S,"os_is_mobile",lua_zq_ZQDeviceInfo_os_is_mobile);
        tolua_function(tolua_S,"browser_useragent",lua_zq_ZQDeviceInfo_browser_useragent);
        tolua_function(tolua_S,"keyboard_exist",lua_zq_ZQDeviceInfo_keyboard_exist);
        tolua_function(tolua_S,"device_telecom",lua_zq_ZQDeviceInfo_device_telecom);
        tolua_function(tolua_S,"os_is_mac",lua_zq_ZQDeviceInfo_os_is_mac);
        tolua_function(tolua_S,"open_browser",lua_zq_ZQDeviceInfo_open_browser);
        tolua_function(tolua_S,"quit_game",lua_zq_ZQDeviceInfo_quit_game);
        tolua_function(tolua_S,"keyboard_close",lua_zq_ZQDeviceInfo_keyboard_close);
        tolua_function(tolua_S,"device_os_version",lua_zq_ZQDeviceInfo_device_os_version);
        tolua_function(tolua_S,"version_short",lua_zq_ZQDeviceInfo_version_short);
        tolua_function(tolua_S,"keep_awake",lua_zq_ZQDeviceInfo_keep_awake);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQDeviceInfo_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQDeviceInfo).name();
    g_luaType[typeName] = "zq.ZQDeviceInfo";
    g_typeCast["ZQDeviceInfo"] = "zq.ZQDeviceInfo";
    return 1;
}
TOLUA_API int register_all_zq(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"zq",0);
	tolua_beginmodule(tolua_S,"zq");

	lua_register_zq_DateUtils(tolua_S);
	lua_register_zq_ZQAppCenter(tolua_S);
	lua_register_zq_ZQTextBox(tolua_S);
	lua_register_zq_ZQJsonManage(tolua_S);
	lua_register_zq_ZQLogger(tolua_S);
	lua_register_zq_ZQFileManage(tolua_S);
	lua_register_zq_ZQCustomAction(tolua_S);
	lua_register_zq_ZQScriptHandler(tolua_S);
	lua_register_zq_ZQAppEvent(tolua_S);
	lua_register_zq_ZQCCBILoader(tolua_S);
	lua_register_zq_ZQDeviceInfo(tolua_S);
	lua_register_zq_Locale(tolua_S);
	lua_register_zq_ZQTextArea(tolua_S);
	lua_register_zq_ZQImageLoader(tolua_S);
	lua_register_zq_ZQTextUtil(tolua_S);
	lua_register_zq_ZQPlistManage(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

