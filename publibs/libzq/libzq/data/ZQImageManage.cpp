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
#include "log/ZQLogger.h"

using namespace zq;

ZQImageManage* ZQImageManage::getInstance()
{
    static ZQImageManage instance;
    return &instance;
}

cocos2d::SpriteFrame* ZQImageManage::loadImage(const std::string &path, const std::string &key)
{
    const std::string &cache_key = key.empty() ? image : key;
    auto texture = cocos2d::Director::getInstance()->getTextureCache()->getTextureForKey(cache_key);
    if (!texture)
    {
        auto data = ZQFileManage::getInstance()->getDataFromFile(path);
        if (data.isNull())
        {
            ZQLogE("loadImage: image file not found : %s ", path.c_str());
            return nullptr;
        }
        
        auto image = new (std::nothrow) Image();
        if (!image)
            return nullptr;
        
        bool bOk = image->initWithImageData(data.getBytes, data.getSize());
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
