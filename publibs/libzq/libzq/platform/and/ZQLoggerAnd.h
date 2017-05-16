//
//  ZQLoggerIos.hpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#pragma once

#ifdef ANDROID

#include "log/ZQLogger.h"

namespace zq
{
    class ZQLoggerAnd : public ZQLogger
    {
    public:
        static ZQLoggerAnd* getInstance();
        
    protected:
        ZQLoggerAnd() = default;
        virtual ~ZQLoggerAnd() = default;
        
    public:
        virtual void error(const std::string &message);
        virtual void debug(const std::string &message);
        
    };

}

#endif


