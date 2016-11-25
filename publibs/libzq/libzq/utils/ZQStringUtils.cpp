//
//  ZQStringUtils.cpp
//  libzq
//
//  Created by staff on 16/11/18.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQStringUtils.h"

#include <functional>

using namespace zq;

bool StringUtils::startsWith(const std::string &text, const std::string &start)
{
    //if start is bigger than the string than it fails
    if (start.length() > text.length()) {
        return false;
    }
    else if (start.length() == text.length()) {
        return start == text;
    }
    //loop through start and check if all char matches
    for (int i = 0; i< start.length(); i++) {
        if (start[i] != text[i]) {
            return false;
        }
    }
    return true;
}

bool StringUtils::endsWith(const std::string &text, const std::string &end)
{
    //if end is bigger than the string than it fails
    if (end.length() > text.length()) {
        return false;
    }
    else if (end.length() == text.length()) {
        return end == text;
    }
    
    std::size_t diff = text.length() - end.length();
    for (std::size_t  i = text.length()-1; i > diff-1; i--) {
        if (end[i-diff] != text[i]) {
            return false;
        }
    }
    return true;
}

bool StringUtils::contains(const std::string &text, const std::string &str)
{
    return text.find(str) != std::string::npos;
}

std::size_t StringUtils::count(const std::string &text, const std::string str, std::size_t start, std::size_t end)
{
    if (start == 0) {
        start = 0;
    }
    
    if (end == 0) {
        end = text.length()-1;
    }
    
    std::size_t nb = 0;
    while (start <= end) {
        start = text.find(str, start);
        if (start != std::string::npos) {
            nb++;
            start += str.length();
        }
        else {
            break;
        }
    }
    
    return nb;
}

std::vector<std::string> StringUtils::split(std::string &text, std::string &separator)
{
    std::vector<std::string> elems;
    std::size_t last_pos = 0;
    std::size_t pos = text.find(separator);
    while (pos != std::string::npos && last_pos != std::string::npos)
    {
        if (pos - last_pos > 0)
        {
            elems.push_back(text.substr(last_pos, pos - last_pos));
        }
        
        last_pos = text.find_first_not_of(separator, pos+separator.length()-1);
        pos = text.find(separator, last_pos);
    }
    
    if (last_pos != std::string::npos)
    {
        elems.push_back(text.substr(last_pos));
    }
    
    return elems;
}

std::string StringUtils::join(std::vector<std::string> &vect, std::string &delimiter)
{
    std::string retval;
    
    std::vector<std::string>::const_iterator began = vect.begin();
    std::vector<std::string>::const_iterator end = vect.end();
    for (; began != end; ++began)
    {
        retval.append(*began);
        retval.append(delimiter);
    }
    retval.erase(retval.length() - delimiter.length());
    
    return retval;
}

bool StringUtils::iequals(const std::string a, const std::string b, bool ignore_case)
{
    std::size_t sz = a.length();
    if (b.length() != sz)
        return false;
    
    for (std::size_t i = 0; i < sz; ++i)
    {
        if (ignore_case)
        {
            if (::tolower(a[i]) != ::tolower(b[i]))
            {
                return false;
            }
        }
        else
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
    }
    
    return true;
}

std::string StringUtils::replace(std::string &text, std::string &from, std::string &to)
{
    std::string temp(text);
    std::size_t start_pos = 0;
    start_pos = temp.find(from, start_pos);
    if (start_pos != std::string::npos) {
        temp.replace(start_pos, from.length(), to);
    }
    
    return temp;
}

std::string StringUtils::replace_all(std::string &text, std::string &from, std::string &to)
{
    std::string temp(text);
    if(!from.empty()) {
        size_t start_pos = 0;
        while ((start_pos = temp.find(from, start_pos)) != std::string::npos) {
            temp.replace(start_pos, from.length(), to);
            // In case 'to' contains 'from', like replacing 'x' with 'yx'
            start_pos += to.length();
        }
    }
    
    return temp;
}

std::string StringUtils::tolower(const std::string &text)
{
    std::string temp(text);
    std::transform(text.begin(),text.end(), temp.begin(), ::tolower);
    return temp;
}

std::string StringUtils::toupper(const std::string &text)
{
    std::string temp(text);
    std::transform(text.begin(),text.end(), temp.begin(), ::toupper);
    return temp;
}

std::string StringUtils::capitalize(const std::string &text)
{
    std::string temp(text);
    std::string::iterator it = temp.begin();
    *it = std::toupper(*it);
    return temp;
}


std::string &StringUtils::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &StringUtils::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
std::string &StringUtils::trim(std::string &s) {
    return ltrim(rtrim(s));
}

std::string StringUtils::ltrim(const std::string &s) {
    std::string temp(s);
    StringUtils::ltrim(temp);
    return temp;
}

// trim from end
std::string StringUtils::rtrim(const std::string &s) {
    std::string temp(s);
    StringUtils::rtrim(temp);
    return temp;
}

// trim from both ends
std::string StringUtils::trim(const std::string &s) {
    std::string temp(s);
    StringUtils::trim(temp);
    return temp;
}
