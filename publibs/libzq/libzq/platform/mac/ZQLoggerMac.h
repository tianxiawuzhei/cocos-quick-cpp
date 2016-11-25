//
//  ZQLoggerIos.hpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQLOGGERMAC_HPP_
#define _ZQLOGGERMAC_HPP_

#include "log/ZQLogger.h"

namespace zq {
    
class ZQLoggerMac : public ZQLogger
{
public:
    static ZQLoggerMac* getInstance();
    
protected:
    ZQLoggerMac() = default;
    virtual ~ZQLoggerMac() = default;
    
public:
    virtual void error(const std::string &message);
    virtual void debug(const std::string &message);
    
};

}

#endif /* _ZQLOGGERMAC_HPP_ */
