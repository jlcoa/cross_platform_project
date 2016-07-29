// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#import <Foundation/Foundation.h>
@class CoreIDataProvider;
@class CoreIUiControllerFactory;
@class CoreIXplatformApplication;
@protocol CoreIPalBundle;


@interface CoreIXplatformApplication : NSObject

- (void)initApp:(nullable id<CoreIPalBundle>)palBundle;

+ (nullable CoreIXplatformApplication *)sharedApplication;

- (nullable CoreIUiControllerFactory *)getUiControllerFactory;

- (nullable CoreIDataProvider *)getDataProvider;

@end