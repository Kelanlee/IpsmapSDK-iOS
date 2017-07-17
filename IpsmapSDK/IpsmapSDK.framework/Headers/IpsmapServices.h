//
//  IpsmapServices.h
//  IpsmapSDK
//
//  Created by zhangty on 17/4/6.
//  Copyright © 2017年 Ipsmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//剪贴板内有位置共享口令
#define IpsReceiveShareInfoNotification     @"IpsNotificationReceiveShareInfo"

@protocol IpsmapServicesDelegate <NSObject>

//监听partner下的医院列表请求返回（一般有两次，缓存、网络）
- (void)responseHospitalList:(NSArray *_Nullable)array error:(NSError *_Nullable)error;

@end

@class IpsPartner;
@interface IpsmapServices : NSObject {
    @private
    IpsPartner  *partner;
    
}
@property (nonatomic, weak)id<IpsmapServicesDelegate> _Nullable delegate;
//医院列表
@property (nonatomic, readonly)NSArray * _Nullable hospitalAry;
//是否在请求中
@property (nonatomic, assign)BOOL   isInLoading;

+ (nonnull instancetype)sharedInstance;

+ (void)setAppKey:(nonnull NSString *)appKey;

- (void)application:(UIApplication *_Nonnull)application didFinishLaunchingWithOptions:(NSDictionary *_Nullable)launchOptions;

- (void)applicationWillEnterForeground:(UIApplication *_Nonnull)application;

//请求对应的医院列表
- (void)requestPartnerHospitalList;

- (NSInteger)hasPermissionWith:(nonnull NSString *)mapId;

+ (NSString *_Nullable)SDKVersion;

@end
