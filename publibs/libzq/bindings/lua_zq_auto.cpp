#include "lua_zq_auto.hpp"
#include "ZQLibExt.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

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
int lua_zq_ZQFileManage_getFileExtension(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_getFileExtension'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:getFileExtension");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getFileExtension'", nullptr);
            return 0;
        }
        std::string ret = cobj->getFileExtension(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:getFileExtension",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getFileExtension'.",&tolua_err);
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
int lua_zq_ZQFileManage_logDir(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_logDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_logDir'", nullptr);
            return 0;
        }
        std::string ret = cobj->logDir();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:logDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_logDir'.",&tolua_err);
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
int lua_zq_ZQFileManage_tempDir(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQFileManage_tempDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_tempDir'", nullptr);
            return 0;
        }
        std::string ret = cobj->tempDir();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQFileManage:tempDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_tempDir'.",&tolua_err);
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
int lua_zq_ZQFileManage_getFileBaseName(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:getFileBaseName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getFileBaseName'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::getFileBaseName(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:getFileBaseName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getFileBaseName'.",&tolua_err);
#endif
    return 0;
}
int lua_zq_ZQFileManage_getDirPath(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQFileManage:getDirPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQFileManage_getDirPath'", nullptr);
            return 0;
        }
        std::string ret = zq::ZQFileManage::getDirPath(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQFileManage:getDirPath",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQFileManage_getDirPath'.",&tolua_err);
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
        tolua_function(tolua_S,"renameFile",lua_zq_ZQFileManage_renameFile);
        tolua_function(tolua_S,"getStringFromFile",lua_zq_ZQFileManage_getStringFromFile);
        tolua_function(tolua_S,"getFileExtension",lua_zq_ZQFileManage_getFileExtension);
        tolua_function(tolua_S,"getFileSize",lua_zq_ZQFileManage_getFileSize);
        tolua_function(tolua_S,"removeFile",lua_zq_ZQFileManage_removeFile);
        tolua_function(tolua_S,"logDir",lua_zq_ZQFileManage_logDir);
        tolua_function(tolua_S,"removeDirectory",lua_zq_ZQFileManage_removeDirectory);
        tolua_function(tolua_S,"tempDir",lua_zq_ZQFileManage_tempDir);
        tolua_function(tolua_S,"addSearchPath",lua_zq_ZQFileManage_addSearchPath);
        tolua_function(tolua_S,"createDirectory",lua_zq_ZQFileManage_createDirectory);
        tolua_function(tolua_S,"getWritablePath",lua_zq_ZQFileManage_getWritablePath);
        tolua_function(tolua_S,"getFileBaseName", lua_zq_ZQFileManage_getFileBaseName);
        tolua_function(tolua_S,"getDirPath", lua_zq_ZQFileManage_getDirPath);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQFileManage_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQFileManage).name();
    g_luaType[typeName] = "zq.ZQFileManage";
    g_typeCast["ZQFileManage"] = "zq.ZQFileManage";
    return 1;
}

