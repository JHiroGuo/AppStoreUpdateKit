//
//  AppDelegate.m
//  AppStoreUpdateKitDemo
//
//  Created by GJH on 2/19/19.
//  Copyright © 2019 GJHi. All rights reserved.
//

#import "AppDelegate.h"
#import <AppStoreUpdateKit/AppStoreUpdateKit.h>

@interface AppDelegate ()
/** 获取APP名称 */
#define APP_NAME ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"])

/** 程序版本号 */
#define APP_VERSION [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

/** 获取APP build版本 */
#define APP_BUILD ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    AppStoreUpdateAppObject *appObj = [[AppStoreUpdateAppObject alloc]
                                       initWithAppName:@"UP Studio"
                                       withAppIcon:[NSImage imageNamed:@"up"]
                                       withCurrentVersion:@"1.0.11"
                                       withProductID:@"1119477741"];
    
    AppStoreUpdateUIConfigure *UIConfigure = [[AppStoreUpdateUIConfigure alloc] init];
    [UIConfigure setSkipButtonTitle:@"Skip this version"];
    [UIConfigure setUpdateButtonTitle:@"Update"];
    [UIConfigure setLaterButtonTitle:@"Later"];
    [UIConfigure setVersionText:@"Version %@"];
    [UIConfigure setReleaseNotesText:@"Release Notes:\n\n"];
    [UIConfigure setReleaseNotesNoneText:@"Release Notes:\n\n None."];
    [[AppStoreUpdateManager sharedManager] customize:UIConfigure];
    
    [[AppStoreUpdateManager sharedManager] isInternationalAddress:YES];
    
    BOOL bRslt = [[AppStoreUpdateManager sharedManager] checkAppUpdate:appObj];
    bRslt = [appObj isNewVersionAvailable];
    
    [[AppStoreUpdateManager sharedManager] checkAppUpdateAsync:appObj withCompletionBlock:^(BOOL rslt, AppStoreUpdateAppObject * _Nonnull AppObj) {
        if (rslt && [appObj isNewVersionAvailable] && ![[AppStoreUpdateManager sharedManager] isCurrentNewVersionSkipped:appObj]) {
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                BOOL extractedExpr = [[AppStoreUpdateManager sharedManager] requestAppUpdateWindow:appObj withCompletionCallback:^(AppUpdateWindowResult rslt, AppStoreUpdateAppObject * _Nonnull AppObj) {
                    switch (rslt) {
                        case AppUpdateWindowResultUpdate:
                            [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"macappstore://itunes.apple.com/app/id%@",[AppObj productID]]]];
                            break;
                            
                        case AppUpdateWindowResultSkip:
                            [[AppStoreUpdateManager sharedManager] skipCurrentNewVersion:AppObj];
                            break;
                            
                        case AppUpdateWindowResultLater:
                            break;
                            
                        default:
                            break;
                    }
                }];
                NSLog(@"extractedExpr : %d",extractedExpr);
            });
        }
    }];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
