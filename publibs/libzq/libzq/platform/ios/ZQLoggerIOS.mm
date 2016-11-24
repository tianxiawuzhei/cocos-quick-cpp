//
//  ZQLoggerIos.cpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQLoggerIOS.h"

using namespace zq;

ZQLoggerIOS* ZQLoggerIOS::getInstance()
{
    static ZQLoggerIOS instance;
    return &instance;
}

void ZQLoggerIOS::error(const std::string &message)
{
    
}

void ZQLoggerIOS::debug(const std::string &message)
{
    
}
