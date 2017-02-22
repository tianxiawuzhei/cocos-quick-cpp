/***********************************************
* ZQAppEvent.h
*
* @author: zyq
* @date: 17/2/22
* @Description:
*
***********************************************/

#ifndef __ZQAPPEVENT_H__
#define __ZQAPPEVENT_H__

#include "core/ZQScriptHandler.h"

namespace zq
{
    class ZQAppEvent : public ZQScriptHandler
    {
    public:
        static ZQAppEvent* getInstance();
        
    protected:
        ZQAppEvent() = default;
        virtual ~ZQAppEvent() = default;
        
    public:
        void applicationDidFinishLaunching();
        void applicationDidEnterBackground();
        void applicationWillEnterForeground();
        void applicationDidReceiveMemoryWarning();
        
        void androidShouldReset();
    };
}


#endif /* defined(__ZQAPPEVENT_H__) */
