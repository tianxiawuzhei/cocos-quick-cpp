// ------------------------------------------------------------------
// WebWidgetAnd
// 内嵌浏览器
// Author: Jian Chen
// Email:  admin@chensoft.com
// Create: 2014.11.12
package com.pinidea.shell;

import java.lang.Exception;

import android.util.Log;
import android.os.Looper;
import android.os.Handler;
import android.view.View;
import android.graphics.Bitmap;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.FrameLayout;

import org.cocos2dx.lib.Cocos2dxActivity;

public class PIWebWidgetAnd {
    // -------------------------------------------------------------------------
    // Members
    // -------------------------------------------------------------------------
    private WebView _view;
    private String _uuid;

    
    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------
    public PIWebWidgetAnd(String uuid) {
        this._uuid = uuid;

        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                WebWidgetDelegate delegate = new WebWidgetDelegate();
                delegate.setParent(self);

                self._view = new WebView(Cocos2dxActivity.getContext());
                self._view.setWebViewClient(delegate);
                self._view.getSettings().setJavaScriptEnabled(true);
                self._view.getSettings().setSupportZoom(true);
                self._view.getSettings().setBuiltInZoomControls(true);

                try
                {
                    self._view.getSettings().setDisplayZoomControls(false);
                }
                catch (Exception e)
                {
                    self._view.getSettings().setBuiltInZoomControls(false);
                    Log.e("cocos2d-x", "webwidget: system not support zoom");
                }
            }
        });
    }

    /**
     * 加载网页：网址
     * 加载网页：字符串
     */
    void loadURL(final String url) {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.loadUrl(url);
            }
        });
    }

    void loadHTML(final String html) {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.loadData(html, "text/html", null);
            }
        });
    }

    /**
     * 流程控制：停止、刷新、向后、向前
     */
    void stop() {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.stopLoading();
            }
        });
    }

    void refresh() {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.reload();
            }
        });
    }

    void back() {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.goBack();
            }
        });
    }

    void forward() {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.goForward();
            }
        });
    }

    /**
     * 重载cocos2d方法
     */
    void setParent(final boolean hasParent) {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                FrameLayout layout = ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getLayout();

                if (hasParent)
                {
                    layout.addView(self._view);
                }
                else
                {
                    layout.removeView(self._view);
                }
            }
        });
    }

    void setVisible(final boolean visible) {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setVisibility(visible ? View.VISIBLE : View.INVISIBLE);
            }
        });
    }

    void setOpacity(final int opacity) {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                try
                {
                    self._view.setAlpha((float)(opacity / 255.0));
                }
                catch (Exception e)
                {
                    Log.e("cocos2d-x", "webwidget: system not support alpha");
                }
            }
        });
    }

    void update(final float x, final float y, final float w, final float h) {
        final PIWebWidgetAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                FrameLayout.LayoutParams layoutParams = new FrameLayout.LayoutParams(FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT);
                layoutParams.leftMargin = (int)x;
                layoutParams.topMargin  = (int)y;
                layoutParams.width      = (int)w;
                layoutParams.height     = (int)h;
                self._view.setLayoutParams(layoutParams);
            }
        });
    }

    
    // -------------------------------------------------------------------------
    // Delegate
    // -------------------------------------------------------------------------
    public class WebWidgetDelegate extends WebViewClient {
        private PIWebWidgetAnd _parent;

        /**
         * 设置宿主
         */
        public void setParent(PIWebWidgetAnd parent) {
            this._parent = parent;
        }

        /**
         * 始终在内嵌浏览器中显示网页
         */
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
            return false;
        }

        /**
         * 页面开始加载
         */
        public void onPageStarted(WebView view, String url, Bitmap favicon) {
            PIWebWidgetAnd.nativeReady(this._parent._uuid, url);
        }

        /**
         * 页面加载完成
         */
        public void onPageFinished(WebView view, String url) {
            PIWebWidgetAnd.nativeFinish(this._parent._uuid, url);
        }
    }


    // -------------------------------------------------------------------------
    // Native
    // -------------------------------------------------------------------------
    private static native void nativeReady(String uuid, String url);
    private static native void nativeFinish(String uuid, String url);
}