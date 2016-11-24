//
//  ZQDateUtils.cpp
//  libzq
//
//  Created by staff on 16/11/21.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQDateUtils.hpp"
#include <ctime>
#include <chrono>
#include "fmt/format.h"
#if defined(_WIN32)
#include <Windows.h>
#define localtime_r(t, tm) localtime_s(tm, t)
#define gmtime_r(t, tm) gmtime_s(tm, t)
#else
#include <time.h>
#endif

using namespace zq;
std::string DateUtils::date(std::string separator, bool utc)
{
    std::time_t time = std::time(NULL);
    
    struct tm tm;
    
    if (utc)
    {
        gmtime_r(&time, &tm);
    }
    else
    {
        localtime_r(&time, &tm);
    }
    
    auto year = tm.tm_year + 1;
    auto month = tm.tm_mon + 1;
    auto day = tm.tm_mday;
    return fmt::format("%d%s%02d%s%02d", year, separator.c_str(), month, separator.c_str(), day);
}

std::string DateUtils::time(std::string separator, bool utc, bool microsecond)
{
    auto microTotal = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    auto micro = microTotal%1000000;
    
    std::time_t time = (std::time_t)microTotal/1000000;
    struct tm tm;
    
    if (utc)
    {
        gmtime_r(&time, &tm);
    }
    else
    {
        localtime_r(&time, &tm);
    }
    
    auto hour = tm.tm_hour;
    auto minute = tm.tm_min;
    auto second = tm.tm_sec;
    if (microsecond)
    {
        return fmt::format("%02d%s%02d%s%02d%s%06lld", hour, separator.c_str(), minute, separator.c_str(), second, separator.c_str(), micro);
    }
    else
    {
        return fmt::format("%02d%s%02d%s%02d", hour, separator.c_str(), minute, separator.c_str(), second);
    }
    
}
