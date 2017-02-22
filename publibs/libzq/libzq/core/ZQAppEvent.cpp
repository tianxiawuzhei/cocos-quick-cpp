/***********************************************
* ZQAppEvent.cpp
*
* @author: zyq
* @date: 17/2/22
* @Description:
*
***********************************************/
#include "ZQAppEvent.h"

using namespace zq;

ZQAppEvent* ZQAppEvent::getInstance()
{
    static ZQAppEvent instance;
    return &instance;
}

void ZQAppEvent::applicationDidFinishLaunching()
{
    this->emit("applicationDidFinishLaunching");
}

void ZQAppEvent::applicationWillEnterForeground()
{
    this->emit("applicationWillEnterForeground");
}

void ZQAppEvent::applicationDidEnterBackground()
{
    this->emit("applicationDidEnterBackground");
}

void ZQAppEvent::applicationDidReceiveMemoryWarning()
{
    this->emit("applicationDidReceiveMemoryWarning");
}

void ZQAppEvent::androidShouldReset()
{
    this->emit("androidShouldReset");
}
