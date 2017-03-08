/***********************************************
* ZQImageManage.cpp
*
* @author: zyq
* @date: 16/11/25
* @Description:
*
***********************************************/

#include "ZQImageManage.h"
#include "data/ZQFileManage.h"
#include "data/ZQPlistManage.h"
#include "log/ZQLogger.h"


using namespace zq;

ZQImageManage* ZQImageManage::getInstance()
{
    static ZQImageManage instance;
    return &instance;
}

cocos2d::SpriteFrame* ZQImageManage::load_image(const std::string &path, const std::string &key)
{
    const std::string &cache_key = key.empty() ? path : key;
    auto texture = cocos2d::Director::getInstance()->getTextureCache()->getTextureForKey(cache_key);
    if (!texture)
    {
        auto data = ZQFileManage::getInstance()->getDataFromFile(path);
        if (data.isNull())
        {
            ZQLogE("loadImage: image file not found : %s ", path.c_str());
            return nullptr;
        }
        
        auto image = new (std::nothrow) cocos2d::Image();
        if (!image)
            return nullptr;
        
        bool bOk = image->initWithImageData(data.getBytes(), data.getSize());
        if (!bOk)
        {
            ZQLogE("loadImage: Load image from buffer error");
            image->release();
            return nullptr;
        }
        
        cocos2d::Director::getInstance()->getTextureCache()->addImage(image, cache_key);
        
        texture = cocos2d::Director::getInstance()->getTextureCache()->getTextureForKey(cache_key);
        if (!texture)
        {
            image->release();
            return nullptr;
        }
        
        image->release();
    }
    
    auto size = texture->getContentSize();
    return cocos2d::SpriteFrame::createWithTexture(texture, cocos2d::Rect(0, 0, size.width, size.height));
}

cocos2d::SpriteFrame* ZQImageManage::load_frame(const std::string &plist, const std::string &frame)
{
    auto spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(frame);
    if (spriteFrame)
    {
        return spriteFrame;
    }
    
    auto dict = ZQPlistManage::getInstance()->load_dict(plist);
    if (dict.empty())
    {
        ZQLogE("loadFrame: load plist file fail: %s, %s", plist.c_str(), frame.c_str());
        return nullptr;
    }
    
    std::string texturePath("");
    
    if (dict.find("metadata") != dict.end())
    {
        cocos2d::ValueMap& metadataDict = dict["metadata"].asValueMap();
        // try to read  texture file name from meta data
        texturePath = metadataDict["realTextureFileName"].asString();
    }
    
    if (texturePath.empty())
    {
        ZQLogE("loadFrame: plist file not find texture file: %s, %s", plist.c_str(), frame.c_str());
        return nullptr;
    }
    
    auto dir = ZQFileManage::dirname_of_path(plist, true);
    auto imageFrame = this->load_image(dir + texturePath, texturePath);
    
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithDictionary(dict, imageFrame->getTexture());
    
    spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(frame);
    if (!spriteFrame)
    {
        ZQLogE("loadFrame: load frame fail :  %s, %s", plist.c_str(), frame.c_str());
        return nullptr;
    }

    return spriteFrame;
    
}


bool ZQImageManage::exist(const std::string &plist, const std::string &frame)
{
    return true;
}


