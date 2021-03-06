// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class IProfileViewModel {
    public abstract void setAccount(RAccount account);

    public abstract RAccount getAccount();

    private static final class CppProxy extends IProfileViewModel
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
        public void setAccount(RAccount account)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setAccount(this.nativeRef, account);
        }
        private native void native_setAccount(long _nativeRef, RAccount account);

        @Override
        public RAccount getAccount()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getAccount(this.nativeRef);
        }
        private native RAccount native_getAccount(long _nativeRef);
    }
}
