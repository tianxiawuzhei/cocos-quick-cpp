// ------------------------------------------------------------------
// MoviePlayerAnd
// 视频播放
// Author: Jian Chen
// Email:  admin@chensoft.com
// Create: 2015.10.27
package com.pinidea.shell;

import java.lang.Exception;

import android.net.Uri;
import android.util.Log;
import android.os.Looper;
import android.os.Handler;
import android.view.View;
import android.view.ViewGroup;
import android.graphics.Bitmap;
import android.widget.VideoView;
import android.widget.FrameLayout;
import android.media.MediaPlayer;

import org.cocos2dx.lib.Cocos2dxActivity;

public class PIMoviePlayerAnd {
    // -------------------------------------------------------------------------
    // Members
    // -------------------------------------------------------------------------
    private VideoView _view;
    private String _uuid;

    
    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------
    public PIMoviePlayerAnd(String uuid) {
        this._uuid = uuid;
    }

    /**
     * 播放视频
     */
    void play(final String path) {
        final PIMoviePlayerAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self.clear();

                try
                {
                    self._view = new VideoView(Cocos2dxActivity.getContext());

                    self._view.setZOrderOnTop(true);
                    self._view.setVideoPath(path);
                    self._view.requestFocus();
                    self._view.setOnCompletionListener(new MediaPlayer.OnCompletionListener()
                    {
                        @Override
                        public void onCompletion(MediaPlayer mp)
                        {
                            self.clear();
                            PIMoviePlayerAnd.nativeFinish(self._uuid);
                        }
                    });
                    self._view.start();

                    FrameLayout layout = ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getLayout();
                    layout.addView(self._view);
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                    self.clear();
                    PIMoviePlayerAnd.nativeFinish(self._uuid);
                }
            }
        });
    }

    /**
     * 清理视频
     */
    void clear() {
        if (this._view == null)
            return;

        this._view.stopPlayback();
        ((ViewGroup)this._view.getParent()).removeView(this._view);

        this._view = null;
    }


    // -------------------------------------------------------------------------
    // Native
    // -------------------------------------------------------------------------
    private static native void nativeFinish(String uuid);
}