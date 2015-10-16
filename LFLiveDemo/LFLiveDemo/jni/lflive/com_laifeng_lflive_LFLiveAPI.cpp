#define __ANDROID__


#include "com_laifeng_lflive_LFLiveAPI.h"
#include "engine/interface/avengAPI.h"
#include "engine/interface/ffmpeg_api.h"
#include "engine/interface/gxhlog.h"
#include "../myLog.h"
#include <jni.h>
#include <assert.h>
#include <string.h>

#ifdef TAG
#undef TAG
#endif
#define TAG "com_laifeng_lflive_LFLiveAPI.cpp"

static const char* mClassPathName = "com/laifeng/lflive/LFLiveAPI";

static JavaVM* jVM = NULL;

class AVEngineData {
 public:
  AVEngineData()
      : _avHnd(NULL),_windows0(NULL),_windows1(NULL)
  {

  }

  ~AVEngineData()
  {

  }
  void *_windows0;
  void *_windows1;
  void *_avHnd;
 private:

};
AVEngineData* mData = NULL;


static void
com_laifeng_lflive_LFLiveAPI_register(JNIEnv* env, jobject thiz, jobject context)
{
	LOGI("com_laifeng_lflive_LFLiveAPI_register");
	char format[128] = "LFLiveAPI_register = %x \n";
	LogOut(format,(void *)jVM);
	IISetAndroidObj((void*)jVM, (void*) context);
	strcpy(format, "LFLiveAPI_register is ok \n");
	LogOut(format,NULL);
}

static void
com_laifeng_lflive_LFLiveAPI_unregister(JNIEnv* env, jobject thiz)
{
	LOGI("com_laifeng_lflive_LFLiveAPI_unregister");
	IIClearAndroidObj();
}

static
int com_laifeng_lflive_LFLiveAPI_create(JNIEnv* env, jobject j_av){
	  mData = new AVEngineData();
	  //LogInit(0);
	  return 1111;
}

static
int com_laifeng_lflive_LFLiveAPI_init(JNIEnv* env, jobject j_av){
	AVEngineData* av_data = mData;
	jint ret = 0;
	char format[128] = "IIICreateAVETestObj 0\n";
	LogOut(format,NULL);
	ret = IIICreateAVETestObj(&av_data->_avHnd);
	strcpy(format,"IIIICreateAVETestObj:ret = %d \n");
	LogOut(format,(void *)&ret);
	strcpy(format,"IIICreateAVETestObj = %x \n");
	LogOut(format,(void *)&av_data->_avHnd);
	return ret;
}

static
int com_laifeng_lflive_LFLiveAPI_avtestmain(JNIEnv* env, jobject j_av, jobject gl_surface0, jobject gl_surface1){
	AVEngineData* av_data = mData;
	av_data->_windows0 = gl_surface0;
	av_data->_windows1 = gl_surface1;
	return IIAVETestMain(gl_surface0, gl_surface1);
}


static JNINativeMethod mMethods[] = {//method for JAVA. use this to register native method
		{"native_register", "(Ljava/lang/Object;)V", (void*) com_laifeng_lflive_LFLiveAPI_register},
		{"native_unregister", "()V", (void*) com_laifeng_lflive_LFLiveAPI_unregister},
		{"native_create", "()I", (int*) com_laifeng_lflive_LFLiveAPI_create},
		{"native_AVInit", "()I", (int*) com_laifeng_lflive_LFLiveAPI_init},
		{"native_avtestmain", "(Ljava/lang/Object;Ljava/lang/Object;)I", (int*) com_laifeng_lflive_LFLiveAPI_avtestmain},
};

int jniRegisterNativeMethods(JNIEnv* env, const JNINativeMethod* methods, int count) {
	jclass clazz;
	int ret = -1;
	clazz = env->FindClass(mClassPathName);
	if(clazz == NULL) {
		return ret;
	}
	if((ret = env->RegisterNatives(clazz,methods, count)) < 0) {
		return ret;
	}
	return ret;
}

int registerMethods(JNIEnv* env) {
	JavaVM* jVM;
	env->GetJavaVM((JavaVM**)&jVM);
	return jniRegisterNativeMethods(env, mMethods, sizeof(mMethods)/sizeof(mMethods[0]));
}

int JNI_OnLoad(JavaVM* vm, void* reserved)
{//JNI main
	jVM = vm;
	JNIEnv* env = NULL;
	jint ret = JNI_ERR;
	if(vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
		LOGE("GetEnv failed!");
		return ret;
	}
	assert(env != NULL);
	if(registerMethods(env) != JNI_OK) {
		LOGE("can not load methods!");
		return ret;
	}
	ret = JNI_VERSION_1_4;
	LOGI("Loaded!");
	return ret;
}


