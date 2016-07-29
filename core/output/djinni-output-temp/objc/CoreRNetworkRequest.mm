// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#import "CoreRNetworkRequest.h"


@implementation CoreRNetworkRequest

- (nonnull instancetype)initWithRequestID:(int64_t)requestID
                                     host:(nonnull NSString *)host
                                     path:(nonnull NSString *)path
                            requestMethod:(CoreENetworkMethod)requestMethod
                                   header:(nonnull NSDictionary<NSString *, NSString *> *)header
                                     data:(nonnull NSString *)data
{
    if (self = [super init]) {
        _requestID = requestID;
        _host = [host copy];
        _path = [path copy];
        _requestMethod = requestMethod;
        _header = [header copy];
        _data = [data copy];
    }
    return self;
}

+ (nonnull instancetype)rNetworkRequestWithRequestID:(int64_t)requestID
                                                host:(nonnull NSString *)host
                                                path:(nonnull NSString *)path
                                       requestMethod:(CoreENetworkMethod)requestMethod
                                              header:(nonnull NSDictionary<NSString *, NSString *> *)header
                                                data:(nonnull NSString *)data
{
    return [[self alloc] initWithRequestID:requestID
                                      host:host
                                      path:path
                             requestMethod:requestMethod
                                    header:header
                                      data:data];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p requestID:%@ host:%@ path:%@ requestMethod:%@ header:%@ data:%@>", self.class, self, @(self.requestID), self.host, self.path, @(self.requestMethod), self.header, self.data];
}

@end