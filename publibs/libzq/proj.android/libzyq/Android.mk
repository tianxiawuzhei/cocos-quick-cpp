LOCAL_PATH := $(call my-dir)

# libsxd
include $(CLEAR_VARS)

LOCAL_MODULE := zq_static

LOCAL_MODULE_FILENAME := libzq

LOCAL_SRC_FILES := ../../auto_buildings/lua_zq_auto.cpp \
				   ../../tolua_buildings/zq_custom_action_tolua_luabinding.cpp \
				   ../../tolua_buildings/zq_scriptHandler_tolua_luabinding.cpp \
				   ../../tolua_buildings/zq_sprite_draw_tolua_manual.cpp \
                   ../../libzq/core/ZQAppCenter.cpp \
				   ../../libzq/core/ZQAppEvent.cpp \
				   ../../libzq/core/ZQRunLoop.cpp \
				   ../../libzq/core/ZQScriptHandler.cpp \
				   ../../libzq/data/ZQCCBILoader.cpp \
				   ../../libzq/data/ZQFileManage.cpp \
				   ../../libzq/data/ZQImageLoader.cpp \
				   ../../libzq/data/ZQJsonManage.cpp \
				   ../../libzq/data/ZQPlistManage.cpp \
				   ../../libzq/draw/ZQTextUtil.cpp \
				   ../../libzq/draw/ZQTextBox.cpp \
				   ../../libzq/draw/ZQTextArea.cpp \
				   ../../libzq/draw/lua_zq_visit_lua_manual.cpp \
				   ../../libzq/draw/ZQCustomAction.cpp \
				   ../../libzq/lang/ZQLocale.cpp \
				   ../../libzq/log/ZQLogger.cpp \
				   ../../libzq/lualoader/ZQLuaLoader.cpp \
				   ../../libzq/net/ZQHTTPService.cpp \
				   ../../libzq/tool/ZQDataFormat.cpp \
				   ../../libzq/tool/ZQDeviceInfo.cpp \
				   ../../libzq/tool/ZQMD5.cpp \
				   ../../libzq/utils/ZQDateUtils.cpp \
				   ../../libzq/utils/ZQFs_unix.cpp \
				   ../../libzq/utils/ZQFs.cpp \
				   ../../libzq/utils/ZQStringUtils.cpp \
				   ../../libzq/utils/ZQUtf8.cpp \
				   ../../libzq/platform/and/ZQDeviceInfoAnd.cpp \
				   ../../libzq/platform/and/ZQLoggerAnd.cpp \
				   ../../libzq/platform/and/ZQTextAreaAnd.cpp \
				   ../../libzq/platform/and/ZQTextBoxAnd.cpp \
				   ../../libzq/platform/and/ZQTextUtilAnd.cpp \


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../libzq \
				    $(LOCAL_PATH)/../../../cocos2dx/cocos \
				    $(LOCAL_PATH)/../../../cocos2dx/external/lua/luajit/include \
				    $(LOCAL_PATH)/../../../cocos2dx/external/lua/tolua \
				    $(LOCAL_PATH)/../../../cocos2dx/cocos/scripting/lua-bindings/manual \
				    $(LOCAL_PATH)/../../../cocos2dx \
				    $(LOCAL_PATH)/../../../cocos2dx/external \
				    $(LOCAL_PATH)/../../libzq/libs \
				    $(LOCAL_PATH)/../../../cocos2dx/external/curl/include/android \
				    $(LOCAL_PATH)/../../../cocos2dx/cocos/platform/android


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../ \
						   $(LOCAL_PATH)/../../libzq \

LOCAL_WHOLE_STATIC_LIBRARIES += cocos_curl_static

LOCAL_CPPFLAGS += -fexceptions


include $(BUILD_STATIC_LIBRARY)

$(call import-module, external/curl/prebuilt/android)
