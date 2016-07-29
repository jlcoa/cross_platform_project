// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

/**# login */
public abstract class ILoginViewModel {
    public abstract String getUserName();

    public abstract void setUserName(String userName);

    public abstract String getPassword();

    public abstract void setPassword(String password);

    public abstract void setStatus(ELoginStatus status);

    public abstract ELoginStatus getStatus();

    public abstract boolean isLoading();

    public abstract void setLoading(boolean loading);

    private static final class CppProxy extends ILoginViewModel
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
        public String getUserName()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getUserName(this.nativeRef);
        }
        private native String native_getUserName(long _nativeRef);

        @Override
        public void setUserName(String userName)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setUserName(this.nativeRef, userName);
        }
        private native void native_setUserName(long _nativeRef, String userName);

        @Override
        public String getPassword()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getPassword(this.nativeRef);
        }
        private native String native_getPassword(long _nativeRef);

        @Override
        public void setPassword(String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setPassword(this.nativeRef, password);
        }
        private native void native_setPassword(long _nativeRef, String password);

        @Override
        public void setStatus(ELoginStatus status)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setStatus(this.nativeRef, status);
        }
        private native void native_setStatus(long _nativeRef, ELoginStatus status);

        @Override
        public ELoginStatus getStatus()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getStatus(this.nativeRef);
        }
        private native ELoginStatus native_getStatus(long _nativeRef);

        @Override
        public boolean isLoading()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_isLoading(this.nativeRef);
        }
        private native boolean native_isLoading(long _nativeRef);

        @Override
        public void setLoading(boolean loading)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setLoading(this.nativeRef, loading);
        }
        private native void native_setLoading(long _nativeRef, boolean loading);
    }
}