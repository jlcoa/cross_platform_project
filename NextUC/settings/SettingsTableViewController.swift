//
//  SettingsTableViewController.swift
//  NextUC
//
//  Created by Bruce (Pengcheng) Cai on 2/28/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit
import Photos
import Qiniu
import Kingfisher

class SettingsTableViewController: UITableViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate, CoreIViewModelDelegate, CoreIRequestUploadTokenCallback, CoreIActionCallback {
    
    @IBOutlet weak var myPhotoImageView: UIImageView!
    
    @IBOutlet weak var nameLabel: UILabel!
    
    var uiController: CoreIProfileUiController?
    
    var delegate: ViewModelDelegate?
    
    var imageUrl: NSURL?
    
    @objc func onDataChanged() {
        
    }
    
    @objc func onResponse(result: CoreRActionResult) {
        self.hideLoading()
    }
    
    @objc func onTokenGet(token: CoreRUploadToken?, result: CoreRActionResult) {
        if result.result == CoreECallbackResult.Success {
//            uiController?.updateAvatar(<#T##avatarInfo: CoreRAvatarInfo##CoreRAvatarInfo#>, callback: <#T##CoreIActionCallback?#>)
//            self.hideLoading()
            self.upload27niu(token!)
        }
        else {
            self.hideLoading()
        }
    }
    
    func upload27niu(token: CoreRUploadToken) {
//        let url = info[UIImagePickerControllerReferenceURL] as! NSURL
        
        let fetchResult = PHAsset.fetchAssetsWithALAssetURLs([self.imageUrl!], options:nil)
        let asset = fetchResult.firstObject as! PHAsset;
        
//        // TODO: Replace the token and userId with data from server
//        let qiniuUtils = QiniuUtils(token: token.avatarUploadToken!, userId: token.userId!)
//        
//        qiniuUtils.uploadImage(asset as! PHAsset)
        
        let upManager = QNUploadManager()
        print("Start to upload image to Qiniu server...")
        
        upManager.putPHAsset(asset, key: token.userId! , token: token.avatarUploadToken! , complete: { (info, key, resp) -> Void in
            
            if (info.statusCode == 200 && resp != nil) {

                print("Image upload succeed")
                
                let avatarInfo = CoreRAvatarInfo(userId: token.userId, avatarUrl: nil, avatarUploadToken: nil)
          
                self.uiController?.updateAvatar(avatarInfo, callback: self)
                
            }else{
                //失败
                print("Image upload failed")
                print(info)
                
                self.hideLoading()
            }
            
            }, option: nil)
        
        
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        self.tabBarController?.tabBar.translucent = false
        self.tabBarController?.navigationController?.navigationBar.translucent = false
        
        self.tableView.tableFooterView = UIView(frame:CGRectZero)
        
        self.delegate = ViewModelDelegate(delegate: self)
        uiController = getUiControllerFactory().createProfileUiController(self.delegate)
        
        let account = uiController?.getViewModel()?.getAccount()
        var url: NSURL? = nil;
        if account?.avatarUrl != nil {
            url = NSURL(string: (account?.avatarUrl!)!)
            myPhotoImageView.kf_setImageWithURL(url!, placeholderImage: UIImage(named: "contact"))
        }
        
        nameLabel.text = account?.displayName
        
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        setNavigationBar()
    }
    
    func setNavigationBar() {
        tabBarController?.navigationItem.titleView = customizedTitleView("Settings")
        tabBarController?.navigationItem.rightBarButtonItem = nil;
    }
    
    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 2
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if (section == 0) {
            return 1
        } else {
            return 2
        }
    }
    
    //    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
    //
    ////        let cell = tableView.dequeueReusableCellWithIdentifier("SettingsTableViewCell", forIndexPath: indexPath) as! GroupTableViewCell
    //
    ////        let model = uiController?.getViewModel()?.getDataSource()?.objectAt((Int32)(indexPath.section), row: (Int32)(indexPath.row))
    //
    ////        cell.name.text = model?.groupName
    //
    ////        return cell
    //    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        let section = indexPath.section
        let row = indexPath.row
        
        
        // If tap to change photo
        if (section == 0 && row == 0) {
            print("Tap the cell to change photo")
            showSetPhotoActionSheet(self)
        }
        else if(section == 1 && row == 1) {
            let alert = UIAlertController(title: nil, message: "Are you sure to sign out?", preferredStyle: UIAlertControllerStyle.Alert)
            
            alert.addAction(UIAlertAction(title: "Cancel", style: .Cancel, handler: { (action: UIAlertAction) in
                
            }))
            
            alert.addAction(UIAlertAction(title: "Ok", style: .Default, handler: { (action: UIAlertAction) in
                
                self.uiController?.signout(self)
                
            }))
            
            self.presentViewController(alert, animated: true, completion: nil)
    
        }
    }
    
    @IBAction func showSetPhotoActionSheet(sender: AnyObject) {
        let optionMenu = UIAlertController(title: nil, message: "Set Photo", preferredStyle: .ActionSheet)
        
        let takePhotoAction = UIAlertAction(title: "Take Photo", style: .Default, handler: {
            (alert: UIAlertAction!) -> Void in
            print("Take photo action is tapped")
        })
        
        let choosePhotoAction = UIAlertAction(title: "Photo Library", style: .Default, handler: {
            (alert: UIAlertAction!) -> Void in
            print("Photo library action is tapped")
            
            let myPickerController = UIImagePickerController()
            myPickerController.delegate = self;
            myPickerController.sourceType = UIImagePickerControllerSourceType.PhotoLibrary
            
            self.presentViewController(myPickerController, animated: true, completion: nil)
        })
        
        let cancelAction = UIAlertAction(title: "Cancel", style: .Cancel, handler: {
            (alert: UIAlertAction!) -> Void in
            print("Cancelled")
        })
        
        
        optionMenu.addAction(takePhotoAction)
        optionMenu.addAction(choosePhotoAction)
        optionMenu.addAction(cancelAction)
        
        
        self.presentViewController(optionMenu, animated: true, completion: nil)
        self.tableView.deselectRowAtIndexPath(self.tableView.indexPathForSelectedRow!, animated: false)
        
    }
    
    func imagePickerController(picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : AnyObject]) {
        myPhotoImageView.image = info[UIImagePickerControllerOriginalImage] as? UIImage
        let url = info[UIImagePickerControllerReferenceURL] as! NSURL
        
        imageUrl = url;
        performUpdateAvatar()
        
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    
    func performUpdateAvatar() {
        
        self.showLoading()
        
        uiController?.requestUploadToken(self)
        
    }
}
