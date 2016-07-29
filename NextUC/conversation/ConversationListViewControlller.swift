//
//  ConversationListViewControlller.swift
//  NextUC
//
//  Created by Steve Chen on 2/20/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

class ConversationListViewControlller: RCConversationListViewController, ContactSelectionDelegate, CoreIViewModelDelegate, CoreIGroupCallback {
    
    var groupCreateUiController: CoreIGroupCreateUiController?
    
    var delegate: ViewModelDelegate?
    
    override func viewDidLoad() {
        //重写显示相关的接口，必须先调用super，否则会屏蔽SDK默认的处理
        super.viewDidLoad()
        
        //设置需要显示哪些类型的会话
        self.setDisplayConversationTypes([RCConversationType.ConversationType_PRIVATE.rawValue,
            RCConversationType.ConversationType_DISCUSSION.rawValue,
            RCConversationType.ConversationType_CHATROOM.rawValue,
            RCConversationType.ConversationType_GROUP.rawValue,
            RCConversationType.ConversationType_APPSERVICE.rawValue,
            RCConversationType.ConversationType_SYSTEM.rawValue])
        //设置需要将哪些类型的会话在会话列表中聚合显示
//        self.setCollectionConversationType([RCConversationType.ConversationType_DISCUSSION.rawValue,
//            RCConversationType.ConversationType_GROUP.rawValue])
        
        self.conversationListTableView.separatorColor = UIColor.clearColor()
        self.conversationListTableView.tableFooterView = UIView()
        
    }
    
    func newChat() {
        self.performSegueWithIdentifier("selectContact", sender: self)
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        let rightBtn = UIButton(frame: CGRectMake(0, 0, 17, 17))
        rightBtn.setImage(UIImage(named:"add"), forState: UIControlState.Normal)
        rightBtn.addTarget(self, action: "newChat", forControlEvents: UIControlEvents.TouchUpInside)
        
        let rightBarBtn = UIBarButtonItem(customView: rightBtn)
        rightBarBtn.tintColor = UIColor.blueColor()
        self.tabBarController?.navigationItem.rightBarButtonItem = rightBarBtn
        
        notifyUpdateUnreadMessageCount()
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "receiveNeedRefreshNotification:", name: "kRCNeedReloadDiscussionListNotification", object: nil)
    }
    
    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        
        setNavigationItemTitleView()
        
        showConnectingStatusOnNavigatorBar = true
        
        updateConnectionStatusOnNavigatorBar()
    }
    
    override func viewWillDisappear(animated: Bool) {
        super.viewWillDisappear(animated)
        
        showConnectingStatusOnNavigatorBar = false
        NSNotificationCenter.defaultCenter().removeObserver(self, name: "kRCNeedReloadDiscussionListNotification", object: nil)
    }

    override func setNavigationItemTitleView() {
        
        if (self.isEnteredToCollectionViewController) {
            return
        }
        
        tabBarController?.navigationItem.titleView = customizedTitleView("Conversation")
    }
    
    override func onSelectedTableRow(conversationModelType: RCConversationModelType, conversationModel model: RCConversationModel!, atIndexPath indexPath: NSIndexPath!) {
        
        let conversationVC = RCConversationViewController()
        conversationVC.conversationType = model.conversationType
        conversationVC.targetId = model.targetId;
        conversationVC.userName = model.conversationTitle;
        conversationVC.title = model.conversationTitle;
        conversationVC.unReadMessage = model.unreadMessageCount;
        conversationVC.enableNewComingMessageIcon = true;
        conversationVC.enableUnreadMessageIcon = true;
        
        tabBarController?.navigationController?.pushViewController(conversationVC, animated: true)
    }
    
    
//    - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
//    // Get the new view controller using [segue destinationViewController].
//    // Pass the selected object to the new view controller.
//    
//    if([segue.identifier isEqualToString:@"selectContact"]) {
//    ContactListViewController *controller = (ContactListViewController *)segue.destinationViewController;
//    controller.viewModel.isMultiSelection = YES;
//    controller.delegate = self;
//    }
//    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if (segue.identifier == "selectContact") {
            
            let vc = segue.destinationViewController as! ContactTableViewController
            vc.multiSelection = true
            vc.selectionDelegate = self
        }
    }
    
    @objc func onDataChanged() {
        
    }
    
    @objc func onGroupUpdated (group: CoreRGroup, code: CoreECallbackResult) {
        
        hideLoading()
        
        if code == CoreECallbackResult.Success {
            tabBarController?.navigationController?.pushViewController(ViewUtils.createTeam(group), animated: true)
        }
    }
    
    func onContactSelected(contacts: [CoreRContact]) {
        
        if contacts.count == 1 {
            tabBarController?.navigationController?.pushViewController(ViewUtils.createP2P(contacts[0]), animated: true)
        }
        else if(contacts.count > 1) {
            if groupCreateUiController == nil {
                
                delegate = ViewModelDelegate(delegate: self)
                groupCreateUiController = getUiControllerFactory().createGroupCreateUiController(delegate)
            }
            
            showLoading()
            groupCreateUiController?.createGroup(contacts, callback: self);
        }
        
    }
    
}
