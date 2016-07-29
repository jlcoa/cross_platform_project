#pragma once
#include "gen/CoreHttp.h"

@interface CoreHttpObjc : NSObject <CoreHttp>

- (void)get:(NSString *)url callback:(CoreHttpCallback *)callback;

@end
