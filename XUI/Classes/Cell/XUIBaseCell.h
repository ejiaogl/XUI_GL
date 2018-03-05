//
// Created by Zheng on 28/07/2017.
// Copyright (c) 2017 Zheng. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "XUITheme.h"
#import "XUIAdapter.h"
#import "XUILogger.h"

@class XUICellFactory;

extern NSString * XUIBaseCellReuseIdentifier;

@interface XUIBaseCell : UITableViewCell

@property (nonatomic, strong) NSString *xui_cell;
@property (nonatomic, strong) NSString *xui_label;
@property (nonatomic, strong) NSString *xui_defaults;
@property (nonatomic, strong) NSString *xui_key;
@property (nonatomic, strong) id xui_default;
@property (nonatomic, strong) NSString *xui_icon;
@property (nonatomic, strong) NSString *xui_iconRenderingMode;
@property (nonatomic, strong) NSNumber *xui_readonly;
@property (nonatomic, strong) NSNumber *xui_height;
@property (nonatomic, strong) id xui_value;
@property (nonatomic, assign, readonly) BOOL canDelete;

@property (nonatomic, weak) XUICellFactory *factory;
@property (nonatomic, strong, readonly) XUITheme *theme; // shortcut for factory.theme
@property (nonatomic, strong, readonly) id <XUIAdapter> adapter; // shortcut for factory.adapter
@property (nonatomic, strong, readonly) XUILogger *logger; // shortcut for factory.logger

@property (nonatomic, strong, setter=setInternalTheme:) XUITheme *internalTheme;
- (void)setInternalTheme:(XUITheme *)theme NS_REQUIRES_SUPER;

@property (nonatomic, strong, setter=setInternalIconPath:) NSString *internalIconPath;
- (void)setInternalIconPath:(NSString *)internalIconPath NS_REQUIRES_SUPER;

+ (BOOL)xibBasedLayout;
+ (UINib *)cellNib;

+ (BOOL)layoutNeedsTextLabel;
+ (BOOL)layoutNeedsImageView;
+ (BOOL)layoutRequiresDynamicRowHeight;
+ (BOOL)layoutUsesAutoResizing;
+ (NSDictionary <NSString *, Class> *)entryValueTypes;
+ (BOOL)testEntry:(NSDictionary *)cellEntry withError:(NSError **)error NS_REQUIRES_SUPER;

- (void)setupCell NS_REQUIRES_SUPER;
- (void)configureCellWithEntry:(NSDictionary *)entry NS_REQUIRES_SUPER;

@end
