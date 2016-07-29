#pragma once
#include "gen/CoreEventLoop.h"

@interface CoreEventLoopObjc : NSObject <CoreEventLoop>

- (void)post:(CoreAsyncTask *)task;

@end
