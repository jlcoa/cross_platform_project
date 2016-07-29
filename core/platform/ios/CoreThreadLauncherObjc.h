#pragma once
#include "gen/CoreThreadLauncher.h"

@interface CoreThreadLauncherObjc : NSObject <CoreThreadLauncher>

- (void)startThread:(NSString *)name runFn:(CoreAsyncTask *)runFn;

@end
