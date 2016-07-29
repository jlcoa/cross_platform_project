//
//  CoreTaskDispatcher.h
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#import <Foundation/Foundation.h>

#import "CoreITaskDispatcher.h"

@interface CoreTaskDispatcher : NSObject <CoreITaskDispatcher>

- (instancetype) init;

@end
