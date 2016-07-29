//
//  CoreFileStorageProvider.m
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import "CoreFileStorageProvider.h"

@implementation CoreFileStorageProvider

- (NSString *)getDocumentsPath:(NSString *)relativePath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString* path = ([paths count] > 0) ? [paths objectAtIndex:0] : @"";
    if(nil != relativePath)
        return [NSString stringWithFormat:@"%@/%@", path, relativePath];
    else
        return path;
}

- (void)createRelativeFolder:(NSString *)relativePath {
    NSString* path = [self getDocumentsPath:relativePath];
    if (![[NSFileManager defaultManager] fileExistsAtPath:path])
        [[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:NO attributes:nil error:nil];
}

- (void)remove:(NSString *)path {
    [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
}


@end
