// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class ISignupUiController {
    public abstract void signup(String userName, String password, String firstName, String lastName, IActionCallback callback);

    private static final class CppProxy extends ISignupUiController
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
        public void signup(String userName, String password, String firstName, String lastName, IActionCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_signup(this.nativeRef, userName, password, firstName, lastName, callback);
        }
        private native void native_signup(long _nativeRef, String userName, String password, String firstName, String lastName, IActionCallback callback);
    }
}
