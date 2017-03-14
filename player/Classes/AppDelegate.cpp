#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"

#include "native/CCNative.h"
#include "network/CCHTTPRequest.h"
#include "luabinding/cocos2dx_extra_luabinding.h"
#include "luabinding/lua_cocos2dx_extension_filter_auto.hpp"
#include "luabinding/lua_cocos2dx_extension_nanovg_auto.hpp"
#include "luabinding/lua_cocos2dx_extension_nanovg_manual.hpp"
#include "luabinding/HelperFunc_luabinding.h"
#include "lua_extensions/lua_extensions_more.h"
#include "node-ex/lua_cocos2dx_quick_manual.hpp"
#include "PlayerProtocol.h"

#include "auto_buildings/lua_zq_auto.hpp"
#include "tolua_buildings/zq_custom_action_tolua_luabinding.h"
#include "tolua_buildings/zq_sprite_draw_tolua_manual.h"
#include "tolua_buildings/zq_scriptHandler_tolua_luabinding.h"

#include "core/ZQAppEvent.h"
#include "core/ZQAppCenter.h"
#include "launch/ZQLaunchScene.h"
#include "data/ZQFileManage.h"

using namespace CocosDenshion;

USING_NS_CC;
USING_NS_CC_EXTRA;
using namespace std;

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

//
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

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
    director->setProjection(Director::Projection::_2D);
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	director->startAnimation();

    // register lua engine
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);

    // If you want to use Quick-Cocos2dx-Community, please uncomment below code
    quick_module_register(L);

    LuaStack* stack = engine->getLuaStack();
//    stack->setXXTEAKeyAndSign("2dxLua", "XXTEA");
    
    zq::ZQFileManage::set_url_for_res("http://debug.mmm.io/cn/");
    
    StartupCall *call = StartupCall::create(this);
    call->startup();
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    
    zq::ZQAppEvent::getInstance()->applicationDidEnterBackground();
    
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    
    zq::ZQAppEvent::getInstance()->applicationWillEnterForeground();
}


void AppDelegate::setProjectConfig(const ProjectConfig& project)
{
    _project = project;
}

// ----------------------------------------

StartupCall *StartupCall::create(AppDelegate *app)
{
    StartupCall *call = new StartupCall();
    call->_app = app;
    call->autorelease();
    return call;
}

void StartupCall::startup()
{
    auto engine = LuaEngine::getInstance();
    auto stack = engine->getLuaStack();
    
    const ProjectConfig &project = _app->_project;
    
    // set framework path
    if (!project.isLoadPrecompiledFramework())
    {
        FileUtils::getInstance()->addSearchPath(project.getQuickCocos2dxRootPath() + "quick/");
    }
    
    // add quick root path for search libzq/*lua lib
    FileUtils::getInstance()->addSearchPath(project.getQuickCocos2dxRootPath());
    
    // set search path
    string path = FileUtils::getInstance()->fullPathForFilename(project.getScriptFileRealPath().c_str());
    size_t pos;
    while ((pos = path.find_first_of("\\")) != std::string::npos)
    {
        path.replace(pos, 1, "/");
    }
    size_t p = path.find_last_of("/");
    string workdir;
    if (p != path.npos)
    {
        workdir = path.substr(0, p);
        // Lua 代码文件的搜索需要包含src
        stack->addSearchPath(workdir.c_str());
        // cc.FileUtils的文件搜索去掉src目录
        size_t p = workdir.find_last_of("/");
        workdir = path.substr(0, p);
        FileUtils::getInstance()->addSearchPath(workdir);
    }
    
    // load framework
    if (project.isLoadPrecompiledFramework())
    {
        const string precompiledFrameworkPath = project.getPrecompiledFrameworkPath();
        stack->loadChunksFromZIP(precompiledFrameworkPath.c_str());
    }
    
    // load script
    string env = "__LUA_STARTUP_FILE__=\"";
    env.append(path);
    env.append("\"");
    engine->executeString(env.c_str());
    
    CCLOG("------------------------------------------------");
    CCLOG("LOAD LUA FILE: %s", path.c_str());
    CCLOG("------------------------------------------------");
//    engine->executeScriptFile(path.c_str());
    
    zq::ZQAppCenter::getInstance()->_script_file = path;
    
    auto scene = zq::ZQLaunchScene::create();
    cocos2d::Director::getInstance()->runWithScene(scene);
    // track start event
    trackLaunchEvent();
}

void StartupCall::trackEvent(const char *eventName)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    const char *platform = "win";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    const char *platform = "mac";
#else
    const char *platform = "UNKNOWN";
#endif
    
    HTTPRequest *request = HTTPRequest::createWithUrl(NULL,
                                                      "http://www.google-analytics.com/collect",
                                                      kCCHTTPRequestMethodPOST);
    request->addPOSTValue("v", "1");
    request->addPOSTValue("tid", "UA-84326395-1");
    request->addPOSTValue("cid", Native::getOpenUDID().c_str());
    request->addPOSTValue("t", "event");
    
    request->addPOSTValue("an", "player");
    request->addPOSTValue("av", cocos2dVersion());
    
    request->addPOSTValue("ec", platform);
    request->addPOSTValue("ea", eventName);
    
    request->start();
}

void StartupCall::trackLaunchEvent()
{
    trackEvent("launch");
}
