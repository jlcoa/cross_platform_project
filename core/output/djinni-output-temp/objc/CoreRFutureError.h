// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#import "CoreEErrorType.h"
#import "CoreRNetworkError.h"
#import "CoreRParsingError.h"
#import "CoreRServerError.h"
#import <Foundation/Foundation.h>

@interface CoreRFutureError : NSObject
- (nonnull instancetype)initWithType:(CoreEErrorType)type
                         serverSrror:(nullable CoreRServerError *)serverSrror
                        parsingError:(nullable CoreRParsingError *)parsingError
                        networkError:(nullable CoreRNetworkError *)networkError
                      generalMessage:(nullable NSString *)generalMessage;
+ (nonnull instancetype)rFutureErrorWithType:(CoreEErrorType)type
                                 serverSrror:(nullable CoreRServerError *)serverSrror
                                parsingError:(nullable CoreRParsingError *)parsingError
                                networkError:(nullable CoreRNetworkError *)networkError
                              generalMessage:(nullable NSString *)generalMessage;

@property (nonatomic, readonly) CoreEErrorType type;

@property (nonatomic, readonly, nullable) CoreRServerError * serverSrror;

@property (nonatomic, readonly, nullable) CoreRParsingError * parsingError;

@property (nonatomic, readonly, nullable) CoreRNetworkError * networkError;

@property (nonatomic, readonly, nullable) NSString * generalMessage;

@end