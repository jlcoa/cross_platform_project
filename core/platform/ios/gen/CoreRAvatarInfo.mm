// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import "CoreRAvatarInfo.h"


@implementation CoreRAvatarInfo

- (nonnull instancetype)initWithUserId:(nullable NSString *)userId
                             avatarUrl:(nullable NSString *)avatarUrl
                     avatarUploadToken:(nullable NSString *)avatarUploadToken
{
    if (self = [super init]) {
        _userId = [userId copy];
        _avatarUrl = [avatarUrl copy];
        _avatarUploadToken = [avatarUploadToken copy];
    }
    return self;
}

+ (nonnull instancetype)rAvatarInfoWithUserId:(nullable NSString *)userId
                                    avatarUrl:(nullable NSString *)avatarUrl
                            avatarUploadToken:(nullable NSString *)avatarUploadToken
{
    return [[self alloc] initWithUserId:userId
                              avatarUrl:avatarUrl
                      avatarUploadToken:avatarUploadToken];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p userId:%@ avatarUrl:%@ avatarUploadToken:%@>", self.class, self, self.userId, self.avatarUrl, self.avatarUploadToken];
}

@end