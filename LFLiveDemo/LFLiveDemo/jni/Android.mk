LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_PREBUILT_STATIC_JAVA_LIBRARIES:= audio-device:libs/audio_device_module_java.jar \
video-capture:libs/video_capture_module_java.jar \
video-render:libs/video_render_module_java.jar
include $(BUILD_MULTI_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE    := avcodec
LOCAL_SRC_FILES := prebuilt/libavcodec-55.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := avformat
LOCAL_SRC_FILES := prebuilt/libavformat-55.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := avengine
LOCAL_SRC_FILES := prebuilt/libavengine-jni.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := webrtcdemo-jni
LOCAL_SRC_FILES := prebuilt/libwebrtcdemo-jni.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := avutil
LOCAL_SRC_FILES := prebuilt/libavutil-52.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := swresample
LOCAL_SRC_FILES := prebuilt/libswresample-0.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := swscale
LOCAL_SRC_FILES := prebuilt/libswscale-2.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
#本地路径
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../lflive \
    				$(LOCAL_PATH)
    				
#生成模块
LOCAL_MODULE := LFLive
######依赖关系######
#系统依赖
LOCAL_LDLIBS += -L$(LOCAL_PATH)/../lflive
# for native multimedia
LOCAL_LDLIBS += -lOpenMAXAL
# for logging
LOCAL_LDLIBS += -llog
# for native windows
LOCAL_LDLIBS += -landroid
#直播传输层依赖 
LOCAL_LDLIBS += -L$(LOCAL_PATH)/prebuilt -lcurl  -L$(LOCAL_PATH)/prebuilt -llive_stream_sdk

LOCAL_SHARED_LIBRARIES := avcodec avformat avutil swresample swscale avengine webrtcdemo-jni
LOCAL_C_INCLUDES +=/vagrant/webrtc/src
LOCAL_C_INCLUDES +=/vagrant/webrtc/src/third_party/android_tools/ndk//sources/cxx-stl/llvm-libc++/libcxx/include
LOCAL_C_INCLUDES +=/vagrant/webrtc/src/third_party/android_tools/ndk//sources/cxx-stl/llvm-libc++abi/libcxxabi/include
LOCAL_C_INCLUDES +=/vagrant/webrtc/src/third_party/android_tools/ndk//sources/android/support/include
LOCAL_C_INCLUDES +=/vagrant/webrtc/src/chromium/src/third_party/icu/source/common

LOCAL_SRC_FILES += lflive/com_laifeng_lflive_LFLiveAPI.cpp
######生成动态库so######
include $(BUILD_SHARED_LIBRARY)