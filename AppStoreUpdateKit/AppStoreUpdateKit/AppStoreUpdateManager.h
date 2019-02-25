//
//  AppStoreUpdateManager.h
//  AppStoreUpdateKit
//
//  Created by GJH on 2/19/19.
//  Copyright © 2019 GJHi. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    AppUpdateWindowResultUpdate,
    AppUpdateWindowResultLater,
    AppUpdateWindowResultSkip
} AppUpdateWindowResult;

NS_ASSUME_NONNULL_BEGIN

@class AppStoreUpdateUIConfigure;
@class AppStoreUpdateAppObject;
@interface AppStoreUpdateManager : NSObject

+(instancetype)sharedManager;

-(void)customize:(AppStoreUpdateUIConfigure *)configure;
/*
 These functions will request app information from app store. Return value YES: New version is available.
 */
-(BOOL)checkAppUpdate:(AppStoreUpdateAppObject *)appObj;
-(void)checkAppUpdateAsync:(AppStoreUpdateAppObject *)appObj withCompletionBlock:(void (^)(BOOL rslt, AppStoreUpdateAppObject *AppObj))block;

/*
 If new version is available, this method will show the updateWindow and return YES, No new version will return NO.
 */
-(BOOL)requestAppUpdateWindow:(AppStoreUpdateAppObject *)appObj withCompletionCallback:(void (^)(AppUpdateWindowResult rslt, AppStoreUpdateAppObject *AppObj))block;

/*
 Record the skipped version.
 */
-(void)skipCurrentNewVersion:(AppStoreUpdateAppObject *)appObj;
-(BOOL)isCurrentNewVersionSkipped:(AppStoreUpdateAppObject *)appObj;

/*
 if the address is internation address.The request result is in English
 */
-(void)isInternationalAddress:(BOOL)bInter;

@end

NS_ASSUME_NONNULL_END
