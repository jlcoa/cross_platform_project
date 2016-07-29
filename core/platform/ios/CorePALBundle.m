//
//  CorePALBundle.m
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import "CorePALBundle.h"

#import "CoreNetworkProvider.h"
#import "CoreLogger.h"
#import "CoreFileStorageProvider.h"
#import "CoreTaskDispatcher.h"

@implementation CorePALBundle {
    CoreLogger* _logger;
    CoreFileStorageProvider* _fileStorageProvider;
    CoreNetworkProvider* _networkProvider;
    CoreTaskDispatcher* _taskDispatcher;
}

- (instancetype) init {
    self = [super init];
    if (self) {
        _logger = [[CoreLogger alloc] init];
        _networkProvider = [[CoreNetworkProvider alloc] init];
        _fileStorageProvider = [[CoreFileStorageProvider alloc] init];
        _taskDispatcher = [[CoreTaskDispatcher alloc] init];
    }
    return self;
}

- (nullable id<CoreINetworkProvider>) getNetworkProvider {
    return _networkProvider;
}

- (nullable id<CoreILog>)getLog {
    return _logger;
}

- (nullable id<CoreIFileStorageProvider>) getFileStorageProvider {
    return _fileStorageProvider;
}

- (nullable id<CoreINetworkStatusProvider>) getNetworkStatusProvider {
    return nil;
}

- (nullable id<CoreITaskDispatcher>) getTaskDispatcher {
    return _taskDispatcher;
}

@end
