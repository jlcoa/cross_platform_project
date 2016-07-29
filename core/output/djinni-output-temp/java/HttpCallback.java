// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class HttpCallback {
    public abstract void onNetworkError();

    public abstract void onSuccess(short httpCode, String data);

    private static final class CppProxy extends HttpCallback
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public void onNetworkError()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_onNetworkError(this.nativeRef);
        }
        private native void native_onNetworkError(long _nativeRef);

        @Override
        public void onSuccess(short httpCode, String data)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_onSuccess(this.nativeRef, httpCode, data);
        }
        private native void native_onSuccess(long _nativeRef, short httpCode, String data);
    }
}
