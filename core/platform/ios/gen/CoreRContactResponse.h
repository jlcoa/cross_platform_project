// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import "CoreRContact.h"
#import <Foundation/Foundation.h>

@interface CoreRContactResponse : NSObject
- (nonnull instancetype)initWithContacts:(nullable NSArray<CoreRContact *> *)contacts;
+ (nonnull instancetype)rContactResponseWithContacts:(nullable NSArray<CoreRContact *> *)contacts;

@property (nonatomic, readonly, nullable) NSArray<CoreRContact *> * contacts;

@end
