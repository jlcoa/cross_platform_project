// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import <Foundation/Foundation.h>
@class CoreIGroupUpdateViewModel;
@protocol CoreIGroupCallback;


@interface CoreIGroupUpdateUiController : NSObject

- (void)updateGroupName:(nonnull NSString *)groupName
               callback:(nullable id<CoreIGroupCallback>)callback;

- (nullable CoreIGroupUpdateViewModel *)getViewModel;

@end
