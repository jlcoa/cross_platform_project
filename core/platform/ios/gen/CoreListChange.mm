// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreListChange.h"


@implementation CoreListChange

- (nonnull instancetype)initWithFromIndex:(int32_t)fromIndex
                                  toIndex:(int32_t)toIndex
{
    if (self = [super init]) {
        _fromIndex = fromIndex;
        _toIndex = toIndex;
    }
    return self;
}

+ (nonnull instancetype)listChangeWithFromIndex:(int32_t)fromIndex
                                        toIndex:(int32_t)toIndex
{
    return [[self alloc] initWithFromIndex:fromIndex
                                   toIndex:toIndex];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p fromIndex:%@ toIndex:%@>", self.class, self, @(self.fromIndex), @(self.toIndex)];
}

@end
