//
//  GroupMembersTableViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/28/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

class GroupMembersTableViewController: UITableViewController, CoreIViewModelDelegate, ContactSelectionDelegate, CoreIGroupCallback {
    
    var uiController: CoreIGroupMemberUiController?
    
    var delegate: ViewModelDelegate?
    
    var group:CoreRGroup?
    
    var isInEditing = false
    
    @objc func onDataChanged() {
        tableView.reloadData()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
        
//        self.navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Add, target: self, action: "addMember:")
        
//        self.navigationItem.rightBarButtonItems = [UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Edit, target: self, action: "editMember:"), UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Add, target: self, action: "addMember:")];
        
        updateMode();
        
        delegate = ViewModelDelegate(delegate: self)
        
        uiController = getUiControllerFactory().createGroupMemberUiController(delegate)
        uiController?.loadData(group!)
    }
    
    func addMember(sender: AnyObject?) {
        self.performSegueWithIdentifier("addMember", sender: self)
    }
    
    func updateMode() {
        
        if isInEditing {
            
            self.navigationItem.rightBarButtonItems = [UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Done, target: self, action: "doneEdit:")];
            
            self.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Cancel, target: self, action: "cancelEdit:");
            
            self.tableView.allowsMultipleSelection = true
        }
        else {
             self.navigationItem.rightBarButtonItems = [UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Edit, target: self, action: "editMember:"), UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Add, target: self, action: "addMember:")];
            self.navigationItem.leftBarButtonItem = self.navigationItem.backBarButtonItem
            
            self.tableView.allowsMultipleSelection = false
        }
    }
    
    func doneEdit (sender: AnyObject?) {
        
        isInEditing = false
        
        
        var selectedContacts = [String]()
        
        for indexPath in tableView.indexPathsForSelectedRows! {
            let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
            selectedContacts.append((model?.id)!)
        }
        
        updateMode()
        
        if !selectedContacts.isEmpty {
            showLoading()
            uiController?.removeMembers(selectedContacts, callback: self)
        }
        
    }
    
    func cancelEdit (sender: AnyObject?) {
        isInEditing = false
        updateMode()
    }
    
    func editMember(sender: AnyObject?) {
        isInEditing = true
        updateMode()
    }
    
    // MARK: - Table view data source
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (Int)((uiController?.getViewModel()?.getDataSource()?.numberOfRowsInSection((Int32)(section)))!)
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCellWithIdentifier("ContactTableViewCell", forIndexPath: indexPath) as! ContactTableViewCell
        
        let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
        
        cell.name.text = model?.displayName
        
        return cell
    }
    
    
    /*
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
    let cell = tableView.dequeueReusableCellWithIdentifier("reuseIdentifier", forIndexPath: indexPath)
    
    // Configure the cell...
    
    return cell
    }
    */
    
    /*
    // Override to support conditional editing of the table view.
    override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
    // Return false if you do not want the specified item to be editable.
    return true
    }
    */
    
    /*
    // Override to support editing the table view.
    override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
    if editingStyle == .Delete {
    // Delete the row from the data source
    tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
    } else if editingStyle == .Insert {
    // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }
    }
    */
    
    /*
    // Override to support rearranging the table view.
    override func tableView(tableView: UITableView, moveRowAtIndexPath fromIndexPath: NSIndexPath, toIndexPath: NSIndexPath) {
    
    }
    */
    
    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(tableView: UITableView, canMoveRowAtIndexPath indexPath: NSIndexPath) -> Bool {
    // Return false if you do not want the item to be re-orderable.
    return true
    }
    */
    
    
    // MARK: - Navigation
    
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
    // Get the new view controller using segue.destinationViewController.
    // Pass the selected object to the new view controller.
        
        if (segue.identifier == "addMember") {
            
            let vc = segue.destinationViewController as! ContactTableViewController
            vc.multiSelection = true
            vc.selectionDelegate = self
        }
    }
    
    @objc func onGroupUpdated(group: CoreRGroup, code: CoreECallbackResult) {
        
        hideLoading()
        
        tableView.reloadData()
    }
    
    func onContactSelected(contacts: [CoreRContact]) {
        
        var selectedContacts = [String]()
        for model in contacts {
            selectedContacts.append(model.id!)
        }
        
        showLoading()
        
        uiController?.addMembers(selectedContacts, callback: self)
    }
    
}
