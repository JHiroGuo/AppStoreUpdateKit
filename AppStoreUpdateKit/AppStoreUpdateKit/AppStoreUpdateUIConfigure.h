//
//  AppStoreUpdateUIConfigure.h
//  AppStoreUpdateKit
//
//  Created by GJH on 2/19/19.
//  Copyright © 2019 GJHi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppStoreUpdateUIConfigure : NSObject

@property (nonatomic, strong, readwrite)        NSString        *skipButtonTitle;
@property (nonatomic, strong, readwrite)        NSString        *laterButtonTitle;
@property (nonatomic, strong, readwrite)        NSString        *updateButtonTitle;

// Default: @"Release Notes:\n\n"
@property (nonatomic, strong, readwrite)        NSString        *releaseNotesText;
// Default: @"Release Notes:\n\n None."
@property (nonatomic, strong, readwrite)        NSString        *releaseNotesNoneText;
// Must format like: Version %@
@property (nonatomic, strong, readwrite)        NSString        *versionText;

@end

NS_ASSUME_NONNULL_END
