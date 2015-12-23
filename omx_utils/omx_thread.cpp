/*
 **************************************************************************************
 *       Filename:  omx_thread.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 22:55:00
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxThread"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include<sys/prctl.h>

#include "omx_log.h"
#include "omx_thread.h"


/*
 **************************************************************************
 * FunctionName: OmxThread::OmxThread;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxThread::OmxThread ( void )
{
    exitPending  = 0;
    runningState = 0;
    threadID     = 0;
    snprintf(threadName, sizeof(threadName), "uname-omx-thread");
}
OmxThread::~OmxThread ( void )
{
}

/*
 **************************************************************************
 * FunctionName: threadFunc;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
void* threadFunc ( void* user)
{
    OmxThread* t = (OmxThread*)user;
    t->threadFunc();
    return NULL;
}

/*
 **************************************************************************
 * FunctionName: OmxThread::threadFunc;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::threadFunc ( void )
{
    int ret = 0;

    prctl(PR_SET_NAME, threadName, 0, 0, 0);

    OMX_LOGI("thread <%s> START!", threadName);
    ret = onStart();
    if(ret != 0)
    {
        OMX_LOGE("fail to call onStart, exit ..");
        onExit();
        return ret;
    }

    runningState = 1;

    while(!exitPending)
    {
        ret = threadLoop();
        if(0 != ret)
        {
            break;
        }
    }


    onExit();
    runningState = 0;
    threadCond.broadcast();
    OMX_LOGI("thread <%s> EXIT!", threadName);
    return ret;
}

/*
 **************************************************************************
 * FunctionName: OmxThread::onStart;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::onStart ( void )
{
    return 0; 
}

/*
 **************************************************************************
 * FunctionName: OmxThread::onExit;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::onExit ( void )
{
    return 0;
}


/*
 **************************************************************************
 * FunctionName: OmxThread::threadLoop;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::threadLoop ( void )
{
    OMX_LOGW("TODO you need to implement this function ...");
    sleep(1);
    return 0;
}
/*
 **************************************************************************
 * FunctionName: OmxThread::run;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::run ( const char* name )
{
    OmxAutolock lock(threadMutex);

    snprintf(threadName, sizeof(threadName), "%s", name);
    int ret = pthread_create(&threadID, NULL, ::threadFunc, this);
    if(ret < 0)
    {
        OMX_LOGE("fail to create thread <%s>", name);
    }
    return ret;
}

/*
 **************************************************************************
 * FunctionName: OmxThread::requestExit;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::requestExit ( void )
{
    OmxAutolock lock(threadMutex);
    exitPending = 1;
    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxThread::requestExitAndWait;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxThread::requestExitAndWait ( void )
{
    OmxAutolock lock(threadMutex);
    exitPending = 1;

    while(runningState)
    {
        threadCond.wait(threadMutex);
    }

    exitPending = 0;
    return 0;
}

/********************************** END **********************************************/

