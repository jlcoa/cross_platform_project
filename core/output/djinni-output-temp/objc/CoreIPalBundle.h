// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_bundle.djinni

#import <Foundation/Foundation.h>
@protocol CoreIFileStorageProvider;
@protocol CoreILog;
@protocol CoreINetworkProvider;
@protocol CoreINetworkStatusProvider;
@protocol CoreITaskDispatcher;


@protocol CoreIPalBundle

- (nullable id<CoreINetworkProvider>)getNetworkProvider;

- (nullable id<CoreILog>)getLog;

- (nullable id<CoreIFileStorageProvider>)getFileStorageProvider;

- (nullable id<CoreINetworkStatusProvider>)getNetworkStatusProvider;

- (nullable id<CoreITaskDispatcher>)getTaskDispatcher;

@end
