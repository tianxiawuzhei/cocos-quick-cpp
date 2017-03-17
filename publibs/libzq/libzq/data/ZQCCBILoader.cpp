/***********************************************
* ZQCCBILoader.cpp
*
* @author: zyq
* @date: 17/3/3
* @Description:
*
***********************************************/

#include "ZQCCBILoader.h"
#include "data/ZQFileManage.h"
#include "data/ZQPlistManage.h"
#include "data/ZQImageLoader.h"

using namespace zq;

ZQCCBILoader* ZQCCBILoader::getInstance()
{
    static ZQCCBILoader instance;
    return &instance;
}

cocosbuilder::CCBReader* ZQCCBILoader::createCCBReader()
{
    cocosbuilder::NodeLoaderLibrary *ccNodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::getInstance();
    cocosbuilder::CCBReader * pCCBReader = new (std::nothrow) cocosbuilder::CCBReader(ccNodeLoaderLibrary);
    pCCBReader->autorelease();
    
    return pCCBReader;
}

cocos2d::Node* ZQCCBILoader::readNodeGraphFromFile(const std::string &ccbi, cocosbuilder::CCBReader *pCCBReader)
{
    if (nullptr == pCCBReader || ccbi.empty())
    {
        return nullptr;
    }
    
    auto data = this->_cache[ccbi];
    if (!data)
    {
        return nullptr;
    }
    
    cocos2d::Node *pNode = nullptr;
    pNode = pCCBReader->readNodeGraphFromData(data, nullptr, cocos2d::Director::getInstance()->getWinSize());
    
    return pNode;
}

bool ZQCCBILoader::load(const std::string &ccbi, bool cache)
{
    auto result = this->list(ccbi);
    if (result.empty())
        return false;
    
    std::vector<std::string> plist;
    std::vector<std::string> image;
    std::vector<std::string> frame;
    std::vector<std::string> store;
    
    auto ret = true;
    auto front = ZQFileManage::dirname_of_path(ccbi, true);
    
    for (auto &name : result)
    {
        auto ext = ZQFileManage::extname_of_path(name, false);
        if ("plist" == ext)
        {
            auto temp = ZQPlistManage::getInstance()->load_dict(front+name);
            if (!front.empty())
            {
                ZQPlistManage::getInstance()->alias(cocos2d::Value(temp), name);
            }
            
            if (!temp.empty())
            {
                auto &tmp = temp["frames"].asValueMap();
                for (auto &pair : tmp)
                    frame.push_back(pair.first);
                
                plist.push_back(name);
                store.push_back(ZQFileManage::dirname_of_path(name, true) + temp["metadata"].asValueMap()["realTextureFileName"].asString());
            }
            else
            {
                ret = false;
            }
        }
        else if (ext == "png" || ext == "jpg")
        {
            image.push_back(name);
        }
    }
    
    for (auto it = image.begin(); it != image.end();)
    {
        auto name = *it;
        auto find = std::find(frame.begin(), frame.end(), name);
        if (find != frame.end())
        {
            it = image.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    for (auto &name : image)
    {
        if (cache)
        {
            if (!ZQImageLoader::getInstance()->load_image(front + name, name))
                ret = false;
        }
        else
        {
            if (ZQFileManage::getInstance()->load_file(front+name).empty())
                ret = false;
        }
    }
    
    if (cache)
    {
        for (auto &name : plist)
        {
            if (!ZQImageLoader::getInstance()->cache(front + name))
                ret = false;
        }
    }
    else
    {
        for (auto &name : store)
        {
            if (ZQFileManage::getInstance()->load_file(front+name).empty())
                ret = false;
        }
    }

    return ret;
}

void ZQCCBILoader::clear()
{
    this->_cache.clear();
}

std::vector<std::string> ZQCCBILoader::list(const std::string &ccbi)
{
    auto data = this->_cache[ccbi];
    if (!data)
    {
        data = std::make_shared<cocos2d::Data>(ZQFileManage::getInstance()->file_data(ccbi));
        if (data->getSize())
        {
            this->_cache[ccbi] = data;
        }
        else
        {
            return std::vector<std::string>();
        }
    }
    
    CCBIPrase prase;
    return prase.read(data);
}

CCBIPrase::CCBIPrase()
{
    this->_nodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::getInstance();
    CC_SAFE_RETAIN(this->_nodeLoaderLibrary);
}

std::vector<std::string> CCBIPrase::read(std::shared_ptr<cocos2d::Data> data)
{
    this->_data = data;
    this->_bytes = this->_data->getBytes();
    this->_currentByte = 0;
    this->_currentBit = 0;
    
    if (!this->readHeader())
    {
        return std::vector<std::string>();
    }
    
    if (!this->readStringCache())
    {
        return std::vector<std::string>();
    }
    
    return this->_stringCache;
}
