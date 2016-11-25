//
//  ZQDateUtils.hpp
//  libzq
//
//  Created by staff on 16/11/21.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQDATEUTILS_HPP_
#define _ZQDATEUTILS_HPP_

#include <string>
namespace zq {

class DateUtils
{
public:
    DateUtils() = delete;
    virtual ~DateUtils() = delete;
    
public:
    static std::string date(std::string separator = "-", bool utc = false);
    static std::string time(std::string separator = ":", bool utc = false, bool microsecond = false);
    
};
    
    
}


#endif /* _ZQDATEUTILS_HPP_ */
