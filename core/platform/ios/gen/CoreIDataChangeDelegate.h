// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreRContact.h"
#import "CoreRGroup.h"
#import <Foundation/Foundation.h>


/**# data provider */
@protocol CoreIDataChangeDelegate

- (void)onContactChanged:(nonnull CoreRContact *)contact;

- (void)onGroupChanged:(nonnull CoreRGroup *)group;

@end