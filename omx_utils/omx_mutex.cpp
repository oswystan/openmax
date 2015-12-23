/*
 **************************************************************************************
 *       Filename:  omx_mutex.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-26 22:49:13
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */


#include "omx_mutex.h"



/*
 **************************************************************************
 * FunctionName: OmxMutex::OmxMutex;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxMutex::OmxMutex()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&mutex, &attr);
}
OmxMutex::~OmxMutex()
{
    pthread_mutex_destroy(&mutex);
}

/*
 **************************************************************************
 * FunctionName: OmxMutex::lock;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxMutex::lock ( void )
{
    return pthread_mutex_lock(&mutex);
}

/*
 **************************************************************************
 * FunctionName: OmxMutex::unlock;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxMutex::unlock ( void )
{
    return pthread_mutex_unlock(&mutex);
}

/********************************** END **********************************************/

