LOCAL_PATH := $(call my-dir)

# libsxd
include $(CLEAR_VARS)

LOCAL_MODULE := base_static

LOCAL_MODULE_FILENAME := libbase

LOCAL_SRC_FILES := ../../Classes/AppDelegate.cpp \




LOCAL_C_INCLUDES := $(LOCAL_PATH)/../.. \
                    $(LOCAL_PATH)/../../Classes \


LOCAL_WHOLE_STATIC_LIBRARIES := cocos2d_lua_static
LOCAL_WHOLE_STATIC_LIBRARIES += quick_static
LOCAL_WHOLE_STATIC_LIBRARIES += zq_static

include $(BUILD_STATIC_LIBRARY)

$(call import-module,scripting/lua-bindings/proj.android)
$(call import-module,libzq/proj.android/libzyq)
$(call import-module,libquick/proj.android)
