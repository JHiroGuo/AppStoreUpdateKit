//
//  AppStoreUpdateWindowController.h
//  AppStoreUpdateKit
//
//  Created by GJH on 2/19/19.
//  Copyright © 2019 GJHi. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class AppStoreUpdateUIConfigure;
@class AppStoreUpdateAppObject;
@class AppStoreUpdateWindowController;

@protocol AppStoreUpdateWindowControllerDelegate <NSObject>

@optional
-(void)skipButtonClick:(AppStoreUpdateWindowController *)sender;
-(void)updateButtonClick:(AppStoreUpdateWindowController *)sender;
-(void)laterButtonClick:(AppStoreUpdateWindowController *)sender;

@end

@interface AppStoreUpdateWindowController : NSWindowController

@property(nonatomic, weak, readwrite)   id<AppStoreUpdateWindowControllerDelegate>      delegate;
@property(nonatomic, strong, readonly)  AppStoreUpdateAppObject                         *appObj;

-(instancetype)initWithAppObject:(AppStoreUpdateAppObject *)appObj withCustomizeConfigure:(AppStoreUpdateUIConfigure *)configure;

@end
