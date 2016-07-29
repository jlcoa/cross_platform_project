// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import "CoreRContactResponse.h"


@implementation CoreRContactResponse

- (nonnull instancetype)initWithContacts:(nullable NSArray<CoreRContact *> *)contacts
{
    if (self = [super init]) {
        _contacts = [contacts copy];
    }
    return self;
}

+ (nonnull instancetype)rContactResponseWithContacts:(nullable NSArray<CoreRContact *> *)contacts
{
    return [[self alloc] initWithContacts:contacts];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p contacts:%@>", self.class, self, self.contacts];
}

@end