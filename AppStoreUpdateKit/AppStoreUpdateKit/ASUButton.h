//
//  ASUButton.h
//  AppStoreUpdateKit
//
//  Created by GJH on 2/19/19.
//  Copyright © 2019 GJHi. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASUButton : NSButton

@property (nonatomic, strong, readwrite)        NSColor         *backgroundColor;
@property (nonatomic, strong, readwrite)        NSColor         *titleColor;

@end

NS_ASSUME_NONNULL_END
