/*
 **************************************************************************************
 *       Filename:  omx_thread.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 22:51:30
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_THREAD_H_INCLUDED
#define OMX_THREAD_H_INCLUDED

#include <pthread.h>

#include "omx_condition.h"

enum { MAX_THREAD_NAME = 32 };

class OmxThread
{
public:
    OmxThread();
    virtual ~OmxThread();

    virtual int onStart();
    virtual int onExit();
    virtual int threadLoop();

    int run(const char* name);

    int requestExit();
    int requestExitAndWait();
    int threadFunc();

protected:
    OmxCondition threadCond;
    OmxMutex     threadMutex;

    int     exitPending;
    int     runningState;
    char    threadName[MAX_THREAD_NAME];
    pthread_t threadID;

};

#endif /*OMX_THREAD_H_INCLUDED*/

/********************************* END ***********************************************/

