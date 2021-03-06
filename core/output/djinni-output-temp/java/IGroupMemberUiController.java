// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class IGroupMemberUiController {
    public abstract IGroupMemberViewModel getViewModel();

    public abstract void loadData(RGroup group);

    public abstract void addMembers(ArrayList<String> memberIds, IGroupCallback callback);

    public abstract void removeMembers(ArrayList<String> memberIds, IGroupCallback callback);

    private static final class CppProxy extends IGroupMemberUiController
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
        public IGroupMemberViewModel getViewModel()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getViewModel(this.nativeRef);
        }
        private native IGroupMemberViewModel native_getViewModel(long _nativeRef);

        @Override
        public void loadData(RGroup group)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_loadData(this.nativeRef, group);
        }
        private native void native_loadData(long _nativeRef, RGroup group);

        @Override
        public void addMembers(ArrayList<String> memberIds, IGroupCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_addMembers(this.nativeRef, memberIds, callback);
        }
        private native void native_addMembers(long _nativeRef, ArrayList<String> memberIds, IGroupCallback callback);

        @Override
        public void removeMembers(ArrayList<String> memberIds, IGroupCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_removeMembers(this.nativeRef, memberIds, callback);
        }
        private native void native_removeMembers(long _nativeRef, ArrayList<String> memberIds, IGroupCallback callback);
    }
}
