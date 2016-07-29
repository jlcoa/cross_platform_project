// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

package com.nextuc;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class IGroupMemberViewModel {
    public abstract void setDataSource(IContactTableDataSource dataSource);

    public abstract IContactTableDataSource getDataSource();

    public abstract void setGroup(RGroup group);

    public abstract RGroup getGroup();

    private static final class CppProxy extends IGroupMemberViewModel
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
        public void setDataSource(IContactTableDataSource dataSource)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setDataSource(this.nativeRef, dataSource);
        }
        private native void native_setDataSource(long _nativeRef, IContactTableDataSource dataSource);

        @Override
        public IContactTableDataSource getDataSource()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDataSource(this.nativeRef);
        }
        private native IContactTableDataSource native_getDataSource(long _nativeRef);

        @Override
        public void setGroup(RGroup group)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setGroup(this.nativeRef, group);
        }
        private native void native_setGroup(long _nativeRef, RGroup group);

        @Override
        public RGroup getGroup()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getGroup(this.nativeRef);
        }
        private native RGroup native_getGroup(long _nativeRef);
    }
}
