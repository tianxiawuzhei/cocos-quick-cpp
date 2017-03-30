#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "scripting/lua-bindings/manual/lua_module_register.h"
#include "luabinding/cocos2dx_extra_luabinding.h"
#include "luabinding/lua_cocos2dx_extension_filter_auto.hpp"
#include "luabinding/lua_cocos2dx_extension_nanovg_auto.hpp"
#include "luabinding/lua_cocos2dx_extension_nanovg_manual.hpp"
#include "luabinding/HelperFunc_luabinding.h"
#include "lua_extensions/lua_extensions_more.h"
#include "node-ex/lua_cocos2dx_quick_manual.hpp"

#include "auto_buildings/lua_zq_auto.hpp"
#include "tolua_buildings/zq_custom_action_tolua_luabinding.h"
#include "tolua_buildings/zq_sprite_draw_tolua_manual.h"
#include "tolua_buildings/zq_scriptHandler_tolua_luabinding.h"

#include "core/ZQAppEvent.h"
#include "core/ZQAppCenter.h"
#include "launch/ZQLaunchScene.h"
#include "data/ZQFileManage.h"
#include "lualoader/ZQLuaLoader.h"
#include "tool/ZQDeviceInfo.h"
#include "utils/ZQStringUtils.h"
#include "log/ZQLogger.h"
#include "lualoader/ZQLuaLoader.h"


using namespace CocosDenshion;
using namespace zq;
USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

static void quick_module_register(lua_State *L)
{
    luaopen_lua_extensions_more(L);
    
    lua_getglobal(L, "_G");
    if (lua_istable(L, -1))//stack:...,_G,
    {
        register_all_quick_manual(L);
        luaopen_cocos2dx_extra_luabinding(L);
        register_all_cocos2dx_extension_filter(L);
        register_all_cocos2dx_extension_nanovg(L);
        register_all_cocos2dx_extension_nanovg_manual(L);
        luaopen_HelperFunc_luabinding(L);
        register_all_zq(L);
        luaopen_zq_custom_action_tolua_luabinding(L);
        luaopen_zq_sprite_draw_tolua_manual(L);
        luaopen_zq_scriptHandler_tolua_luabinding(L);
    }
    lua_pop(L, 1);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview)
    {
        glview = cocos2d::GLViewImpl::createWithRect("zq_cpp", Rect(0,0,900,640));
        director->setOpenGLView(glview);
    }
    else
    {
        director->setDefaultValues();
    }
    
    director->setProjection(cocos2d::Director::Projection::_2D);
    // set default FPS
    Director::getInstance()->setAnimationInterval(1.0 / 60.0f);

    // register lua module
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    engine->addLuaLoader(zq_lua_loader);
    
    lua_module_register(L);
    quick_module_register(L);

    LuaStack* stack = engine->getLuaStack();
//    stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));

    //register custom function
    //LuaStack* stack = engine->getLuaStack();
    //register_custom_function(stack->getLuaState());
    
    ZQFileManage::set_url_for_code("http://172.26.167.82:8089/");
    
#if COCOS2D_DEBUG
    bool clean = true;
#else
    bool clean = UserDefault::getInstance()->getBoolForKey("pref_cache") || UserDefault::getInstance()->getBoolForKey("pref_data");
#endif
    
    std::string v_old = UserDefault::getInstance()->getStringForKey("cpp_version");
    std::string v_new = zq::StringUtils::format("%d", ZQDeviceInfo::getInstance()->version_cpp());
    
    ZQLogD("Resource c++ version old: %s, new: %s", v_old.c_str(), v_new.c_str());
    if (clean || v_old != v_new)
    {
        ZQFileManage::remove_file(ZQFileManage::cache_path());
        ZQFileManage::create_folder(ZQFileManage::cache_path());
        
        ZQFileManage::rebuild_folder(ZQFileManage::temp_path());
    }
    
    UserDefault::getInstance()->setBoolForKey("clean_cache_pref", UserDefault::getInstance()->getBoolForKey("pref_data"));
    UserDefault::getInstance()->setBoolForKey("reset_account_perf", UserDefault::getInstance()->getBoolForKey("pref_logout"));
    
    UserDefault::getInstance()->setBoolForKey("pref_data", false);
    UserDefault::getInstance()->setBoolForKey("pref_cache", false);
    UserDefault::getInstance()->setStringForKey("cpp_version", v_new);
    UserDefault::getInstance()->flush();
    
    if (engine->executeScriptFile("main.lua"))
    {
        return false;
    }

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
