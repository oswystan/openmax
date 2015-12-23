/*
 **************************************************************************************
 *       Filename:  omx_mutex.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-26 22:40:23
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_MUTEX_H_INCLUDED
#define OMX_MUTEX_H_INCLUDED

#include <pthread.h>

class OmxCondition;

class OmxMutex
{
public:
    OmxMutex();
    ~OmxMutex();

    int lock();
    int unlock();

private:
    pthread_mutex_t mutex;
    friend OmxCondition;
};

class OmxAutolock
{
public:
    OmxAutolock(OmxMutex& mutex)
        : lock(mutex)
    {
        lock.lock();
    }
    ~OmxAutolock()
    {
        lock.unlock();
    }

private:
    OmxMutex& lock;
};

#endif /*OMX_MUTEX_H_INCLUDED*/

/********************************* END ***********************************************/

