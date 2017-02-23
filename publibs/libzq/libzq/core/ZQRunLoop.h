/***********************************************
* ZQRunLoop.h
*
* @author: zyq
* @date: 17/2/22
* @Description:
*
************************************************/

#ifndef __ZQRUNLOOP_H__
#define __ZQRUNLOOP_H__

#include <mutex>
#include <list>
#include <functional>

namespace zq
{
    class ZQRunLoop
    {
    public:
        static ZQRunLoop* getInstance();
    
    protected:
        ZQRunLoop();
        virtual ~ZQRunLoop();
    
    public:
        typedef std::function<void ()> type_callback;
        typedef std::pair<void*, type_callback> type_store;
        
    public:
        void reset();
        
    public:
        void schedule(type_callback callback, void *caller);
        void unschedule(void *caller);
        
    public:
        void update(float dt);
        
    private:
        std::mutex _mutex;
        std::list<type_store> _queue;
        
    };
}



#endif /* defined(__ZQRUNLOOP_H__) */
