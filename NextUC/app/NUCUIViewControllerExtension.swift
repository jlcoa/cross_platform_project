//
//  NUCUIViewController.swift
//  NextUC
//
//  Created by Steve Chen on 2/20/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import Foundation
import UIKit
import PKHUD

public extension UIViewController
{
    public func getUiControllerFactory() -> CoreIUiControllerFactory!
    {
       return CoreApp.sharedApplication().getUiControllerFactory()!
    }
    
    public func showLoading()
    {
        PKHUD.sharedHUD.contentView = PKHUDProgressView()
        PKHUD.sharedHUD.show()
    }
    
    public func hideLoading()
    {
        PKHUD.sharedHUD.hide()
    }
    
    public func customizedTitleView(title: String!) -> UIView {
        
        let titleView = UILabel(frame: CGRectMake(0, 0, 200, 44))
        titleView.backgroundColor = UIColor.clearColor()
        titleView.font = UIFont.boldSystemFontOfSize(19)
        titleView.textColor = UIColor.blackColor()
        titleView.textAlignment = NSTextAlignment.Center
        titleView.text = title
        
        return titleView
    }
}




