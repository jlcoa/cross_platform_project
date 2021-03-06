// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class IGroupUpdateUiController {
    public abstract void updateGroupName(String groupName, IGroupCallback callback);

    public abstract IGroupUpdateViewModel getViewModel();

    private static final class CppProxy extends IGroupUpdateUiController
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
        public void updateGroupName(String groupName, IGroupCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_updateGroupName(this.nativeRef, groupName, callback);
        }
        private native void native_updateGroupName(long _nativeRef, String groupName, IGroupCallback callback);

        @Override
        public IGroupUpdateViewModel getViewModel()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getViewModel(this.nativeRef);
        }
        private native IGroupUpdateViewModel native_getViewModel(long _nativeRef);
    }
}
