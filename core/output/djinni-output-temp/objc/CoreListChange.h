// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import <Foundation/Foundation.h>

@interface CoreListChange : NSObject
- (nonnull instancetype)initWithFromIndex:(int32_t)fromIndex
                                  toIndex:(int32_t)toIndex;
+ (nonnull instancetype)listChangeWithFromIndex:(int32_t)fromIndex
                                        toIndex:(int32_t)toIndex;

@property (nonatomic, readonly) int32_t fromIndex;

@property (nonatomic, readonly) int32_t toIndex;

@end
