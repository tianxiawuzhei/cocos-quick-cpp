/***********************************************
* ZQImageManage.cpp
*
* @author: zyq
* @date: 16/11/25
* @Description:
*
***********************************************/

#include "ZQImageLoader.h"
#include "data/ZQFileManage.h"
#include "data/ZQPlistManage.h"
#include "log/ZQLogger.h"

using namespace zq;

ZQImageLoader* ZQImageLoader::getInstance()
{
    static ZQImageLoader instance;
    return &instance;
}

cocos2d::SpriteFrame* ZQImageLoader::load_image(const std::string &path, const std::string &key)
{
    const std::string &cache_key = key.empty() ? path : key;
    auto texture = cocos2d::Director::getInstance()->getTextureCache()->getTextureForKey(cache_key);
    if (!texture)
    {
        auto data = ZQFileManage::getInstance()->file_data(path);
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

cocos2d::SpriteFrame* ZQImageLoader::load_frame(const std::string &plist, const std::string &frame)
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


bool ZQImageLoader::exist(const std::string &plist, const std::string &frame)
{
    if (!frame.empty())
        return cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(frame);
    
    auto dict = ZQPlistManage::getInstance()->load_dict(plist);
    if (dict.empty())
        return false;
    
    auto &frames = dict["frames"].asValueMap();
    for (auto &pair : frames)
    {
        if (!cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(pair.first))
            return false;
    }
    return true;
}

bool ZQImageLoader::cache(const std::string &plist)
{
    auto dict = ZQPlistManage::getInstance()->load_dict(plist);
    if (dict.empty())
    {
        return false;
    }
    
    auto &meta = dict["metadata"].asValueMap();
    auto image = meta["realTextureFileName"].asString();
    auto front = ZQFileManage::dirname_of_path(plist, true);
    
    auto frame = this->load_image(front + image);
    
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithDictionary(dict, frame->getTexture());
    
    return true;
}

void ZQImageLoader::clear(const std::string &plist, const std::string &frame)
{
    if (!frame.empty())
    {
        cocos2d::SpriteFrameCache::getInstance()->removeSpriteFrameByName(frame);
    }
    else
    {
        cocos2d::AnimationCache::destroyInstance();
        cocos2d::SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
        cocos2d::Director::getInstance()->getTextureCache()->removeUnusedTextures();
    }
}

