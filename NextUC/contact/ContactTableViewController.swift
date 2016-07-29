//
//  ConversationTableViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/21/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit
import Kingfisher

protocol ContactSelectionDelegate: class {
    
    func onContactSelected(contacts: [CoreRContact])
    
}

class ContactTableViewController: UITableViewController, CoreIViewModelDelegate {
    
    var uiController: CoreIContactUiController?
    
    var multiSelection = false
    
    var selectDoneBarItem: UIBarButtonItem?
    
    weak var selectionDelegate: ContactSelectionDelegate?
    
    var delegate: CoreIViewModelDelegate?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        delegate = ViewModelDelegate(delegate: self)
        
        uiController = getUiControllerFactory().createContactUiController(delegate)
        
        self.tabBarController?.tabBar.translucent = false
        self.tabBarController?.navigationController?.navigationBar.translucent = false
        
        if multiSelection {
            selectDoneBarItem = UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.Done, target: self, action: "selectDone:")
        }
        
        tableView.allowsMultipleSelection = multiSelection
        
    }
    
    func selectDone(sender: AnyObject) {
        
        if ((self.selectionDelegate ) != nil) {
            
            var contacts: [CoreRContact] = [];
            
            for indexPath in tableView.indexPathsForSelectedRows! {
                
                let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
                contacts.append(model!)
                
            }
            
            selectionDelegate?.onContactSelected(contacts)
        }
        
        self.navigationController?.popViewControllerAnimated(true)
        
    }
    
    func updateSelectDoneButton () {
        self.navigationItem.rightBarButtonItem = self.tableView.indexPathsForSelectedRows!.count > 0 ? self.selectDoneBarItem : nil;
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        setNavigationBar()
    }
    
    func setNavigationBar() {
        tabBarController?.navigationItem.titleView = customizedTitleView("Contact")
        tabBarController?.navigationItem.rightBarButtonItem = nil;
    }
    
    @objc func onDataChanged() {
        tableView.reloadData()
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (Int)((uiController?.getViewModel()?.getDataSource()?.numberOfRowsInSection((Int32)(section)))!)
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCellWithIdentifier("ContactTableViewCell", forIndexPath: indexPath) as! ContactTableViewCell
        
        let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
        
        cell.name.text = model?.displayName
        
        var url: NSURL? = nil;
        if model?.avatarUrl != nil {
            url = NSURL(string: (model?.avatarUrl!)!)
        }
        
        
        if url != nil {
            cell.avatar.kf_setImageWithURL(url!, placeholderImage: UIImage(named: "contact"))
        }
        else {
            cell.avatar.image = UIImage(named: "contact")
        }
        
        return cell
    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        if multiSelection {
            updateSelectDoneButton()
        }
        else {
            let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
            tabBarController?.navigationController?.pushViewController(ViewUtils.createP2P(model!), animated: true)
        }

    }
}
