package com.laifeng.lflive;

import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.ref.WeakReference;

import android.content.Context;
import android.os.Environment;
import android.os.Message;
import android.util.Log;
import android.view.SurfaceView;

public class LFLiveAPI {
	private final int nativeAVEngine;
	private native void native_register(Object context);
	private native void native_unregister();
	private native int native_create();
	private native int native_AVInit();
	private native int native_avtestmain(Object win0, Object win1);
    
	public LFLiveAPI(){
		nativeAVEngine = create();
	}
	
	public void register(Context context){
		native_register(context);
	}
	
	public void unregister(){
		native_unregister();
	}
	
	public int create(){
		return native_create();
	}
	
	public int AVInit(){
		return native_AVInit();
	}
	
	public int avtestmain(SurfaceView win0, SurfaceView win1){
		return native_avtestmain(win0, win1);
	}

	
	static {
        System.loadLibrary("avutil-52");
        System.loadLibrary("swresample-0");
        System.loadLibrary("swscale-2");
        System.loadLibrary("avcodec-55");
        System.loadLibrary("avformat-55");
        System.loadLibrary("webrtcdemo-jni");
        System.loadLibrary("avengine-jni");
		System.loadLibrary("LFLive");
	}
}
