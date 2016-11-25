//
//  ZQLoggerIos.hpp
//  libzq
//
//  Created by staff on 16/11/22.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQLOGGERIOS_HPP_
#define _ZQLOGGERIOS_HPP_

#include "log/ZQLogger.h"

namespace zq {
    
class ZQLoggerIOS : public ZQLogger
{
public:
    static ZQLoggerIOS* getInstance();
    
protected:
    ZQLoggerIOS() = default;
    virtual ~ZQLoggerIOS() = default;
    
public:
    virtual void error(const std::string &message);
    virtual void debug(const std::string &message);
    
};

}

#endif /* _ZQLOGGERIOS_HPP_ */
