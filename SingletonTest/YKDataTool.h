//
//  YKDataTool.h
//  SingletonTest
//
//  Created by yankang on 2017/3/11.
//  Copyright © 2017年 yankang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Singleton.h"

@interface YKDataTool : NSObject<NSCopying>

SingletonH(DataTool)

@end
