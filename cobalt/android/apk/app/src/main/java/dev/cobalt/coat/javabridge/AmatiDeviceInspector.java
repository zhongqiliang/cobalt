package dev.cobalt.coat.javabridge;

import static dev.cobalt.util.Log.TAG;

import android.content.Context;
import android.util.Log;

/**
 * A simple example of implement CobaltJavaScriptAndroidObject.
 */
public class AmatiDeviceInspector implements CobaltJavaScriptAndroidObject {

    private final Context context;

    public AmatiDeviceInspector(Context context) {
        this.context = context;
    }

    @Override
    public String getJavaScriptInterfaceName() {
        return "Android_AmatiDeviceInspector";
    }

    @Override
    public String getJavaScriptAssetName() {
        return "amati_device_inspector.js";
    }

    @CobaltJavaScriptInterface
    public void printIsAmatiDevice() {
        boolean isAmatiDevice = context.getPackageManager().hasSystemFeature("com.google.android.feature.AMATI_EXPERIENCE");
        Log.i(TAG, "It is running on an Amati device? " + isAmatiDevice);
    }
}
