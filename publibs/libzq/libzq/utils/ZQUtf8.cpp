/***********************************************
* ZQUtf8.cpp
*
* @author: zyq
* @date: 17/3/20
* @Description:
*
***********************************************/

#include "ZQUtf8.h"

std::size_t zq::utf8::count(const std::string &text)
{
    auto ptr = text.data();
    auto len = text.size();
    
    std::size_t num  = 0;
    std::size_t pos  = utf8::bom(text) ? 3 : 0;
    std::size_t step = 0;
    
    while (pos < len)
    {
        if ((ptr[pos] & 0x80) == 0x00)       // 1Bytes
            step = 1;
        else if ((ptr[pos] & 0xE0) == 0xC0)  // 2Bytes
            step = 2;
        else if ((ptr[pos] & 0xF0) == 0xE0)  // 3Bytes
            step = 3;
        else if ((ptr[pos] & 0xF8) == 0xF0)  // 4Bytes
            step = 4;
        else if ((ptr[pos] & 0xFC) == 0xF8)  // 5Bytes
            step = 5;
        else if ((ptr[pos] & 0xFE) == 0xFC)  // 6Bytes
            step = 6;
        else
            break;
        
        ++num;
        pos += step;
    }
    
    return num;
}

std::string zq::utf8::substr(const std::string &text, std::size_t start, std::size_t count)
{
    if (!count)
        return "";
    
    auto ptr = text.data();
    auto len = text.size();
    
    std::string ret;
    
    std::size_t num  = 0;
    std::size_t pos  = utf8::bom(text) ? 3 : 0;
    std::size_t step = 0;
    
    while ((pos < len) && count)
    {
        if ((ptr[pos] & 0x80) == 0x00)       // 1Bytes
            step = 1;
        else if ((ptr[pos] & 0xE0) == 0xC0)  // 2Bytes
            step = 2;
        else if ((ptr[pos] & 0xF0) == 0xE0)  // 3Bytes
            step = 3;
        else if ((ptr[pos] & 0xF8) == 0xF0)  // 4Bytes
            step = 4;
        else if ((ptr[pos] & 0xFC) == 0xF8)  // 5Bytes
            step = 5;
        else if ((ptr[pos] & 0xFE) == 0xFC)  // 6Bytes
            step = 6;
        else
            return ret;
        
        if (num >= start)
        {
            ret.append(ptr + pos, step);
            count--;
        }
        
        ++num;
        pos += step;
    }
    
    return ret;

}

bool zq::utf8::bom(const std::string &text)
{
    return (text.size() >= 3) &&
    (static_cast<unsigned char>(text[0]) == 0xEF) &&
    (static_cast<unsigned char>(text[1]) == 0xBB) &&
    (static_cast<unsigned char>(text[2]) == 0xBF);
}
