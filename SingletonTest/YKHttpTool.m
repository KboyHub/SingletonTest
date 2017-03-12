//
//  YKHttpTool.m
//  SingletonTest
//
//  Created by yankang on 2017/3/11.
//  Copyright © 2017年 yankang. All rights reserved.
//

#import "YKHttpTool.h"

@implementation YKHttpTool

static id _instance = nil;

//重写allocWithZone：
+ (id)allocWithZone:(struct _NSZone *)zone {
    if (_instance == nil) {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            _instance = [super allocWithZone:zone];
        });
    }
    return _instance;
    
}

//对外接口
+ (instancetype)shareHttpTool{
    return [[self alloc]init];
}
//重写init方法
- (instancetype)init {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            _instance = [super  init];
        });
    return _instance;
}

- (id)copyWithZone:(NSZone *)zone{
    return  _instance;
}
+ (instancetype)copyWithZone:(struct _NSZone *)zone{
    return  _instance;
}
+ (instancetype)mutableCopyWithZone:(struct _NSZone *)zone{
    return _instance;
}
- (id)mutableCopyWithZone:(NSZone *)zone{
    return _instance;
}


#if !__has_feature(objc_arc)
- (oneway void)release{
    
}
- (id)retain{
    return _instance;
}
- (NSUInteger)retainCount{
    return 1;
}
#endif


@end
