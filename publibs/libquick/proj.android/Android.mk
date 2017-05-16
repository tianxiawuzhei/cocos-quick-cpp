
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := quick_static
LOCAL_MODULE_FILENAME := libquick
LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := \
    ../quick-src/node-ex/lua_cocos2dx_quick_manual.cpp \
    ../quick-src/node-ex/LuaEventNode.cpp \
    ../quick-src/node-ex/LuaNodeManager.cpp \
    ../quick-src/node-ex/LuaTouchEventManager.cpp \
    ../quick-src/node-ex/LuaTouchTargetNode.cpp \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

LOCAL_C_INCLUDES := $(LOCAL_EXPORT_C_INCLUDES) \
                    $(LOCAL_PATH)/../../cocos2dx/cocos \
                    $(LOCAL_PATH)/../../cocos2dx/external/lua/luajit/include \
                    $(LOCAL_PATH)/../../cocos2dx/external/lua/tolua \
                    $(LOCAL_PATH)/../../cocos2dx/external \
                    $(LOCAL_PATH)/../../cocos2dx/cocos/scripting/lua-bindings/manual

LOCAL_WHOLE_STATIC_LIBRARIES := extra_static
LOCAL_WHOLE_STATIC_LIBRARIES += lua_extensions_static

include $(BUILD_STATIC_LIBRARY)

$(call import-module, libquick/quick-src/extra)
$(call import-module, libquick/quick-src/lua_extensions)
