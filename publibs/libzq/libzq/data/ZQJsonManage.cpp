//
//  ZQJsonManage.cpp
//  libzq
//
//  Created by staff on 16/11/9.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQJsonManage.hpp"
#include "data/ZQFileManage.hpp"
#include "json/document.h"

using namespace zq;

static void parseDict(const rapidjson::Value& json, cocos2d::ValueMap& dict);
static void parseArray(const rapidjson::Value& json, cocos2d::ValueVector& array);

static void parseArray(const rapidjson::Value& json, cocos2d::ValueVector& array)
{
    for (rapidjson::SizeType i = 0; i < json.Size(); i++)
    {
        const rapidjson::Value &item = json[i];
        if (item.IsNull())
        {
            array.push_back(cocos2d::Value::Null);
        }
        else if (item.IsArray())
        {
            cocos2d::ValueVector vect;
            parseArray(item, vect);
            array.push_back(std::move(cocos2d::Value(std::move(vect))));
        }
        else if (item.IsObject())
        {
            cocos2d::ValueMap map;
            parseDict(item, map);
            array.push_back(std::move(cocos2d::Value(std::move(map))));
        }
        else if (item.IsString())
        {
            array.push_back(cocos2d::Value(item.GetString()));
        }
        else if (item.IsBool())
        {
            array.push_back(cocos2d::Value(item.GetBool()));
        }
        else
        {
            if (item.IsDouble())
            {
                array.push_back(cocos2d::Value(item.GetDouble()));
            }
            else
            {
                array.push_back(cocos2d::Value(item.GetInt()));
            }
        }

        
    }
}

static void parseDict(const rapidjson::Value& json, cocos2d::ValueMap& dict)
{
    for (rapidjson::Value::ConstMemberIterator itr = json.MemberBegin();
         itr != json.MemberEnd(); ++itr)
    {
        std::string key = itr->name.GetString();
        const rapidjson::Value& value = itr->value;
        if (value.IsNull())
        {
            dict[key] = cocos2d::Value::Null;
        }
        else if (value.IsArray())
        {
            cocos2d::ValueVector vect;
            parseArray(value, vect);
            dict[key] = std::move(cocos2d::Value(std::move(vect)));
        }
        else if (value.IsObject())
        {
            cocos2d::ValueMap map;
            parseDict(value, map);
            dict[key] = std::move(cocos2d::Value(std::move(map)));
        }
        else if (value.IsString())
        {
            dict[key] = cocos2d::Value(value.GetString());
        }
        else if (value.IsBool())
        {
            dict[key] = cocos2d::Value(value.GetBool());
        }
        else
        {
            if (value.IsDouble())
            {
                dict[key] = cocos2d::Value(value.GetDouble());
            }
            else
            {
                dict[key] = cocos2d::Value(value.GetInt());
            }
        }
        
    }
}

ZQJsonManage* ZQJsonManage::_instanceJsonManage = nullptr;

ZQJsonManage* ZQJsonManage::getInstance()
{
    if (_instanceJsonManage == nullptr)
    {
        _instanceJsonManage = new (std::nothrow) ZQJsonManage();
        if(!_instanceJsonManage->init())
        {
            delete _instanceJsonManage;
            _instanceJsonManage = nullptr;
            CCLOG("ERROR: Could not init _instanceJsonManage");
        }
    }
    
    return _instanceJsonManage;
}


bool ZQJsonManage::init()
{
    return true;
}

cocos2d::ValueMap ZQJsonManage::getDictFromFile(const std::string &filename)
{
    cocos2d::Value val = this->getValueFromFile(filename);
    if (val.getType() == cocos2d::Value::Type::MAP)
    {
        return val.asValueMap();
    }
    else
    {
        return cocos2d::ValueMapNull;
    }
}

cocos2d::ValueMap ZQJsonManage::getDictFromText(const std::string &text)
{
    cocos2d::Value val = this->getValueFromText(text);
    if (val.getType() == cocos2d::Value::Type::MAP)
    {
        return val.asValueMap();
    }
    else
    {
        return cocos2d::ValueMapNull;
    }
}

cocos2d::ValueVector ZQJsonManage::getArrayFromFile(const std::string &filename)
{
    cocos2d::Value val = this->getValueFromFile(filename);
    if (val.getType() == cocos2d::Value::Type::VECTOR)
    {
        return val.asValueVector();
    }
    else
    {
        return cocos2d::ValueVectorNull;
    }
}

cocos2d::ValueVector ZQJsonManage::getArrayFromText(const std::string &text)
{
    cocos2d::Value val = this->getValueFromText(text);
    if (val.getType() == cocos2d::Value::Type::VECTOR)
    {
        return val.asValueVector();
    }
    else
    {
        return cocos2d::ValueVectorNull;
    }
}

cocos2d::Value ZQJsonManage::getValueFromFile(const std::string &filename)
{
    const std::string text = ZQFileManage::getInstance()->getStringFromFile(filename);
    return getValueFromText(text);
}

cocos2d::Value ZQJsonManage::getValueFromText(const std::string &text)
{
    if (text.empty())
    {
        return cocos2d::Value::Null;
    }
    
    rapidjson::Document doc;
    doc.Parse<0>(text.c_str());
    if (doc.HasParseError())
    {
        CCLOG("GetParseError %d\n",doc.GetParseError());
    }
    
    if (doc.IsObject())
    {
        cocos2d::ValueMap dict;
        parseDict(doc, dict);
        return cocos2d::Value(std::move(dict));
    }
    else if (doc.IsArray())
    {
        cocos2d::ValueVector vect;
        parseArray(doc, vect);
        return cocos2d::Value(std::move(vect));
    }
    else
    {
        
    }
    
    return cocos2d::Value::Null;
}
