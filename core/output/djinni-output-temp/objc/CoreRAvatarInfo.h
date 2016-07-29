// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import <Foundation/Foundation.h>

@interface CoreRAvatarInfo : NSObject
- (nonnull instancetype)initWithUserId:(nullable NSString *)userId
                             avatarUrl:(nullable NSString *)avatarUrl
                     avatarUploadToken:(nullable NSString *)avatarUploadToken;
+ (nonnull instancetype)rAvatarInfoWithUserId:(nullable NSString *)userId
                                    avatarUrl:(nullable NSString *)avatarUrl
                            avatarUploadToken:(nullable NSString *)avatarUploadToken;

@property (nonatomic, readonly, nullable) NSString * userId;

@property (nonatomic, readonly, nullable) NSString * avatarUrl;

@property (nonatomic, readonly, nullable) NSString * avatarUploadToken;

@end
