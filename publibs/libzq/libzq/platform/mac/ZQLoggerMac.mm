//
//  ZQLoggerIos.cpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQLoggerMac.h"

using namespace zq;

ZQLoggerMac* ZQLoggerMac::getInstance()
{
    static ZQLoggerMac instance;
    return &instance;
}

void ZQLoggerMac::error(const std::string &message)
{
    std::string temp = "[ERROR] " + message + "\n";
    
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", temp.c_str());
    fflush(stdout);
    
    this->write(temp);
}

void ZQLoggerMac::debug(const std::string &message)
{
    if (!this->_debug)
        return;
    
    std::string temp = "[DEBUG] " + message + "\n";
    
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", temp.c_str());
    fflush(stdout);
    
    this->write(temp);
}
