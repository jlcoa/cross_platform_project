//
//  GroupSettingViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/28/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

class GroupSettingViewController: UITableViewController, CoreIViewModelDelegate, CoreIActionCallback {

    var group: CoreRGroup?
    
    var uiController: CoreIGroupDetailUiController?
    
    var delegate: ViewModelDelegate?
    
    @objc func onDataChanged() {
        
    }
    
    @objc func onResponse(result: CoreRActionResult) {
        
        hideLoading()
        
        if result.result == CoreECallbackResult.Success {
            self.navigationController?.popViewControllerAnimated(true)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        delegate = ViewModelDelegate(delegate: self)
        
        uiController = getUiControllerFactory().createGroupDetailUiController(delegate);
        uiController?.setGroup(group!);
    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        if indexPath.row == 2 {
            showLoading()
            uiController?.quit(self)
        }

    }

    
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
        
        if (segue.identifier == "updateGroupName") {
            
            let vc = segue.destinationViewController as! GroupNameSettingViewController
            vc.group = uiController?.getViewModel()?.getGroup()
        }
        else if(segue.identifier == "groupMember") {
            let vc = segue.destinationViewController as! GroupMembersTableViewController
            vc.group = uiController?.getViewModel()?.getGroup()
        }
    }
    

}