int lua_zq_ZQJsonManage_getValueFromFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_getValueFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:getValueFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getValueFromFile'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getValueFromFile(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:getValueFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getValueFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_getDictFromText(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_getDictFromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:getDictFromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getDictFromText'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->getDictFromText(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:getDictFromText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getDictFromText'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_getDictFromFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_getDictFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:getDictFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getDictFromFile'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->getDictFromFile(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:getDictFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getDictFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_getArrayFromText(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_getArrayFromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:getArrayFromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getArrayFromText'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->getArrayFromText(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:getArrayFromText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getArrayFromText'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_getArrayFromFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_getArrayFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:getArrayFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getArrayFromFile'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->getArrayFromFile(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:getArrayFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getArrayFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQJsonManage_getValueFromText(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQJsonManage_getValueFromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQJsonManage:getValueFromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQJsonManage_getValueFromText'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getValueFromText(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQJsonManage:getValueFromText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQJsonManage_getValueFromText'.",&tolua_err);
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
        tolua_function(tolua_S,"getValueFromFile",lua_zq_ZQJsonManage_getValueFromFile);
        tolua_function(tolua_S,"getDictFromText",lua_zq_ZQJsonManage_getDictFromText);
        tolua_function(tolua_S,"getDictFromFile",lua_zq_ZQJsonManage_getDictFromFile);
        tolua_function(tolua_S,"getArrayFromText",lua_zq_ZQJsonManage_getArrayFromText);
        tolua_function(tolua_S,"getArrayFromFile",lua_zq_ZQJsonManage_getArrayFromFile);
        tolua_function(tolua_S,"getValueFromText",lua_zq_ZQJsonManage_getValueFromText);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQJsonManage_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQJsonManage).name();
    g_luaType[typeName] = "zq.ZQJsonManage";
    g_typeCast["ZQJsonManage"] = "zq.ZQJsonManage";
    return 1;
}

int lua_zq_ZQPlistManage_getValueFromFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_getValueFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:getValueFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getValueFromFile'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getValueFromFile(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:getValueFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getValueFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_getDictFromText(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_getDictFromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:getDictFromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getDictFromText'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->getDictFromText(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:getDictFromText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getDictFromText'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_getDictFromFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_getDictFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:getDictFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getDictFromFile'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->getDictFromFile(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:getDictFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getDictFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_getArrayFromText(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_getArrayFromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:getArrayFromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getArrayFromText'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->getArrayFromText(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:getArrayFromText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getArrayFromText'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_getArrayFromFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_getArrayFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:getArrayFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getArrayFromFile'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->getArrayFromFile(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:getArrayFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getArrayFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQPlistManage_getValueFromText(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQPlistManage_getValueFromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQPlistManage:getValueFromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQPlistManage_getValueFromText'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getValueFromText(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQPlistManage:getValueFromText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQPlistManage_getValueFromText'.",&tolua_err);
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
        tolua_function(tolua_S,"getValueFromFile",lua_zq_ZQPlistManage_getValueFromFile);
        tolua_function(tolua_S,"getDictFromText",lua_zq_ZQPlistManage_getDictFromText);
        tolua_function(tolua_S,"getDictFromFile",lua_zq_ZQPlistManage_getDictFromFile);
        tolua_function(tolua_S,"getArrayFromText",lua_zq_ZQPlistManage_getArrayFromText);
        tolua_function(tolua_S,"getArrayFromFile",lua_zq_ZQPlistManage_getArrayFromFile);
        tolua_function(tolua_S,"getValueFromText",lua_zq_ZQPlistManage_getValueFromText);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQPlistManage_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQPlistManage).name();
    g_luaType[typeName] = "zq.ZQPlistManage";
    g_typeCast["ZQPlistManage"] = "zq.ZQPlistManage";
    return 1;
}

int lua_zq_ZQImageManage_loadImage(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageManage_loadImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageManage:loadImage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageManage_loadImage'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->loadImage(arg0);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageManage:loadImage");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQImageManage:loadImage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageManage_loadImage'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->loadImage(arg0, arg1);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageManage:loadImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageManage_loadImage'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageManage_loadFrame(lua_State* tolua_S)
{
    int argc = 0;
    zq::ZQImageManage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"zq.ZQImageManage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (zq::ZQImageManage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_zq_ZQImageManage_loadFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "zq.ZQImageManage:loadFrame");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "zq.ZQImageManage:loadFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageManage_loadFrame'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->loadFrame(arg0, arg1);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zq.ZQImageManage:loadFrame",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageManage_loadFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_zq_ZQImageManage_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"zq.ZQImageManage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_zq_ZQImageManage_getInstance'", nullptr);
            return 0;
        }
        zq::ZQImageManage* ret = zq::ZQImageManage::getInstance();
        object_to_luaval<zq::ZQImageManage>(tolua_S, "zq.ZQImageManage",(zq::ZQImageManage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "zq.ZQImageManage:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_zq_ZQImageManage_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_zq_ZQImageManage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZQImageManage)");
    return 0;
}

int lua_register_zq_ZQImageManage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"zq.ZQImageManage");
    tolua_cclass(tolua_S,"ZQImageManage","zq.ZQImageManage","",nullptr);

    tolua_beginmodule(tolua_S,"ZQImageManage");
        tolua_function(tolua_S,"loadImage",lua_zq_ZQImageManage_loadImage);
        tolua_function(tolua_S,"loadFrame",lua_zq_ZQImageManage_loadFrame);
        tolua_function(tolua_S,"getInstance", lua_zq_ZQImageManage_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(zq::ZQImageManage).name();
    g_luaType[typeName] = "zq.ZQImageManage";
    g_typeCast["ZQImageManage"] = "zq.ZQImageManage";
    return 1;
}
TOLUA_API int register_all_zq(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"zq",0);
	tolua_beginmodule(tolua_S,"zq");

	lua_register_zq_ZQFileManage(tolua_S);
	lua_register_zq_ZQJsonManage(tolua_S);
	lua_register_zq_ZQPlistManage(tolua_S);
	lua_register_zq_ZQImageManage(tolua_S);
	lua_register_zq_ZQLogger(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

