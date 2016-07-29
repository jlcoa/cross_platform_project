package com.mx3;

import com.nextuc.ICoreApp;
import com.nextuc.IPalBundle;
import com.nextuc.IXplatformApplication;

/**
 * Created by coa.ke on 7/28/16.
 */

public class CoreAppImplement implements ICoreApp {
    @Override
    public void initCore() {
        IPalBundle palBundle = new PalBundleImplement();
        IXplatformApplication.sharedApplication().initApp(palBundle);
    }

    @Override
    public IXplatformApplication sharedApplication() {
        return IXplatformApplication.sharedApplication();
    }
}
