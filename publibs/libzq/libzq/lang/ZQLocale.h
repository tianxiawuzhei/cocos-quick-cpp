/***********************************************
* ZQLocale.h
*
* @author: zyq
* @date: 17/3/20
* @Description:
*
***********************************************/

#pragma once

#include <string>
#include <map>

namespace zq
{
    class Locale
    {
    public:
        static Locale* getInstance();
        
    protected:
        Locale() = default;
        
    public:
        std::string translate(const std::string &text);
        
    public:
        void setup(const std::string &filename, bool word = false);
        
    protected:
        std::string escape(std::string text);
        
    private:
        bool _word = false;
        std::map<std::string, std::map<std::string, std::string>> _data;
    };
}
