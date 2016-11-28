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
    ZQImageManage* getInstance();
    
protected:
    ZQImageManage() = default;
    virtual ~ZQImageManage() = default;
    
public:
    cocos2d::SpriteFrame* loadImage(const std::string &path, const std::string &key = "");
};
    
}


#endif /* defined(__ZQImageManage_H__) */
