/***********************************************
* ZQCCBILoader.h
*
* @author: zyq
* @date: 17/3/3
* @Description:
*
***********************************************/

#ifndef __ZQCCBILOADER_H__
#define __ZQCCBILOADER_H__

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "cocos2d.h"
#include "editor-support/cocosbuilder/CocosBuilder.h"

namespace zq
{
    class ZQCCBILoader
    {
    public:
        static ZQCCBILoader* getInstance();
        
    protected:
        ZQCCBILoader() = default;
        ~ZQCCBILoader() = default;
    
    public:
        static cocosbuilder::CCBReader* createCCBReader();
        
        cocos2d::Node* readNodeGraphFromFile(const std::string &filename, cocosbuilder::CCBReader* pCCBReader);
    public:
        bool load(const std::string &ccbi, bool cache = false);
        
        void clear();
        
    protected:
        std::vector<std::string> list(const std::string &ccbi);
    
    private:
        std::unordered_map<std::string, std::shared_ptr<cocos2d::Data>> _cache;
        
    };
    
    class CCBIPrase : public cocosbuilder::CCBReader
    {
    public:
        CCBIPrase();
        ~CCBIPrase() = default;
        
    public:
        std::vector<std::string> read(std::shared_ptr<cocos2d::Data> data);
    };
}


#endif /* defined(__ZQCCBILOADER_H__) */
