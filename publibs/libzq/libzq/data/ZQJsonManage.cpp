//
//  ZQJsonManage.cpp
//  libzq
//
//  Created by staff on 16/11/9.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQJsonManage.h"
#include "data/ZQFileManage.h"
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

ZQJsonManage* ZQJsonManage::getInstance()
{
    static ZQJsonManage instance;
    return &instance;
}

const cocos2d::ValueMap& ZQJsonManage::load_dict(const std::string &filename)
{
    const cocos2d::Value &val = this->read_file(filename);
    if (val.getType() == cocos2d::Value::Type::MAP)
    {
        return val.asValueMap();
    }
    else
    {
        return cocos2d::ValueMapNull;
    }
}

cocos2d::ValueMap ZQJsonManage::text_dict(const std::string &text)
{
    cocos2d::Value val = this->read_text(text);
    if (val.getType() == cocos2d::Value::Type::MAP)
    {
        return val.asValueMap();
    }
    else
    {
        return cocos2d::ValueMapNull;
    }
}

const cocos2d::ValueVector& ZQJsonManage::load_array(const std::string &filename)
{
    const cocos2d::Value &val = this->read_file(filename);
    if (val.getType() == cocos2d::Value::Type::VECTOR)
    {
        return val.asValueVector();
    }
    else
    {
        return cocos2d::ValueVectorNull;
    }
}

cocos2d::ValueVector ZQJsonManage::text_array(const std::string &text)
{
    cocos2d::Value val = this->read_text(text);
    if (val.getType() == cocos2d::Value::Type::VECTOR)
    {
        return val.asValueVector();
    }
    else
    {
        return cocos2d::ValueVectorNull;
    }
}

bool ZQJsonManage::exist(const std::string &filename)
{
    return this->_cache.find(filename) != this->_cache.end();
}

bool ZQJsonManage::cache(const std::string &filename)
{
    return !this->read_file(filename).isNull();
}

void ZQJsonManage::clear(const std::string &filename)
{
    if (!filename.empty())
    {
        auto it = this->_cache.find(filename);
        if (it != this->_cache.end())
            this->_cache.erase(it);
    }
    else
    {
        this->_cache.clear();
    }
}

const cocos2d::Value& ZQJsonManage::read_file(const std::string &filename)
{
    if (this->_cache.find(filename) != this->_cache.end())
        return this->_cache[filename];
    
    auto text = ZQFileManage::getInstance()->getStringFromFile(filename);
    
    auto data = this->read_text(text);
    if (!data.isNull())
    {
        this->_cache[filename] = data;
        return this->_cache[filename];
    }
    
    return cocos2d::Value::Null;
}

cocos2d::Value ZQJsonManage::read_text(const std::string &text)
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
