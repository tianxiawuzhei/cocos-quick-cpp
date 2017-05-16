// ------------------------------------------------------------------
// TextUtilAnd
// 文本渲染的java接口
// Author: Jian Chen
// Email:  admin@chensoft.com
// Create: 2014.02.15
package com.pinidea.shell;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONException;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Paint.FontMetrics;
import android.graphics.Color;
import android.graphics.Rect;
import android.graphics.Typeface;
import android.opengl.GLES10;
import android.util.Log;

public class PITextUtilAnd {
    // ===========================================================
    // Members
    // ===========================================================  
    private static Paint _paint = new Paint();

    
    // ===========================================================
    // Methods
    // ===========================================================  
    /**
     * 系统默认字体
     * @return {String}
     */
    public static String standardFontName() {
        return "";
    }

    /**
     * 特定字体的文本长度
     * @param {String} text
     * @param {String} font_name
     * @param {float} font_size
     * @return {float}
     */
    public static float widthByFont(final String text, final String font_name, float font_size) {
        PITextUtilAnd._paint.setTextSize(font_size);
        PITextUtilAnd._paint.setTypeface(Typeface.DEFAULT_BOLD);
        
        return PITextUtilAnd._paint.measureText(text);
    }
    
    /**
     * 特定字体的高度
     * @param {String} text
     * @param {String} font_name
     * @param {float} font_size
     * @return {float}
     */
    public static float heightByFont(final String text, final String font_name, float font_size) {
        PITextUtilAnd._paint.setTextSize(font_size);
        PITextUtilAnd._paint.setTypeface(Typeface.DEFAULT_BOLD);
        
        FontMetrics fm = PITextUtilAnd._paint.getFontMetrics();
        return fm.bottom - fm.top;
    }

    /**
     * 制作纹理
     * 完成后会回调C++的Java_com_pinidea_shell_PITextUtilAnd_nativeRender函数
     * @param {String} info
     * @param {float} width
     * @param {float} height
     * @return {boolean}
     */
    public static boolean render(final String info, int width, int height, boolean pot) {
        try
        {
            // 检查
            JSONArray lines = new JSONArray(info);
            if ((lines.length() == 0) || (width == 0) || (height == 0))
                return false;
            
            // OpenGL对纹理大小有限制
            // 不同机器不一样，iphone4应该是2048*2048
            int[] limit = new int[1];
            GLES10.glGetIntegerv(GLES10.GL_MAX_TEXTURE_SIZE, limit, 0);

            if ((width > limit[0]) || (height > limit[0]))
            {
                Log.e("cocos2d-x", String.format("text util texture too big: %d, %d, max: %d", width, height, limit[0]));
                return false;
            }
            
            // 创建Bitmap、Canvas
            // 对于支持NPOT的设备就使用NPOT纹理
            int POTWide = pot ? PITextUtilAnd.nextPOT(width)  : width;
            int POTHigh = pot ? PITextUtilAnd.nextPOT(height) : height;
            
            Bitmap bitmap = Bitmap.createBitmap(POTWide, POTHigh, Bitmap.Config.ARGB_8888);
            Canvas canvas = new Canvas(bitmap);
            Paint  paint  = new Paint();

            paint.setAntiAlias(true);

            // 渲染文本
            for (int i = 0; i < lines.length(); ++i)
            {
                JSONObject line = lines.getJSONObject(i);
                JSONArray units = line.getJSONArray("_units");
                
                for (int j = 0; j < units.length(); ++j)
                {
                    JSONObject unit = units.getJSONObject(j);
                    if (!unit.getBoolean("_visible"))
                    	continue;
                    
                    String     text   = unit.getString("_text");
                    JSONObject color  = unit.getJSONObject("_color");
                    JSONObject stroke = unit.getJSONObject("_stroke");
                    float    stroke_w = (float)unit.getDouble("_stroke_width");
                    
                    float    size = (float)unit.getDouble("_size");
                    boolean under = unit.getBoolean("_underline");
                    float       x = (float)unit.getDouble("_x");
                    float       y = (float)unit.getDouble("_y");
                    float       w = (float)unit.getDouble("_w");
                    float       h = (float)unit.getDouble("_h");

                    int clr_force_r = color.getInt("r");
                    int clr_force_g = color.getInt("g");
                    int clr_force_b = color.getInt("b");
                    
                    int clr_stroke_r = stroke.getInt("r");
                    int clr_stroke_g = stroke.getInt("g");
                    int clr_stroke_b = stroke.getInt("b");
                    int clr_stroke_a = stroke.getInt("a");
                                        
                    // 字体
                    paint.setTypeface(Typeface.DEFAULT_BOLD);
                    paint.setTextSize((float)size);
                    
                    // y偏移
                    FontMetrics fm = paint.getFontMetrics();                    
                    
                    // 描边
                    if (stroke_w > 0)
                    {
                        paint.setARGB(clr_stroke_a, clr_stroke_r, clr_stroke_g, clr_stroke_b);
                        paint.setStyle(Paint.Style.STROKE);
                        paint.setStrokeWidth(stroke_w);
                        
                        // 文字
                        // 绘制时y略微偏移，避免微小的像素偏差
                        canvas.drawText(text, x, y - 1 - fm.top, paint);
                    }
                    
                    // 填充
                    paint.setARGB(255, clr_force_r, clr_force_g, clr_force_b);
                    paint.setStyle(Paint.Style.FILL);
                    
                    // 文字
                    // 绘制时y略微偏移，避免微小的像素偏差
                    canvas.drawText(text, x, y - 1 - fm.top, paint);
                    
                    // 下划线
                    if (under)
                    {
                        paint.setStrokeWidth((float)1.3);
                        canvas.drawLine(x, y + h - 1, x + w, y + h - 1, paint);
                    }
                }
            }
            
            // 获取纹理数据
            byte[]  pixels = new byte[POTWide * POTHigh * 4];
            ByteBuffer buf = ByteBuffer.wrap(pixels);
            buf.order(ByteOrder.nativeOrder());
            bitmap.copyPixelsToBuffer(buf);
            
            // 回调C++
            PITextUtilAnd.nativeRender(POTWide, POTHigh, width, height, pixels);
        }
        catch (JSONException e)
        {
            Log.e("cocos2d-x", "render text error: " + e.getMessage());
            Log.e("cocos2d-x", info);
            return false;
        }
        
        return true;
    }
    
    private static native void nativeRender(int finalWide, int finalHigh, int width, int height, final byte[] pixels);
    
    /**
     * OpenGl纹理大小需要是2的整数倍，这里向上取整
     * @param {int} x
     * @return {int}
     */
    public static int nextPOT(int x)
    {
        x = x - 1;
        x = x | (x >> 1);
        x = x | (x >> 2);
        x = x | (x >> 4);
        x = x | (x >> 8);
        x = x | (x >> 16);
        return x + 1;
    }
}