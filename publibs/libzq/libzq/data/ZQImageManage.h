/***********************************************
* ZQImageManage.h
*
* @author: zyq
* @date: 16/11/25
* @Description:
*
/***********************************************/

#ifndef __ZQImageManage_H__
#define __ZQImageManage_H__

#include "cocos2d.h"
namespace zq {
    
class ZQImageManage
{
public:
    static ZQImageManage* getInstance();
    
protected:
    ZQImageManage() = default;
    virtual ~ZQImageManage() = default;
    
public:
    cocos2d::SpriteFrame* loadImage(const std::string &path, const std::string &key = "");
    cocos2d::SpriteFrame* loadFrame(const std::string &plist, const std::string &frame);
};
    
}


#endif /* defined(__ZQImageManage_H__) */
