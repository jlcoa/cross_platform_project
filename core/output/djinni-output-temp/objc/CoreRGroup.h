// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#import <Foundation/Foundation.h>

/** group */
@interface CoreRGroup : NSObject
- (nonnull instancetype)initWithId:(nullable NSString *)id
                         groupName:(nullable NSString *)groupName
                         groupType:(nullable NSString *)groupType
                           userIds:(nullable NSArray<NSString *> *)userIds
                             owner:(nullable NSArray<NSString *> *)owner
                             admin:(nullable NSArray<NSString *> *)admin;
+ (nonnull instancetype)rGroupWithId:(nullable NSString *)id
                           groupName:(nullable NSString *)groupName
                           groupType:(nullable NSString *)groupType
                             userIds:(nullable NSArray<NSString *> *)userIds
                               owner:(nullable NSArray<NSString *> *)owner
                               admin:(nullable NSArray<NSString *> *)admin;

@property (nonatomic, readonly, nullable) NSString * id;

@property (nonatomic, readonly, nullable) NSString * groupName;

@property (nonatomic, readonly, nullable) NSString * groupType;

/**	membersCount: optional<i64>; */
@property (nonatomic, readonly, nullable) NSArray<NSString *> * userIds;

@property (nonatomic, readonly, nullable) NSArray<NSString *> * owner;

@property (nonatomic, readonly, nullable) NSArray<NSString *> * admin;

@end

extern NSString * __nonnull const CoreRGroupTYPEGROUP;
