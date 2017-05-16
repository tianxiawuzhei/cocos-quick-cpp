// ------------------------------------------------------------------
// PIDeviceInfoAnd
// 设备信息
package com.pinidea.shell;

import java.lang.System;
import android.content.Intent;
import android.content.Context;
import android.content.ClipboardManager;
import android.content.ClipData;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManager.MemoryInfo;
import android.net.Uri;
import android.net.NetworkInfo;
import android.net.ConnectivityManager;
import android.telephony.TelephonyManager;
import android.os.Debug;
import android.os.Looper;
import android.os.Handler;
import android.util.Log;
import android.webkit.WebView;
import android.os.Vibrator;
import android.os.Environment;
import android.view.WindowManager;
import org.cocos2dx.lib.Cocos2dxActivity;

public class PIDeviceInfoAnd {
    // ===========================================================
    // Methods
    // ===========================================================  
    /**
     * 已用的内存
     * @return {int}
     */
    public static int memory_used() {
        return (int)(Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory());
    }
    
    /**
     * 剩余的内存
     * @return {int}
     */
    public static int memory_free() {
        ActivityManager activityManager = (ActivityManager)Cocos2dxActivity.getContext().getSystemService(Context.ACTIVITY_SERVICE);
        MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        activityManager.getMemoryInfo(memoryInfo);

        return (int)memoryInfo.availMem;
    }

    /*
     * 获取CPU占用率
     */
    public static float cpu_usage() {
        // 获取CPU使用率
        // 不理想，需要线程上等待，不能立刻获取
        // try
        // {
        //     Process       process = Runtime.getRuntime().exec("top -n 1 -d 1");
        //     BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));

        //     String line = null;
        //     String name = Cocos2dxActivity.getContext().getPackageName();

        //     while ((line = reader.readLine()) != null) 
        //     {
        //         String[] split = line.split("\\s+");

        //         if ((split.length > 3) && (split[split.length - 1].equals(name)))
        //         {
        //             String percent = split[3];
        //             PIDeviceInfoAnd._cpu_usage = percent.length() > 0 ? Integer.parseInt(percent.substring(0, percent.length() - 1)) : 0;
        //             break;
        //         }
        //     }
        // }
        // catch (Exception e)
        // {
        // }
        return 0;
    }

    /**
     * 版本号
     */
    public static int version_cpp() {
        try
        {
            Context ctx = Cocos2dxActivity.getContext();
            return ctx.getPackageManager().getPackageInfo(ctx.getPackageName(), 0).versionCode;
        }
        catch (Exception e)
        {
            return 0;
        }
    }

    public static String version_short() {
        try
        {
            Context ctx = Cocos2dxActivity.getContext();
            return ctx.getPackageManager().getPackageInfo(ctx.getPackageName(), 0).versionName;
        }
        catch (Exception e)
        {
            return "";
        }
    }

    /**
     * Bundle
     */
    public static String bundle_id() {
        try
        {
            Context ctx = Cocos2dxActivity.getContext();
            return ctx.getPackageName();
        }
        catch (Exception e)
        {
            return "";
        }
    }

    public static String bundle_name() {
        try
        {
            Context ctx = Cocos2dxActivity.getContext();
            return (String)ctx.getApplicationInfo().loadLabel(ctx.getPackageManager());
        }
        catch (Exception e)
        {
            return "";
        }
    }

    /**
     * 运营商信息
     */
    public static String device_telecom() {
        TelephonyManager telephonyManager = ((TelephonyManager)Cocos2dxActivity.getContext().getSystemService(Context.TELEPHONY_SERVICE));
        return telephonyManager.getNetworkOperatorName();
    }

    /**
     * 手机机型
     */
    public static String device_hardware() {
        // http://developer.android.com/reference/android/os/Build.html
        return android.os.Build.MANUFACTURER + " " + android.os.Build.MODEL;
    }

