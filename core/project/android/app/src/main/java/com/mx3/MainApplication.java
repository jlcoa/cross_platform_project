package com.mx3;

import android.app.Application;
import android.content.Intent;

import com.nextuc.EAccountStatus;
import com.nextuc.ICoreApp;
import com.nextuc.IDataChangeDelegate;
import com.nextuc.IDataProvider;
import com.nextuc.ILifecycleUiController;
import com.nextuc.ILifecyleViewModelDelegate;
import com.nextuc.IUiControllerFactory;
import com.nextuc.RContact;
import com.nextuc.RGroup;

import uicontroler.LoginViewController;

/**
 * Created by coa.ke on 7/28/16.
 */

public class MainApplication extends Application implements ILifecyleViewModelDelegate, IDataChangeDelegate {

    private IDataProvider dataProvider;
    private ICoreApp coreApp;

    static {
        System.loadLibrary("core_android");
    }

    @Override
    public void onCreate() {
        super.onCreate();
        startApp();
        showLogin();
    }



    private void initCore() {

        coreApp = new CoreAppImplement();
        coreApp.initCore();

        dataProvider = coreApp.sharedApplication().getDataProvider();
        dataProvider.setDelegate(this);
    }

    private void startApp() {

        initCore();

        IUiControllerFactory uiControllerFactory = coreApp.sharedApplication().getUiControllerFactory();
        ILifecycleUiController lifecycleUiController = uiControllerFactory.createLifecycleUiController(this);
        lifecycleUiController.start();
    }

    private void showLogin() {
        Intent intent = new Intent();
        intent.setClass(this, LoginViewController.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        this.startActivity(intent);
    }


    @Override
    public void onAccountStatusChanged(EAccountStatus status) {

    }

    @Override
    public void onContactChanged(RContact contact) {

    }

    @Override
    public void onGroupChanged(RGroup group) {

    }
}
