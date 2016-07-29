//
//  CoreApp.m
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import "CoreApp.h"
#import "CorePALBundle.h"

@implementation CoreApp

+ (void) initCore {
    id<CoreIPalBundle> palBundle = [[CorePALBundle alloc] init];
    [[CoreIXplatformApplication sharedApplication] initApp:palBundle];
}

+ (CoreIXplatformApplication *) sharedApplication {
    return [CoreIXplatformApplication sharedApplication];
}

@end
