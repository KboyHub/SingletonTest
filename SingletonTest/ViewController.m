//
//  ViewController.m
//  SingletonTest
//
//  Created by yankang on 2017/3/11.
//  Copyright © 2017年 yankang. All rights reserved.
//

#import "ViewController.h"
#import "YKHttpTool.h"
#import "YKDataTool.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    YKDataTool *h1 = [YKDataTool shareDataTool];
    YKDataTool *h2 = [YKDataTool shareDataTool];
    YKDataTool *h3 = [h2 copy];
    YKDataTool *h4 = [h3 mutableCopy];

    NSLog(@"%p,%p,%p,%p",h1,h2,h3,h4);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
