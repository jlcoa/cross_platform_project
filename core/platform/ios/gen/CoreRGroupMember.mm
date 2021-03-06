// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import "CoreRGroupMember.h"


@implementation CoreRGroupMember

- (nonnull instancetype)initWithId:(nullable NSString *)id
                           groupId:(nullable NSString *)groupId
                            userId:(nullable NSString *)userId
                              type:(nullable NSNumber *)type
{
    if (self = [super init]) {
        _id = [id copy];
        _groupId = [groupId copy];
        _userId = [userId copy];
        _type = type;
    }
    return self;
}

+ (nonnull instancetype)rGroupMemberWithId:(nullable NSString *)id
                                   groupId:(nullable NSString *)groupId
                                    userId:(nullable NSString *)userId
                                      type:(nullable NSNumber *)type
{
    return [[self alloc] initWithId:id
                            groupId:groupId
                             userId:userId
                               type:type];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ groupId:%@ userId:%@ type:%@>", self.class, self, self.id, self.groupId, self.userId, self.type];
}

@end
