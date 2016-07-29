//
//  SignUpViewController.swift
//  NextUC
//
//  Created by Steve Chen on 3/7/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import UIKit

class SignUpViewController: UIViewController, CoreIViewModelDelegate, CoreIActionCallback {

    @IBOutlet weak var email: UITextField!
    
    @IBOutlet weak var password: UITextField!
    
    @IBOutlet weak var confirmPassword: UITextField!
    
    @IBOutlet weak var firstName: UITextField!
    
    @IBOutlet weak var lastName: UITextField!
    
    @IBAction func signUpTapped(sender: AnyObject) {
        
        showLoading()
        
        uiController?.signup(email.text!, password: password.text!, firstName: firstName.text!, lastName: lastName.text!, callback: self)
        
    }
    
    @objc func onDataChanged() {
        
    }
    
    @objc func onResponse(result: CoreRActionResult) {
        
        hideLoading()
        
        if result.result == CoreECallbackResult.Success {
            self.navigationController?.popViewControllerAnimated(true)
        }
        
    }
    
    var delegate: CoreIViewModelDelegate?
    
    var uiController: CoreISignupUiController?
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        delegate = ViewModelDelegate(delegate: self)
        uiController = getUiControllerFactory().createSignUpUiController(delegate)
        
    }

//    override func didReceiveMemoryWarning() {
//        super.didReceiveMemoryWarning()
//        // Dispose of any resources that can be recreated.
//    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
