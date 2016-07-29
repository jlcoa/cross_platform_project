//
//  LoginViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/20/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit
import SnapKit

class LoginViewController: UIViewController, CoreIViewModelDelegate {

    @IBOutlet weak var email: UITextField!
    
    @IBOutlet weak var password: UITextField!
    
    var loginUiController: CoreILoginUiController?
    
    var delegate: ViewModelDelegate?
    
//    override func loadView() {
//        super.loadView()
//        
//        let view = UIView()
//        view.backgroundColor = UIColor.greenColor()
//        view.autoresizingMask = [.FlexibleHeight, .FlexibleWidth]
//        
////        view.addSubview(self.view)
//        
//        let contentView = self.view
//        contentView.backgroundColor = UIColor.purpleColor()
//        view.addSubview(contentView)
//        
//        let box = UIView()
//        box.backgroundColor = UIColor.redColor()
//        view.addSubview(box)
//        
//        box.snp_makeConstraints { (make) -> Void in
//            make.height.equalTo(250)
//            make.width.equalTo(view)
//            make.top.equalTo(view)
//        }
////
//        view.addSubview(contentView)
//        contentView.snp_makeConstraints { (make) -> Void in
//            make.left.equalTo(view)
//            make.width.equalTo(view)
//            make.top.equalTo(box.snp_bottom)
//            make.height.equalTo(view)
//        }
//        
//        self.view = view
//    }
    
//    override func viewWillLayoutSubviews()
//    {
//        super.viewWillLayoutSubviews()
//        view.subviews[0].frame = self.view.bounds
        
//        view.subviews[0].snp_updateConstraints { (make) -> Void in
//            make.left.equalTo(view)
//            make.width.equalTo(view)
//            make.top.equalTo(view)
//            make.height.equalTo(view)
//        }
//    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        delegate = ViewModelDelegate(delegate: self)
        loginUiController = getUiControllerFactory().createLoginUiController(delegate)
        
    }

    @objc func onDataChanged() {
        loginUiController?.getViewModel()?.getStatus()
        hideLoading()
    }
    
    @IBAction func tapLogin(sender: AnyObject) {
        
        showLoading()
        
        let viewModel = loginUiController?.getViewModel()
        viewModel?.setUserName(email.text!)
        viewModel?.setPassword(password.text!)
        
        loginUiController?.login()
    
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
