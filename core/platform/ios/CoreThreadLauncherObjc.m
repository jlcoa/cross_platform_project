#include <Foundation/Foundation.h>
#include "CoreThreadLauncherObjc.h"
#include "gen/CoreAsyncTask.h"

@implementation CoreThreadLauncherObjc

- (void)startThread:(NSString *)name runFn:(CoreAsyncTask *)runFn {
    NSThread *thread = [[NSThread alloc] initWithTarget:runFn selector:@selector(execute) object:nil];
    if (name) {
        [thread setName:name];
    }
    [thread start];
}

@end
