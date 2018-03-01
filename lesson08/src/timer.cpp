#include "timer.h"

timer::timer()
{
    //ctor
    startedAt =0;
    pausedAt = 0;
    paused = false;
    started = false;
}

timer::~timer()
{
    //dtor
}

bool timer::isStarted()
{
    return Started;
}

bool timer::isStopped()
{
    return isStopped;
}

bool timer::isPaused()
{
     return isPaused;
}

void timer::pause()
{
    if (passed || !started)
        return;
    paused = true;
    pausedAt = clock();

}

void timer::resume()
{
    if(!paused) return;
    paused = false;
    startedAt +=clock()-pauseAt;

}

void timer::stop()
{
    started = false;
}

void timer::reset()
{

}


clock_t timer::getTicks()
{

}
