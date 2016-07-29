// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class INetworkStatusDelegate {
    public abstract void onNetworkStatusChanged(ENetworkStatus status);

    private static final class CppProxy extends INetworkStatusDelegate
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
        public void onNetworkStatusChanged(ENetworkStatus status)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_onNetworkStatusChanged(this.nativeRef, status);
        }
        private native void native_onNetworkStatusChanged(long _nativeRef, ENetworkStatus status);
    }
}
