//
//  GroupTableViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/21/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

class GroupTableViewController: UITableViewController, CoreIViewModelDelegate {
    
    var uiController: CoreIGroupUiController?
    
    var delegate: ViewModelDelegate?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        delegate = ViewModelDelegate(delegate: self)
            
        uiController = getUiControllerFactory().createGroupUiController(delegate)
        
        self.tabBarController?.tabBar.translucent = false
        self.tabBarController?.navigationController?.navigationBar.translucent = false
        
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        setNavigationBar()
    }
    
    func setNavigationBar() {
        tabBarController?.navigationItem.titleView = customizedTitleView("Team")
        tabBarController?.navigationItem.rightBarButtonItem = nil;
    }
    
    @objc func onDataChanged() {
        tableView.reloadData()
    }
    
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (Int)((uiController?.getViewModel()?.getDataSource()?.numberOfRowsInSection((Int32)(section)))!)
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCellWithIdentifier("GroupTableViewCell", forIndexPath: indexPath) as! GroupTableViewCell
        
        let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
        
        cell.name.text = model?.groupName
        
        return cell
    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
        tabBarController?.navigationController?.pushViewController(ViewUtils.createTeam(model!), animated: true)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
        
        if (segue.identifier == "groupSetting") {
            
            let indexPath = self.tableView.indexPathForCell(sender as! UITableViewCell)
            
            let vc = segue.destinationViewController as! GroupSettingViewController
            
            let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath!.section), row: (Int32)(indexPath!.row))
            
            vc.group = model
        }
    }
    
}
