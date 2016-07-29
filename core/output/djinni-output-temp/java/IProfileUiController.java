// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class IProfileUiController {
    public abstract IProfileViewModel getViewModel();

    public abstract void updateAvatar(RAvatarInfo avatarInfo, IActionCallback callback);

    public abstract void requestUploadToken(IRequestUploadTokenCallback callback);

    public abstract void signout(IActionCallback callback);

    private static final class CppProxy extends IProfileUiController
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
        public IProfileViewModel getViewModel()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getViewModel(this.nativeRef);
        }
        private native IProfileViewModel native_getViewModel(long _nativeRef);

        @Override
        public void updateAvatar(RAvatarInfo avatarInfo, IActionCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_updateAvatar(this.nativeRef, avatarInfo, callback);
        }
        private native void native_updateAvatar(long _nativeRef, RAvatarInfo avatarInfo, IActionCallback callback);

        @Override
        public void requestUploadToken(IRequestUploadTokenCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_requestUploadToken(this.nativeRef, callback);
        }
        private native void native_requestUploadToken(long _nativeRef, IRequestUploadTokenCallback callback);

        @Override
        public void signout(IActionCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_signout(this.nativeRef, callback);
        }
        private native void native_signout(long _nativeRef, IActionCallback callback);
    }
}
