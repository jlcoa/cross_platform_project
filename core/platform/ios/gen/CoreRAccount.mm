// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import "CoreRAccount.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"

NSString * __nonnull const CoreRAccountGRANDTYPEPASSWORD = @"password";

#pragma clang diagnostic pop

@implementation CoreRAccount

- (nonnull instancetype)initWithUsername:(nullable NSString *)username
                                password:(nullable NSString *)password
                               grantType:(nullable NSString *)grantType
                                      id:(nullable NSString *)id
                                   email:(nullable NSString *)email
                               firstName:(nullable NSString *)firstName
                                lastName:(nullable NSString *)lastName
                             displayName:(nullable NSString *)displayName
                               companyId:(nullable NSString *)companyId
                          rongCloudToken:(nullable NSString *)rongCloudToken
                               avatarUrl:(nullable NSString *)avatarUrl
{
    if (self = [super init]) {
        _username = [username copy];
        _password = [password copy];
        _grantType = [grantType copy];
        _id = [id copy];
        _email = [email copy];
        _firstName = [firstName copy];
        _lastName = [lastName copy];
        _displayName = [displayName copy];
        _companyId = [companyId copy];
        _rongCloudToken = [rongCloudToken copy];
        _avatarUrl = [avatarUrl copy];
    }
    return self;
}

+ (nonnull instancetype)rAccountWithUsername:(nullable NSString *)username
                                    password:(nullable NSString *)password
                                   grantType:(nullable NSString *)grantType
                                          id:(nullable NSString *)id
                                       email:(nullable NSString *)email
                                   firstName:(nullable NSString *)firstName
                                    lastName:(nullable NSString *)lastName
                                 displayName:(nullable NSString *)displayName
                                   companyId:(nullable NSString *)companyId
                              rongCloudToken:(nullable NSString *)rongCloudToken
                                   avatarUrl:(nullable NSString *)avatarUrl
{
    return [[self alloc] initWithUsername:username
                                 password:password
                                grantType:grantType
                                       id:id
                                    email:email
                                firstName:firstName
                                 lastName:lastName
                              displayName:displayName
                                companyId:companyId
                           rongCloudToken:rongCloudToken
                                avatarUrl:avatarUrl];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p username:%@ password:%@ grantType:%@ id:%@ email:%@ firstName:%@ lastName:%@ displayName:%@ companyId:%@ rongCloudToken:%@ avatarUrl:%@>", self.class, self, self.username, self.password, self.grantType, self.id, self.email, self.firstName, self.lastName, self.displayName, self.companyId, self.rongCloudToken, self.avatarUrl];
}

@end