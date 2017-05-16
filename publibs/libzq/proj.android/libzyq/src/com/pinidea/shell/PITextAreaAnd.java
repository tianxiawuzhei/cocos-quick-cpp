// ------------------------------------------------------------------
// TextAreaAnd
// 多行文本输入框
// Author: Jian Chen
// Email:  admin@chensoft.com
// Create: 2015.07.09
package com.pinidea.shell;

import java.lang.Exception;

import android.util.Log;
import android.util.TypedValue;
import android.os.Looper;
import android.os.Handler;
import android.graphics.Color;
import android.view.View;
import android.view.Gravity;
import android.widget.EditText;
import android.widget.FrameLayout;

import org.cocos2dx.lib.Cocos2dxActivity;

public class PITextAreaAnd {
    // -------------------------------------------------------------------------
    // Members
    // -------------------------------------------------------------------------
    private EditText _view;

    
    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------
    public PITextAreaAnd() {
        final PITextAreaAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view = new EditText(Cocos2dxActivity.getContext());
                self._view.setGravity(Gravity.TOP);
                self._view.setBackgroundDrawable(null);
                self._view.setTextColor(Color.rgb(255, 255, 255));
            }
        });
    }

    /**
     * 设置显示文字
     */
    void setString(final String text) {
        final PITextAreaAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setText(text);
            }
        });
    }
            
    /**
     * 设置字体大小
     */
    void setFontSize(final float font_size) {
        final PITextAreaAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setTextSize(TypedValue.COMPLEX_UNIT_PX, font_size);
            }
        });
    }
        
    /**
     * 设置字体颜色
     */
    void setFontColor(final int r, final int g, final int b) {
        final PITextAreaAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setTextColor(Color.rgb(r, g, b));
            }
        });
    }
        
    /**
     * 获取输入文字
     */
    String getString() {
        return this._view.getText().toString();
    }

    /**
     * 重载cocos2d方法
     */
    void setParent(final boolean hasParent) {
        final PITextAreaAnd self = this;

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
        final PITextAreaAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setVisibility(visible ? View.VISIBLE : View.INVISIBLE);
            }
        });
    }

    void setOpacity(final int opacity) {
        final PITextAreaAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                try
                {
                    self._view.setAlpha((float)(opacity / 255.0));
                }
                catch (Exception e)
                {
                    Log.e("cocos2d-x", "TextArea: system not support alpha");
                }
            }
        });
    }

    void update(final float x, final float y, final float w, final float h) {
        final PITextAreaAnd self = this;

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
}