// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#import <Foundation/Foundation.h>

@interface CoreRNetworkError : NSObject
- (nonnull instancetype)initWithErrorCode:(int32_t)errorCode;
+ (nonnull instancetype)rNetworkErrorWithErrorCode:(int32_t)errorCode;

@property (nonatomic, readonly) int32_t errorCode;

@end
