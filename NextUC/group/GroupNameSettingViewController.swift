//
//  GroupNameSettingViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/28/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

class GroupNameSettingViewController: UIViewController, CoreIViewModelDelegate, CoreIGroupCallback {

    @IBOutlet weak var groupName: UITextField!
    
    var group: CoreRGroup?
    
    var groupUpdateUiController: CoreIGroupUpdateUiController?
    
    var delegate: ViewModelDelegate?
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        delegate = ViewModelDelegate(delegate: self)
        
        groupUpdateUiController = getUiControllerFactory().createGroupUpdateUiController(delegate)
        
        groupUpdateUiController?.getViewModel()?.setGroup(group!)
        
        refreshUI()
    }
    
    func refreshUI() {
        groupName.text = groupUpdateUiController?.getViewModel()?.getGroup().groupName
    }

    @objc func onDataChanged() {
//        refreshUI()
    }
    
    @objc func onGroupUpdated(updatedGroup: CoreRGroup, code: CoreECallbackResult) {
        
        hideLoading()
        
        if code == CoreECallbackResult.Success {
             self.navigationController?.popViewControllerAnimated(true)
        }
    }
    
    @IBAction func updateTapped(sender: AnyObject) {
        
        showLoading()
        
        groupUpdateUiController?.updateGroupName(groupName.text!, callback: self)
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
