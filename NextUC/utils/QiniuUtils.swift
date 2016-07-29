//
//  QiniuUtils.swift
//  NextUC
//
//  Created by Bruce (Pengcheng) Cai on 2/28/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import Foundation
import Photos
import Qiniu

class QiniuUtils {
    
    let token: String
    let userId: String
    
    init(token: String, userId: String) {
        self.token = token
        self.userId = userId
    }
    
    
    func uploadImage(asset: PHAsset) {
        let upManager = QNUploadManager()
        print("Start to upload image to Qiniu server...")
        
        upManager.putPHAsset(asset, key: self.userId , token: self.token , complete: { (info, key, resp) -> Void in
            
            if (info.statusCode == 200 && resp != nil){
                //上传完毕
                //                if i == sum{
                //刷新数据
                print("Image upload succeed")
                //                }
                
            }else{
                //失败
                print("Image upload failed")
                print(info)
            }
            
            }, option: nil)
    }
    
}