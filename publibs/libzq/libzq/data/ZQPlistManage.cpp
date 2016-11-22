//
//  ZQPlistManage.cpp
//  libzq
//
//  Created by staff on 16/11/11.
//  Copyright © 2016年 zyqiosexercise. All rights reserved.
//

#include "ZQPlistManage.hpp"
#include "data/ZQFileManage.hpp"
#include "rapidxml/rapidxml.hpp"

using namespace zq;

namespace {
    void parseDict(const rapidxml::xml_node<> *node, cocos2d::ValueMap &dict);
    void parseArray(const rapidxml::xml_node<> *node, cocos2d::ValueVector &array);
    
    void parseDict(const rapidxml::xml_node<> *node, cocos2d::ValueMap &dict)
    {
        while (node) {
            auto key_node = node;
            auto val_node = key_node->next_sibling();
            
            std::string key_name = std::string(key_node->name(), key_node->name_size());
            std::string val_name = std::string(val_node->name(), val_node->name_size());

            if (val_name == "dict")
            {
                cocos2d::ValueMap map;
                parseDict(val_node->first_node(), map);
                dict[key_name] = std::move(map);
            }
            else if (val_name == "array")
            {
                cocos2d::ValueVector vect;
                parseArray(node->first_node(), vect);
                dict[key_name] = std::move(vect);
            }
            else if (val_name == "string")
            {
                dict[key_name] = std::move(cocos2d::Value(val_node->value()));
            }
            else if (val_name == "integer")
            {
                dict[key_name] = cocos2d::Value(atoi(val_node->value()));
            }
            else if (val_name == "real")
            {
                dict[key_name] = cocos2d::Value(atof(val_node->value()));
            }
            else if (val_name == "false")
            {
                dict[key_name] = cocos2d::Value(false);
            }
            else if (val_name == "true")
            {
                dict[key_name] = cocos2d::Value(true);
            }
            
            node = val_node->next_sibling();
        }
    }
    
    void parseArray(const rapidxml::xml_node<> *node, cocos2d::ValueVector &array)
    {
        while (node) {
            std::string name = std::string(node->name(), node->name_size());
            if (name == "array")
            {
                cocos2d::ValueVector vect;
                parseArray(node->first_node(), vect);
                array.push_back(std::move(cocos2d::Value(std::move(vect))));
            }
            else if (name == "dict")
            {
                cocos2d::ValueMap map;
                parseDict(node->first_node(), map);
                array.push_back(std::move(cocos2d::Value(std::move(map))));
            }
            else if (name == "string")
            {
                array.push_back(std::move(cocos2d::Value(node->value())));
            }
            else if (name == "integer")
            {
                array.push_back(cocos2d::Value(atoi(node->value())));
            }
            else if (name == "real")
            {
                array.push_back(cocos2d::Value(atof(node->value())));
            }
            else if (name == "false")
            {
                array.push_back(cocos2d::Value(false));
            }
            else if (name == "true")
            {
                array.push_back(cocos2d::Value(true));
            }

        }
    }
}

ZQPlistManage* ZQPlistManage::getInstance()
{
    static ZQPlistManage instance;
    return &instance;
}

cocos2d::ValueMap ZQPlistManage::getDictFromFile(const std::string &filename)
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

cocos2d::ValueMap ZQPlistManage::getDictFromText(const std::string &text)
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

cocos2d::ValueVector ZQPlistManage::getArrayFromFile(const std::string &filename)
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

cocos2d::ValueVector ZQPlistManage::getArrayFromText(const std::string &text)
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

cocos2d::Value ZQPlistManage::getValueFromFile(const std::string &filename)
{
    const std::string text = ZQFileManage::getInstance()->getStringFromFile(filename);
    return getValueFromText(text);
}

cocos2d::Value ZQPlistManage::getValueFromText(const std::string &text)
{
    if (text.empty())
    {
        return cocos2d::Value::Null;
    }
    
    std::unique_ptr<char[]> buff(new char[text.size() + 1]);
    std::copy(text.begin(), text.end(), buff.get());
    buff.get()[text.size()] = '\0'; // don't forget the terminating 0
    
    rapidxml::xml_document<> doc;
    try {
        doc.parse<0>(buff.get());
    } catch (rapidxml::parse_error &e) {
        
    } catch(std::exception &e) {
        
    }
    
    rapidxml::xml_node<> *root = doc.first_node();
    if (!root)
    {
        return cocos2d::Value::Null;
    }
    
    rapidxml::xml_node<> *node = root->first_node();
    
    if (!node)
    {
        return cocos2d::Value::Null;
    }
    
    std::string name = std::string(node->name(), node->name_size());
    if (name == "array")
    {
        cocos2d::ValueVector vect;
        parseArray(node->first_node(), vect);
        return cocos2d::Value(std::move(vect));
    }
    else if (name == "dict")
    {
        cocos2d::ValueMap map;
        parseDict(node->first_node(), map);
        return cocos2d::Value(std::move(map));
    }
    
    return cocos2d::Value::Null;
}