    /**
     * 网络类型
     */
    public static String device_network() {
        // 检测是否已连接
        ConnectivityManager connectivity = (ConnectivityManager)Cocos2dxActivity.getContext().getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo info = connectivity.getActiveNetworkInfo();

        if ((info == null) || !info.isConnected())
            return "";

        // 检测是否是WIFI
        if (info.getType() == ConnectivityManager.TYPE_WIFI)
            return "WiFi";

        // 如果不是移动网络
        if (info.getType() != ConnectivityManager.TYPE_MOBILE)
            return "Unknown";

        // 检测移动网络类型：2G、3G、4G
        TelephonyManager mTelephonyManager = (TelephonyManager)Cocos2dxActivity.getContext().getSystemService(Context.TELEPHONY_SERVICE);
        int networkType = mTelephonyManager.getNetworkType();

        switch (networkType) 
        {
            case TelephonyManager.NETWORK_TYPE_GPRS:
            case TelephonyManager.NETWORK_TYPE_EDGE:
            case TelephonyManager.NETWORK_TYPE_CDMA:
            case TelephonyManager.NETWORK_TYPE_1xRTT:
            case TelephonyManager.NETWORK_TYPE_IDEN:
                return "2G";

            case TelephonyManager.NETWORK_TYPE_UMTS:
            case TelephonyManager.NETWORK_TYPE_EVDO_0:
            case TelephonyManager.NETWORK_TYPE_EVDO_A:
            case TelephonyManager.NETWORK_TYPE_HSDPA:
            case TelephonyManager.NETWORK_TYPE_HSUPA:
            case TelephonyManager.NETWORK_TYPE_HSPA:
            case TelephonyManager.NETWORK_TYPE_EVDO_B:
            case TelephonyManager.NETWORK_TYPE_EHRPD:
            case TelephonyManager.NETWORK_TYPE_HSPAP:
                return "3G";

            case TelephonyManager.NETWORK_TYPE_LTE:
                return "4G";

            default:
                return "Unknown";
        }
    }

    /**
     * 打开浏览器
     * @param {String} url
     */
    public static void open_browser(String url) {
        // MX3上下面3段代码会造成按钮抖动很多次，类似小米Pad上点击微信按钮抖动
        Intent i = new Intent(Intent.ACTION_VIEW);
        i.setData(Uri.parse(url));
        Cocos2dxActivity.getContext().startActivity(i);
    }

    /**
     * 退出游戏
     */
    public static void quit_game() {
        ((Cocos2dxActivity)Cocos2dxActivity.getContext()).finish();
        System.exit(0);
    }

    /**
     * User Agent
     */
    public static String browser_useragent() {
        try
        {
            if (PIDeviceInfoAnd._browser_useragent == "")
            {
                // 获取真正的UA，会有延迟，必须在主线程
                new Handler(Looper.getMainLooper()).post(new Runnable() {
                    public void run() {
                        try
                        {
                            PIDeviceInfoAnd._browser_useragent = new WebView(Cocos2dxActivity.getContext()).getSettings().getUserAgentString();
                        }
                        catch (Exception e)
                        {
                        }
                    }
                });

                // 在没获取到真正UA前临时给一个值
                PIDeviceInfoAnd._browser_useragent = System.getProperty("http.agent");
            }

            return PIDeviceInfoAnd._browser_useragent != null ? PIDeviceInfoAnd._browser_useragent : "";
        }
        catch (Exception e)
        {
            return "";
        }
    }

    /**
     * 振动
     */
    public static void vibrate() {
        Vibrator v = (Vibrator)Cocos2dxActivity.getContext().getSystemService(Context.VIBRATOR_SERVICE);
        v.vibrate(400);
    }

    /**
     * 唤醒
     */
    public static void keep_awake(final boolean keep) {
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                if (keep)
                    ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
                else
                    ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getWindow().clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
            }
        });                
    }

    /**
     * 键盘
     */
    public static boolean keyboard_exist() {
        return ((Cocos2dxActivity)Cocos2dxActivity.getContext()).keyboard_exist();
    }

    public static void keyboard_close() {
        ((Cocos2dxActivity)Cocos2dxActivity.getContext()).keyboard_close();
    }

    /**
     * 剪贴板
     */
    public static void clipboard(final String text) {
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @SuppressLint("NewApi")
			public void run() {
                ClipboardManager clipboard = (ClipboardManager)Cocos2dxActivity.getContext().getSystemService(Context.CLIPBOARD_SERVICE); 
                ClipData clip = ClipData.newPlainText(text, text);
                clipboard.setPrimaryClip(clip);
            }
        });                
    }

    /**
     * 安卓外部存储路径
     */
    public static String external_path() {
        if (Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED))
            return Environment.getExternalStorageDirectory().toString();
        else
            return "";
    }

    // members
    private static String _browser_useragent = "";
}