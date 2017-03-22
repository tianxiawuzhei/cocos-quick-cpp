/***********************************************
* ZQDataFormat.cpp
*
* @author: zyq
* @date: 17/3/20
* @Description:
*
***********************************************/

#include "ZQDataFormat.h"
#include "utils/ZQStringUtils.h"

using namespace zq;

DataFormat::DataFormat(size_t indent, bool pretty)
:_pretty(pretty)
{
    if (this->_pretty)
        this->indent(indent);
}

void DataFormat::visit(const cocos2d::Value &p)
{
    switch (p.getType())
    {
        case cocos2d::Value::Type::BYTE:
            this->visit(p);
            break;
            
        default:
            break;
    }
}

void DataFormat::visit(unsigned char p)
{
    this->_result += StringUtils::format("0x%x02x", p);
}

void DataFormat::visit(bool p)
{
    this->_result += p ? "true" : "false";
}

void DataFormat::visit(int p)
{
    this->_result += StringUtils::format("%d", p);
}

void DataFormat::visit(float p)
{
    this->_result += StringUtils::format("%f", p);
}

void DataFormat::visit(double p)
{
    this->_result += StringUtils::format("%lf", p);
}

void DataFormat::visit(const std::string &p)
{
    
}

void DataFormat::visit(const cocos2d::ValueMap &p)
{
    
}

void DataFormat::visit(const cocos2d::ValueVector &p)
{
    
}

std::string DataFormat::result()
{
    return this->_result;
}

void DataFormat::clear()
{
    this->_result.clear();
}

void DataFormat::indent(size_t val)
{
    
}
