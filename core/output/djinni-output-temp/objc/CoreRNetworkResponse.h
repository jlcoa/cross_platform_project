// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#import "CoreERequestResult.h"
#import <Foundation/Foundation.h>

@interface CoreRNetworkResponse : NSObject
- (nonnull instancetype)initWithCode:(int64_t)code
                              header:(nonnull NSDictionary<NSString *, NSArray<NSString *> *> *)header
                              status:(CoreERequestResult)status
                                data:(nonnull NSData *)data
                         contentType:(nonnull NSString *)contentType;
+ (nonnull instancetype)rNetworkResponseWithCode:(int64_t)code
                                          header:(nonnull NSDictionary<NSString *, NSArray<NSString *> *> *)header
                                          status:(CoreERequestResult)status
                                            data:(nonnull NSData *)data
                                     contentType:(nonnull NSString *)contentType;

@property (nonatomic, readonly) int64_t code;

@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSArray<NSString *> *> * header;

@property (nonatomic, readonly) CoreERequestResult status;

@property (nonatomic, readonly, nonnull) NSData * data;

@property (nonatomic, readonly, nonnull) NSString * contentType;

@end
