//
//  ZQStringUtils.hpp
//  libzq
//
//  Created by staff on 16/11/18.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#ifndef _ZQSTRINGUTILS_HPP_
#define _ZQSTRINGUTILS_HPP_

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <functional>

namespace zq {
    
class StringUtils
{
    
protected:
    StringUtils() = default;
    ~StringUtils() = default;
    
public:
    
    static std::string format(const char *fmt)
    {
        // to improve performance, return fmt if no other params
        return fmt;
    }
    
    template <typename ...Args>
    static std::string format(const char *fmt, Args... args)
    {
        auto size = ::snprintf(nullptr, 0, fmt, args...);
        if (size <= 0)
            return "";
        
        std::string ret(++size, '\0');
        
        size = ::snprintf(&ret[0], static_cast<std::size_t>(size), fmt, args...);
        if (size <= 0)  // re-check
            return "";
        
        ret.resize(static_cast<std::size_t>(size));
        return ret;
    }

    static bool startsWith(const std::string &text, const std::string &start);
    static bool endsWith(const std::string &text, const std::string &end);
    
    static bool contains(const std::string &text, const std::string &str);
//    static std::size_t count(const std::string &text, const std::string &str);
    
    static std::size_t count(const std::string &text, const std::string str, std::size_t start = 0, std::size_t end = 0);
    

    static std::vector<std::string> split(std::string &text, std::string &separator);
    
    /**
     * Join a sequence of strings by some delimiter to create a new string
     * @section Example
     * @code
     * std::vector<std::ext_string> v;
     * v.push_back("This");
     * v.push_back("is");
     * v.push_back("a");
     * v.push_back("test.");
     * std::cout << std::ext_string::join(v, "|") << std::endl;
     *
     * This|is|a|test.
     * @endcode
     */
    static std::string join(std::vector<std::string> &vect, std::string &delimiter);
    
    
    static bool iequals(const std::string a, const std::string b, bool ignore_case = true);
    
    static std::string replace(std::string &text, std::string &from, std::string &to);
    static std::string replace_all(std::string &text, std::string &from, std::string &to);
    
    static std::string tolower(const std::string &text);
    static std::string toupper(const std::string &text);
    static std::string capitalize(const std::string &text);
    
    // http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring/217605#217605
    static std::string &ltrim(std::string &s);
    // trim from end
    static std::string &rtrim(std::string &s);
    // trim from both ends
    static std::string &trim(std::string &s);
    
    static std::string ltrim(const std::string &s);
    // trim from end
    static std::string rtrim(const std::string &s);
    // trim from both ends
    static std::string trim(const std::string &s);

    static inline bool islower(const std::string& s)
    {
        return std::all_of( std::begin(s), std::end(s),
                           [] (char c) { return std::islower(c); });
    }
    
    static inline bool isupper(const std::string& s)
    {
        return std::all_of( std::begin(s), std::end(s),
                           [] (char c) { return std::isupper(c); });
    }
    
    static inline bool isalpha(const std::string& s)
    {
        return std::all_of( std::begin(s), std::end(s),
                           [] (char c) { return std::isalpha(c); });
    }
    
    static inline bool isdigit(const std::string& s)
    {
        return std::all_of( std::begin(s), std::end(s),
                           [] (char c) { return ::isdigit(c); });
    }
    
    static inline bool isalnum (const std::string& s)
    {
        return std::all_of( std::begin(s), std::end(s),
                           [] (char c) { return std::isalnum(c); });
    }

};
    
}

#endif /* _ZQSTRINGUTILS_HPP_ */
