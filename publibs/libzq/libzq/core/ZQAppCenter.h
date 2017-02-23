/***********************************************
* ZQAppCenter.h
*
* @author: zyq
* @date: 17/2/22
* @Description:
*
***********************************************/

#ifndef __ZQAPPCENTER_H__
#define __ZQAPPCENTER_H__

#include <string>

namespace zq
{
    class ZQAppCenter
    {
    public:
        static ZQAppCenter* getInstance();
    
    protected:
        ZQAppCenter() = default;
        virtual ~ZQAppCenter() = default;
        
    public:
        virtual void start();
        virtual void restart();
        virtual void quit();
        
    public:
        virtual bool isRestart();
        
    private:
        bool _restart = false;
        
    public:
        std::string _script_file;
    };
}




#endif /* defined(__ZQAPPCENTER_H__) */
