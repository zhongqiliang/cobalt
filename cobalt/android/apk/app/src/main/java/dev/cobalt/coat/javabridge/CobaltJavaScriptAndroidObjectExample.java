package dev.cobalt.coat.javabridge;

import static dev.cobalt.util.Log.TAG;

import android.content.Context;
import android.util.Log;

/**
 * A simple example of implement CobaltJavaScriptAndroidObject.
 */
public class CobaltJavaScriptAndroidObjectExample implements CobaltJavaScriptAndroidObject {

    private final Context context;

    public CobaltJavaScriptAndroidObjectExample(Context context) {
        this.context = context;
    }

    @Override
    public String getJavaScriptInterfaceName() {
        return "AndroidExample";
    }

    @Override
    public String getJavaScriptAssetName() {
        return "example.js";
    }

    @CobaltJavaScriptInterface
    public void testJavaScriptMethod() {
        Log.i(TAG, "Hello world");
    }

    @CobaltJavaScriptInterface
    public void printIsAmatiDevice() {
        boolean isAmatiDevice = context.getPackageManager().hasSystemFeature("com.google.android.feature.AMATI_EXPERIENCE");
        Log.i(TAG, "It is running on an Amati device? " + isAmatiDevice);
    }
}
