//
//  ViewModelDelegate.swift
//  NextUC
//
//  Created by Steve Chen on 3/5/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import Foundation

class ViewModelDelegate: CoreIViewModelDelegate {
    
    weak var mDelegate: CoreIViewModelDelegate?
    
    init(delegate: CoreIViewModelDelegate) {
        mDelegate = delegate
    }
    
    @objc func onDataChanged() {
        mDelegate?.onDataChanged()
    }
    
}