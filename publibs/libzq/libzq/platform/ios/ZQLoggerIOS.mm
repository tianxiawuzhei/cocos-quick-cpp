//
//  ZQLoggerIos.cpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQLoggerIOS.h"
#import <UIKit/UIKit.h>

using namespace zq;

ZQLoggerIOS* ZQLoggerIOS::getInstance()
{
    static ZQLoggerIOS instance;
    return &instance;
}

void ZQLoggerIOS::error(const std::string &message)
{
    std::string temp = "[ERROR] " + message + "\n";
    
#if COCOS2D_DEBUG
    NSLog(@"❤️ %@", [NSString stringWithUTF8String:temp.c_str()]);
#else
    NSLog(@"%@", [NSString stringWithUTF8String:temp.c_str()]);
#endif
    
    this->write(temp);
}

void ZQLoggerIOS::debug(const std::string &message)
{
    if (!this->_debug)
        return;
    
    std::string temp = "[DEBUG] " + message + "\n";
    
#if COCOS2D_DEBUG
    NSLog(@"💚 %@", [NSString stringWithUTF8String:temp.c_str()]);
    //    NSLog(@"%s%@%s", XCODE_COLORS_ESCAPE "fg255,0,0;", [NSString stringWithUTF8String:temp.c_str()], XCODE_COLORS_RESET);
#else
    NSLog(@"%@", [NSString stringWithUTF8String:temp.c_str()]);
#endif
    
    this->write(temp);
}
