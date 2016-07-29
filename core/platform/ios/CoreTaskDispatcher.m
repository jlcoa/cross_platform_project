//
//  CoreTaskDispatcher.m
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import "CoreTaskDispatcher.h"
#import "CoreITask.h"

@implementation CoreTaskDispatcher {
    dispatch_queue_t _coreQueue;
    dispatch_queue_t _bgQueue;
    dispatch_queue_t _dbQueue;
}

- (instancetype) init {
    self = [super init];
    if (self) {
        _coreQueue = dispatch_queue_create("core", DISPATCH_QUEUE_SERIAL);
        _dbQueue = dispatch_queue_create("db", DISPATCH_QUEUE_SERIAL);
        _bgQueue = dispatch_queue_create("bg", DISPATCH_QUEUE_CONCURRENT);
    }
    return self;
}

- (void)dispatchToUI:(nullable CoreITask *)task {
    dispatch_async(dispatch_get_main_queue(), ^{
        [task execute];
    });
}

- (void)dispatchToCore:(nullable CoreITask *)task {
    dispatch_async(_coreQueue, ^{
        [task execute];
    });
}

- (void)dispatchToDB:(nullable CoreITask *)task {
    dispatch_async(_dbQueue, ^{
        [task execute];
    });
}

- (void)dispatchToBG:(nullable CoreITask *)task {
    dispatch_async(_bgQueue, ^{
        [task execute];
    });
}

@end
