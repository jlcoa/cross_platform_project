#import <Foundation/Foundation.h>
#import "CoreHttpObjc.h"
#import "CoreThreadLauncherObjc.h"

#import "CoreEventLoopObjc.h"
#import "gen/CoreApi.h"


int main() {
    id <CoreHttp> httpImpl = [[CoreHttpObjc alloc] init];
    id <CoreEventLoop> uiThread= [[CoreEventLoopObjc alloc] init];
    id <CoreThreadLauncher> launcher = [[CoreThreadLauncherObjc alloc] init];
    NSString *filePath = @"../core";
    BOOL fileExists =[[NSFileManager defaultManager] fileExistsAtPath:filePath];
    if (fileExists) {
        CoreApi *api = [CoreApi createApi:filePath uiThread: uiThread httpImpl:httpImpl launcher:launcher];
        if (![api hasUser]) {
            [api setUsername: NSUserName()];
        }
        NSString * username = [api getUsername];
        NSLog(@"Hello, %@", username);
    } else {
        NSLog(@"Could not find path: `%@`", filePath);
    }
    return 0;
}
