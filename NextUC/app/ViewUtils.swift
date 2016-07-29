//
//  ViewUtils.swift
//  NextUC
//
//  Created by Steve Chen on 2/21/16.
//  Copyright © 2016 Steve Chen. All rights reserved.
//

import Foundation

class ViewUtils {
    
    static func createP2P(contact: CoreRContact) -> UIViewController {

        let chatVc = RCConversationViewController()
        chatVc.targetId = contact.id
        chatVc.userName = contact.displayName
        chatVc.conversationType = RCConversationType.ConversationType_PRIVATE
        chatVc.title = contact.displayName
        
        return chatVc
    }
    
    static func createTeam(model: CoreRGroup) -> UIViewController {
        
        let chatVc = RCConversationViewController()
        chatVc.targetId = model.id
        chatVc.userName = model.groupName
        chatVc.conversationType = RCConversationType.ConversationType_GROUP
        chatVc.title = model.groupName
        
        return chatVc
    }
    
}