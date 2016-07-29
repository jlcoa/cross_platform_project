//
//  AppDelegate.swift
//  NextUC
//
//  Created by Steve Chen on 1/24/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, CoreILifecyleViewModelDelegate, CoreIDataChangeDelegate, RCIMUserInfoDataSource, RCIMGroupInfoDataSource, RCIMReceiveMessageDelegate {

    var window: UIWindow?
    
    let rongcloudIMAppkey = "0vnjpoadnw3zz"
    
    var lifecycleUiController: CoreILifecycleUiController?
    
    var dataProvider: CoreIDataProvider?

    func initCore() {
        
        CoreApp.initCore()
        
        dataProvider = CoreApp.sharedApplication().getDataProvider()
        dataProvider?.setDelegate(self)
    }
    
    func initRongYun() {
        
        RCIM.sharedRCIM().initWithAppKey(rongcloudIMAppkey)
        
        //设置监听连接状态
//        RCIM.sharedRCIM().connectionStatusDelegate = self
//        //设置消息接收的监听
        RCIM.sharedRCIM().receiveMessageDelegate = self
//
        //设置用户信息提供者，需要提供正确的用户信息，否则SDK无法显示用户头像、用户名和本地通知
        RCIM.sharedRCIM().userInfoDataSource = self
        //设置群组信息提供者，需要提供正确的群组信息，否则SDK无法显示群组头像、群名称和本地通知
        RCIM.sharedRCIM().groupInfoDataSource = self
        
       
        
//        RCIMClient.sharedRCIMClient().setReceiveMessageDelegate(self, object: nil)
        
        
    }
    
    func startApp() {
        
        initCore()
        
        let uiControllerFactory = CoreApp.sharedApplication().getUiControllerFactory()
        lifecycleUiController = uiControllerFactory?.createLifecycleUiController(self)
        lifecycleUiController?.start()
    }
    
    func onAccountStatusChanged(status: CoreEAccountStatus) {
        
        if(status == CoreEAccountStatus.NotLoggedIn) {
            showLogin()
        }
        else if(status == CoreEAccountStatus.LoggedIn) {
            loginRongCloud()
            showMain()
        }
    }
    
    func switch2StoryBoard(name: String!) {
        let storyBoard: UIStoryboard = UIStoryboard(name:name, bundle: nil)
        let viewController = storyBoard.instantiateInitialViewController()
        self.window?.rootViewController = viewController
    }
    
    func showLogin() {
        switch2StoryBoard("Login")
    }
    
    func showMain() {
        switch2StoryBoard("Main")
    }
    
    func loginRongCloud() {
        //登录融云服务器的token。需要您向您的服务器请求，您的服务器调用server api获取token
        //开发初始阶段，您可以先在融云后台API调试中获取
        let token = lifecycleUiController?.getAccountInfo().user.rongCloudToken
        
        //连接融云服务器
        RCIM.sharedRCIM().connectWithToken(token,
            success: { (userId) -> Void in
                print("登陆成功。当前登录的用户ID：\(userId)")
                
                //设置当前登陆用户的信息
                RCIM.sharedRCIM().currentUserInfo = RCUserInfo.init(userId: userId, name: self.lifecycleUiController?.getAccountInfo().user.displayName, portrait: self.lifecycleUiController?.getAccountInfo().user.avatarUrl)
                
                dispatch_sync(dispatch_get_main_queue(), { () -> Void in
                    //打开会话列表
//                    let chatListView = DemoChatListViewController()
//                    self.navigationController?.pushViewController(chatListView, animated: true)
                })
            }, error: { (status) -> Void in
                print("登陆的错误码为:\(status.rawValue)")
            }, tokenIncorrect: {
                //token过期或者不正确。
                //如果设置了token有效期并且token过期，请重新请求您的服务器获取新的token
                //如果没有设置token有效期却提示token错误，请检查您客户端和服务器的appkey是否匹配，还有检查您获取token的流程。
                print("token错误")
        })
    }
    
    func onGroupChanged(group: CoreRGroup) {
        
        let gp = RCGroup()
        gp.groupId = group.id
        gp.groupName = group.groupName
        RCIM.sharedRCIM().refreshGroupInfoCache(gp, withGroupId: group.id);
    }
    
    func onContactChanged(contact: CoreRContact) {
         let user = RCUserInfo()
        user.userId = contact.id
        user.name = contact.displayName
        user.portraitUri = contact.avatarUrl
        RCIM.sharedRCIM().refreshUserInfoCache(user, withUserId: contact.id)
    }
    
    
    func onRCIMReceiveMessage(message: RCMessage!, left: Int32) {
        print("onRCIMReceiveMessage------\(message.content), \(message.objectName)")
        
        let cmMessage = message.content as? RCCommandMessage;
        
        if cmMessage != nil {
            print("cmd message: \(cmMessage!.data),  \(cmMessage!.name)");
            
            dataProvider?.hasGroup("");
            dataProvider?.hasContact("");
        }
    }
    
    //用户信息提供者。您需要在completion中返回userId对应的用户信息，SDK将根据您提供的信息显示头像和用户名
    func getUserInfoWithUserId(userId: String!, completion: ((RCUserInfo!) -> Void)!) {
        print("用户信息提供者，getUserInfoWithUserId:\(userId)")
        
        
        let user = RCUserInfo()
        
        if dataProvider!.hasContact(userId) {
            let contact = dataProvider?.getContact(userId)
            user.userId = contact?.id
            user.name = contact?.displayName
            user.portraitUri = contact?.avatarUrl
        }
        
        return completion(user)
        
//        RCUserInfo *user = [[RCUserInfo alloc]init];
//        user.userId = viewModel.contactModel.userId;
//        user.name = viewModel.contactModel.displayName;
//        return completion(user);
//        
//        //简单的示例，根据userId获取对应的用户信息并返回
//        //建议您在本地做一个缓存，只有缓存没有该用户信息的情况下，才去您的服务器获取，以提高用户体验
//        if (userId == "me") {
//            //如果您提供的头像地址是http连接，在iOS9以上的系统中，请设置使用http，否则无法正常显示
//            //具体可以参考Info.plist中"App Transport Security Settings->Allow Arbitrary Loads"
//            completion(RCUserInfo(userId: userId, name: "我的名字", portrait: "http://www.rongcloud.cn/images/newVersion/logo/baixing.png"))
//        } else if (userId == "you") {
//            completion(RCUserInfo(userId: userId, name: "你的名字", portrait: "http://www.rongcloud.cn/images/newVersion/logo/qichezc.png"))
//        } else {
//            completion(RCUserInfo(userId: userId, name: "unknown", portrait: "http://www.rongcloud.cn/images/newVersion/logo/douguo.png"))
//        }
    }
    
    //群组信息提供者。您需要在Block中返回groupId对应的群组信息，SDK将根据您提供的信息显示头像和群组名
    func getGroupInfoWithGroupId(groupId: String!, completion: ((RCGroup!) -> Void)!) {
        print("群组信息提供者，getGroupInfoWithGroupId:\(groupId)")
        
        let gp = RCGroup()
        gp.groupId = groupId
        
        if dataProvider!.hasGroup(groupId)  {
            let group = dataProvider?.getGroup(groupId)
            gp.groupName = group?.groupName
            return completion(gp)
        }
        else {
            gp.groupName = "deactive group"
        }
        return completion(gp)
    }

    func setpCrashReport() {
        KSCrashInstallationStandard.sharedInstance().url = NSURL(string: "https://collector.bughd.com/kscrash?key=c6f8c598f9f2aa69d530621e8716789f")
        KSCrashInstallationStandard.sharedInstance().install()
        KSCrashInstallationStandard.sharedInstance().sendAllReportsWithCompletion(nil)
    }

    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        
