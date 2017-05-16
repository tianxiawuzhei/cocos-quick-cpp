// ------------------------------------------------------------------
// TextBoxAnd
// 单行文本输入框
// Author: Jian Chen
// Email:  admin@chensoft.com
// Create: 2015.07.20
package com.pinidea.shell;

import java.lang.Exception;

import android.app.Activity;
import android.util.Log;
import android.util.TypedValue;
import android.os.Looper;
import android.os.Handler;
import android.graphics.Color;
import android.graphics.Rect;
import android.view.View;
import android.view.Gravity;
import android.text.InputType;
import android.text.InputFilter;
import android.text.Spanned;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.content.Context;
import android.view.ViewTreeObserver;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.cocos2dx.lib.Cocos2dxRenderer;

public class PITextBoxAnd {
    // -------------------------------------------------------------------------
    // Members
    // -------------------------------------------------------------------------
    private EditText _view;

    
    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------
    public PITextBoxAnd() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view = new EditText(Cocos2dxActivity.getContext());
                self._view.setBackgroundDrawable(null);
                self._view.setTextColor(Color.rgb(255, 255, 255));
                self._view.setMaxLines(1);
                self._view.setSingleLine(true);
                self._view.setImeOptions(EditorInfo.IME_FLAG_NO_EXTRACT_UI);
                self._view.setPadding(10, 0, 10, 4);
                self._view.setFilters(new InputFilter[] {self.emojiFilter()});

                final Activity activity = (Activity)Cocos2dxActivity.getContext();

                self._view.getViewTreeObserver().addOnGlobalLayoutListener(
                    new ViewTreeObserver.OnGlobalLayoutListener() {
                        //当键盘弹出隐藏的时候会 调用此方法。
                        @Override
                        public void onGlobalLayout() {
                            self._view.bringToFront();
                            Rect r = new Rect();
                            //获取当前界面可视部分
                            activity.getWindow().getDecorView().getWindowVisibleDisplayFrame(r);
                            //获取屏幕的高度
                            int screenHeight = activity.getWindow().getDecorView().getRootView().getHeight();
                            //此处就是用来获取键盘的高度的， 在键盘没有弹出的时候 此高度为0 键盘弹出的时候为一个正数
                            int heightDifference = screenHeight - r.bottom;
                            boolean shown = (heightDifference > 0);
                            Cocos2dxGLSurfaceView.getInstance().setSoftKeyboardShown(shown);
                        }
                    }
                );

            }
        });
    }

    /**
     * 设置显示文字
     */
    void setString(final String text) {
        final PITextBoxAnd self = this;

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
        final PITextBoxAnd self = this;

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
        final PITextBoxAnd self = this;

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
     * 设置键盘模式
     */
    void setKeyboardDefault() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setInputType(InputType.TYPE_CLASS_TEXT);
            }
        });
    }

    void setKeyboardNumber() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setInputType(InputType.TYPE_CLASS_NUMBER | InputType.TYPE_NUMBER_FLAG_SIGNED);
            }
        });
    }

    void setKeyboardEmail() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_EMAIL_ADDRESS);
            }
        });
    }

    void setKeyboardURL() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_URI);
            }
        });
    }

    /**
     * 设置文本对齐
     */
    void setAlignmentLeft() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setGravity(Gravity.LEFT | Gravity.CENTER_VERTICAL);
            }
        });
    }

    void setAlignmentCenter() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setGravity(Gravity.CENTER);
            }
        });
    }

    void setAlignmentRight() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setGravity(Gravity.RIGHT | Gravity.CENTER_VERTICAL);
            }
        });
    }

    /**
     * 设置最大字符数
     */
    void setMaxLength(final int length) {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                if (length != 0)
                    self._view.setFilters(new InputFilter[] {self.emojiFilter(), self.lengthFilter(length)});
                else
                    self._view.setFilters(new InputFilter[] {self.emojiFilter()});
            }
        });
    }

    /**
     * 过滤器
     */
    private InputFilter lengthFilter(final int length) {
        return new InputFilter.LengthFilter(length);
    }

    private InputFilter emojiFilter() {
        return new InputFilter() {
            public CharSequence filter(CharSequence source, int start, int end, Spanned dest, int dstart, int dend) {
                for (int i = start; i < end; i++) {
                    char c = source.charAt(i);
                    if(!((c == 0x0) || (c == 0x9) || (c == 0xA) || (c == 0xD) || 
                        (c >= 0x20 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFD) 
                        || (c >= 0x10000 && c <= 0x10FFFF))) {
                        return "";
                    }
                }
                return null;
            }
        };
    }

    /**
     * 拥有输入焦点
     */
    void focus() {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {               
                if (self._view.requestFocus())
                {
                    final InputMethodManager imm = (InputMethodManager)Cocos2dxActivity.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
                    imm.showSoftInput(self._view, 0);
                }
            }
        });
    }

    /**
     * 重载cocos2d方法
     */
    void setParent(final boolean hasParent) {
        final PITextBoxAnd self = this;

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
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                self._view.setVisibility(visible ? View.VISIBLE : View.INVISIBLE);
            }
        });
    }

    void setOpacity(final int opacity) {
        final PITextBoxAnd self = this;

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                try
                {
                    self._view.setAlpha((float)(opacity / 255.0));
                }
                catch (Exception e)
                {
                    Log.e("cocos2d-x", "TextBox: system not support alpha");
                }
            }
        });
    }

    void update(final float x, final float y, final float w, final float h) {
        final PITextBoxAnd self = this;

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