package com.mx3;

import com.nextuc.IFileStorageProvider;
import com.nextuc.ILog;
import com.nextuc.INetworkProvider;
import com.nextuc.INetworkStatusProvider;
import com.nextuc.IPalBundle;
import com.nextuc.ITaskDispatcher;

/**
 * Created by coa.ke on 7/28/16.
 */

public class PalBundleImplement extends IPalBundle {
    @Override
    public INetworkProvider getNetworkProvider() {
        return null;
    }

    @Override
    public ILog getLog() {
        return null;
    }

    @Override
    public IFileStorageProvider getFileStorageProvider() {
        return new FileStorageProviderImplement();
    }

    @Override
    public INetworkStatusProvider getNetworkStatusProvider() {
        return null;
    }

    @Override
    public ITaskDispatcher getTaskDispatcher() {
        return null;
    }
}
