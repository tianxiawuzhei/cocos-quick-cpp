/***********************************************
* ZQLocale.cpp
*
* @author: zyq
* @date: 17/3/20
* @Description:
*
***********************************************/

#include "ZQLocale.h"
#include "data/ZQJsonManage.h"
#include "utils/ZQUtf8.h"
#include "log/ZQLogger.h"

using namespace zq;

Locale* Locale::getInstance()
{
    static Locale instance;
    return &instance;
}

std::string Locale::translate(const std::string &text)
{
    if (this->_data.empty())
        return text;
    
    if (!this->_word)
    {
        auto whole = this->_data.find(text);
        return (whole != this->_data.end()) ? this->_data[text]["0"] : text;
    }
    else
    {
        std::string result;
        for (std::size_t i = 0, len = utf8::count(text); i < len; )
        {
            auto key = utf8::substr(text, i, 1);
            auto val = key;
            auto find = this->_data.find(key);
            if (find != this->_data.end())
            {
                std::size_t last = 0;
                for (auto &single : find->second)
                {
                    auto length = utf8::count(single.first);
                    auto substr = utf8::substr(text, i, length);
                    if ((substr == single.first) && length >= last)
                    {
                        key = substr;
                        val = single.second;
                        last = length;
                    }
                }
            }
            
            i += utf8::count(key);
            result += val;
        }
        
        return result;
    }
}

void Locale::setup(const std::string &filename, bool traditional)
{
    this->_word = traditional;
    this->_data.clear();
    
    auto dict = ZQJsonManage::getInstance()->load_dict(filename);
    if (!dict.empty())
    {
        for (auto it : dict)
        {
            auto key = this->escape(it.first);
            auto val = this->escape(it.second.asString());
           
            std::string ch(utf8::substr(key, 0, 1));
            if (!traditional)
            {
                this->_data[key]["0"] = val;
            }
            else
            {
                auto &store = this->_data[ch];
                store[key] = val;
            }
            
        }
        
        ZQLogD("locale: loaded success: %s count: %d", filename.c_str(), this->_data.size());
    }
    else
    {
        ZQLogD("locale: loaded fail %s", filename.c_str());
    }
}

std::string Locale::escape(std::string text)
{
    auto block = [] (std::string &str, const std::string &from, const std::string &to) {
        std::string::size_type start = 0;
        
        while ((start = str.find(from, start)) != std::string::npos)
        {
            str.replace(start, from.length(), to);
            start += to.length();
        }
    };
    
    block(text, "\\n", "\n");
    block(text, "\\r", "\r");
    block(text, "\\\"", "\"");
    
    return text;
}
