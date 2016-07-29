//
//  CoreLogger.m
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import "CoreLogger.h"

@implementation CoreLogger {
    CoreLogLevel _currentLevel;
}
-(instancetype)init {
    _currentLevel = CoreLogLevelVerboss;
    return self;
}

- (void)error:(NSString *)tag message:(NSString *)message {
    NSLog(@"[%@] %@", tag, message);
}

- (void)warning:(NSString *)tag message:(NSString *)message {
    NSLog(@"[%@] %@", tag, message);
}

- (void)info:(NSString *)tag message:(NSString *)message {
    NSLog(@"[%@] %@", tag, message);
}

- (void)debug:(NSString *)tag message:(NSString *)message {
    NSLog(@"[%@] %@", tag, message);
}

- (void)verbose:(NSString *)tag message:(NSString *)message {
    NSLog(@"[%@] %@", tag, message);
}

- (void)setLogLevel:(CoreLogLevel)level {
    _currentLevel = level;
}

- (BOOL) visible:(CoreLogLevel)level {
    return _currentLevel <= level;
}

@end
