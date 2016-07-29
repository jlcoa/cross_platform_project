// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#import "CoreRServerErrorDetail.h"
#import <Foundation/Foundation.h>

@interface CoreRServerError : NSObject
- (nonnull instancetype)initWithErrorCode:(nullable NSString *)errorCode
                                  message:(nullable NSString *)message
                            parameterName:(nullable NSString *)parameterName
                                parameter:(nullable NSString *)parameter
                                   errors:(nonnull NSArray<CoreRServerErrorDetail *> *)errors
                                    error:(nullable NSString *)error
                         errorDescription:(nullable NSString *)errorDescription;
+ (nonnull instancetype)rServerErrorWithErrorCode:(nullable NSString *)errorCode
                                          message:(nullable NSString *)message
                                    parameterName:(nullable NSString *)parameterName
                                        parameter:(nullable NSString *)parameter
                                           errors:(nonnull NSArray<CoreRServerErrorDetail *> *)errors
                                            error:(nullable NSString *)error
                                 errorDescription:(nullable NSString *)errorDescription;

@property (nonatomic, readonly, nullable) NSString * errorCode;

@property (nonatomic, readonly, nullable) NSString * message;

@property (nonatomic, readonly, nullable) NSString * parameterName;

@property (nonatomic, readonly, nullable) NSString * parameter;

@property (nonatomic, readonly, nonnull) NSArray<CoreRServerErrorDetail *> * errors;

@property (nonatomic, readonly, nullable) NSString * error;

@property (nonatomic, readonly, nullable) NSString * errorDescription;

@end