#include <Foundation/Foundation.h>
#include "CoreEventLoopObjc.h"
#include "gen/CoreAsyncTask.h"

@implementation CoreEventLoopObjc

- (void)post:(CoreAsyncTask *)task {
    dispatch_async(dispatch_get_main_queue(), ^{
        [task execute];
    });
}

@end
