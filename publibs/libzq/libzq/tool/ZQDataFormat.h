/***********************************************
* ZQDataFormat.h
*
* @author: zyq
* @date: 17/3/20
* @Description:
*
***********************************************/
#pragma once

#include "cocos2d.h"

namespace zq
{
    class DataFormat
    {
    public:
        DataFormat(size_t indent = 0, bool pretty = true);
        
    public:
        virtual void visit(const cocos2d::Value &p);
        virtual void visit(unsigned char p);
        virtual void visit(bool p);
        virtual void visit(int p);
        virtual void visit(float p);
        virtual void visit(double p);
        virtual void visit(const std::string &p);
        virtual void visit(const cocos2d::ValueMap &p);
        virtual void visit(const cocos2d::ValueVector &p);
    
    public:
        virtual std::string result();
        virtual void clear();
        
    private:
        void indent(size_t val);
    
    private:
        bool _pretty;
        
        std::string _indent;
        std::string _result;
    };
}