//        let textAttributes = [NSFontAttributeName: UIFont.systemFontOfSize(19.0), NSForegroundColorAttributeName: UIColor.whiteColor()]
//        UINavigationBar.appearance().titleTextAttributes = textAttributes
//        UINavigationBar.appearance().tintColor = UIColor.whiteColor()
//        UINavigationBar.appearance().barTintColor = UIColor.redColor()
        
//        let documentsFolder = NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory.DocumentDirectory, NSSearchPathDomainMask.UserDomainMask, true).last
//        
//        let file = "\(documentsFolder!)/nextuc"
//        
//        let fileManager = NSFileManager.defaultManager()
//        if !fileManager.fileExistsAtPath(file) {
//            
//            do {
//                try fileManager.createDirectoryAtPath(file, withIntermediateDirectories: false, attributes: nil)
//            }
//            catch let error as NSError {
//                print("\(error)")
//            }
//        }
//        
//        let httpImpl = CoreHttpObjc()
//        let uiThread = CoreEventLoopObjc()
//        let launcher = CoreThreadLauncherObjc()
//        
//        let api = CoreApi.createApi(file, uiThread: uiThread, httpImpl: httpImpl, launcher: launcher)
//        
//        if (!api!.hasUser()) {
//            api?.setUsername("djinni demo")
//        }
//        
//        testCore()
        
        // Register Notifications
        let notificationTypes: UIUserNotificationType = [UIUserNotificationType.Alert, UIUserNotificationType.Badge, UIUserNotificationType.Sound]
        let pushNotificationSettings = UIUserNotificationSettings(forTypes: notificationTypes, categories: nil)
        
        application.registerUserNotificationSettings(pushNotificationSettings)
        application.registerForRemoteNotifications()
        
        setpCrashReport();
        
        initRongYun();
        
        startApp();
        
        return true
    }

    func applicationWillResignActive(application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }

    func application(application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: NSData) {
        print("DEVICE TOKEN = \(deviceToken)")
        
        let token = deviceToken.description.stringByReplacingOccurrencesOfString("<", withString: "").stringByReplacingOccurrencesOfString(">", withString: "").stringByReplacingOccurrencesOfString(" ", withString: "")
        
        print("DEVICE TOKEN to RongCloud = \(token)")

        
        RCIMClient.sharedRCIMClient().setDeviceToken(token)
    }
    
    func application(application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: NSError) {
        print(error)
    }
    
    func application(application: UIApplication, didReceiveRemoteNotification userInfo: [NSObject : AnyObject]) {
        print(userInfo)
    }

}

