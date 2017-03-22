/***********************************************
* ZQUtf8.h
*
* @author: zyq
* @date: 17/3/20
* @Description:
*
***********************************************/

#pragma once

#include <string>
namespace zq
{
    class utf8
    {
    public:
        static std::size_t count(const std::string &text);
        
        static std::string substr(const std::string &text, std::size_t start, std::size_t count);
        
        static bool bom(const std::string &text);
    };
}
