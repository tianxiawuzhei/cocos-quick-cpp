/***********************************************
* ZQImageManage.h
*
* @author: zyq
* @date: 16/11/25
* @Description:
*
***********************************************/

#ifndef __ZQImageManage_H__
#define __ZQImageManage_H__

#include "cocos2d.h"
namespace zq
{
    class ZQImageLoader
    {
    public:
        static ZQImageLoader* getInstance();

    protected:
        ZQImageLoader() = default;
        ~ZQImageLoader() = default;

    public:
        cocos2d::SpriteFrame* load_image(const std::string &path, const std::string &key = "");
        
        cocos2d::SpriteFrame* load_frame(const std::string &plist, const std::string &frame);

    public:
        bool exist(const std::string &plist, const std::string &frame = "");
        
        bool cache(const std::string &plist);
        
        void clear(const std::string &plist = "", const std::string &frame = "");
    };
    
}


#endif /* defined(__ZQImageManage_H__) */
