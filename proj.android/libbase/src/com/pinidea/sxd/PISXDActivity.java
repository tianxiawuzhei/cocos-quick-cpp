package com.pinidea.sxd;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

import android.util.Log;
import android.net.Uri;
import android.os.Bundle;
import android.os.AsyncTask;
import android.content.Intent;
import android.content.res.AssetManager;

import org.cocos2dx.lib.Cocos2dxActivity;

/**
 * shenxiandao base activity for all channels
 */
public class PISXDActivity extends Cocos2dxActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.v("cocos2d-x", "Activity onCreate");

        super.onCreate(savedInstanceState);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        Log.v("cocos2d-x", "Activity onNewIntent");

        super.onNewIntent(intent);
    }

    @Override
    protected void onResume() {
        Log.v("cocos2d-x", "Activity onResume");
        super.onResume();
    }

    @Override
    protected void onStop() {
        Log.v("cocos2d-x", "Activity onStop");
        super.onStop();
    }

    @Override
    public void onLowMemory() {
        Log.v("cocos2d-x", "Activity onLowMemory");

        super.onLowMemory();
        this.runOnGLThread(new Runnable() {
            public void run() {
                PISXDActivity.nativeApplicationDidReceiveMemoryWarning();
            }
        });
    }
    
    /**
     * Notify memory warning to C++
     */
    private static native void nativeApplicationDidReceiveMemoryWarning();
}