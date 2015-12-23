/*
 **************************************************************************************
 *       Filename:  omx_condition.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 23:56:01
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */


#include "omx_condition.h"


/*
 **************************************************************************
 * FunctionName: OmxCondition::OmxCondition;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxCondition::OmxCondition ( void )
{
    pthread_condattr_t attr;
    pthread_condattr_init(&attr);
    pthread_condattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&cond, &attr);
    pthread_condattr_destroy(&attr);
}
OmxCondition::~OmxCondition ( void )
{
    pthread_cond_destroy(&cond);
}

/*
 **************************************************************************
 * FunctionName: OmxCondition::wait;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxCondition::wait ( OmxMutex& m )
{
    return pthread_cond_wait(&cond, &m.mutex);
}

/*
 **************************************************************************
 * FunctionName: OmxCondition::signal;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxCondition::signal ( void )
{
    return pthread_cond_signal(&cond);
}

/*
 **************************************************************************
 * FunctionName: OmxCondition::broadcast;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxCondition::broadcast ( void )
{
    pthread_cond_broadcast(&cond);
    return 0;
}

/********************************** END **********************************************/

