package com.laifeng.lflive;

import java.io.IOException;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.SurfaceView;


public class MainActivity extends Activity {
 
		private  LFLiveAPI avEngine = new LFLiveAPI();
		private SurfaceView surface1;
		private SurfaceView surface2;
	    public void onCreate(Bundle savedInstanceState) {
	    	
	        super.onCreate(savedInstanceState);
	      	        
	        setContentView(R.layout.activity_av_capture);
	        surface1 = (SurfaceView)findViewById(R.id.videosurface1);
	        surface2 = (SurfaceView)findViewById(R.id.videosurface2);
	        avEngine.register(this);
			avEngine.AVInit();
			avEngine.avtestmain(surface1,surface2);
	    }


		@Override
		protected void onDestroy() {
			// TODO Auto-generated method stub
			super.onDestroy();
			avEngine.unregister();
		}
	    
	    
}
