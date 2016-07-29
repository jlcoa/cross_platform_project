//
//  CoreNetworkProvider.m
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import "CoreNetworkProvider.h"
#import "CoreRNetworkResponse.h"
#import "CoreINetworkCallback.h"

@implementation CoreNetworkProvider

- (void)request:(nonnull CoreRNetworkRequest *)request
       callback:(nullable CoreINetworkCallback *)callback
{
    NSString *url = [NSString stringWithFormat:@"%@%@", request.host, request.path];
    NSMutableURLRequest *urlRequest = [[NSMutableURLRequest alloc] initWithURL: [NSURL URLWithString:url]];
    
    [urlRequest setAllHTTPHeaderFields: request.header];
    
    [urlRequest setTimeoutInterval: 30];
    [urlRequest setCachePolicy: NSURLRequestReloadIgnoringCacheData];
    [urlRequest setHTTPShouldHandleCookies: NO];
    
    
    if (request.requestMethod == CoreENetworkMethodPost) {
        [urlRequest setHTTPMethod: @"POST"];
    } else if (request.requestMethod == CoreENetworkMethodPut) {
        [urlRequest setHTTPMethod: @"PUT"];
    }
    else if(request.requestMethod == CoreENetworkMethodGet) {
        [urlRequest setHTTPMethod: @"GET"];
    }
    else
    {
        [urlRequest setHTTPMethod: @"DELETE"];
    }

    void (^completionHandler)(NSData * __nullable data, NSURLResponse * __nullable response, NSError * __nullable error)  = ^(NSData * __nullable data, NSURLResponse * __nullable response, NSError * __nullable error) {
        
        if (error != nil) {
            NSLog(@"doRequest failed: %@", error);
            CoreRNetworkResponse *coreResponse = [CoreRNetworkResponse rNetworkResponseWithCode:-1 header:@{} status:CoreERequestResultUnknowError data:[@"" dataUsingEncoding:NSUTF8StringEncoding] contentType:@""];
            
            [callback onFailure:request.requestID response:coreResponse];
        }
        else {
            
            NSString *responseStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSLog(@"%@", responseStr);
            
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse*) response;
            NSMutableDictionary *header=[[NSMutableDictionary alloc] init];
            for (id key in httpResponse.allHeaderFields) {
                id value = [httpResponse.allHeaderFields objectForKey:key];
                if ([value isKindOfClass: [NSString class] ]) {
                    NSArray *valueArray = @[value];
                    [header setObject: valueArray forKey:key];
                }else if([value isKindOfClass:[NSArray class]]) {
                    [header setObject:value forKey:key];
                }
            }
            
            
            NSString *contentType = [httpResponse.allHeaderFields objectForKey:@"Content-Type"];
            if (contentType == nil) {
                contentType = @"";
            }
            
            CoreRNetworkResponse *coreResponse = [CoreRNetworkResponse rNetworkResponseWithCode:httpResponse.statusCode header:header status:CoreERequestResultSuccess data:data contentType:contentType];
            
            [callback onSuccess:request.requestID response:coreResponse];
            
            
        }
        
    };
    
    NSURLSession *urlSession = [NSURLSession sharedSession];
    
    if (request.requestMethod == CoreENetworkMethodGet) {
        [[urlSession dataTaskWithRequest:urlRequest completionHandler:completionHandler] resume];
    }
    else {
        NSData *requestData = [request.data dataUsingEncoding: NSUTF8StringEncoding];
        
        [[urlSession uploadTaskWithRequest:urlRequest
                                  fromData:requestData
                         completionHandler:completionHandler] resume];
        
        
    }
    
}

@end
