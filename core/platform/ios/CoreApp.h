//
//  CoreApp.h
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import <Foundation/Foundation.h>
#import "gen/CoreIXplatformApplication.h"

@interface CoreApp : NSObject

+ (void) initCore;

+ (CoreIXplatformApplication *) sharedApplication;

@end
