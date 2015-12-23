/*
 **************************************************************************************
 *       Filename:  omx_sem.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-26 23:44:38
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <errno.h>
#include "omx_sem.h"

/*
 **************************************************************************
 * FunctionName: OmxSem::OmxSem;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxSem::OmxSem ( int count )
{
    sem_init(&sem, 0, count);
    return;
}
OmxSem::~OmxSem ( void )
{
    sem_destroy(&sem);
    return;
}

/*
 **************************************************************************
 * FunctionName: OmxSem::wait;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxSem::wait ( void )
{
    if(sem_wait(&sem) != 0)
    {
        return errno;
    }

    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxSem::post;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxSem::post ( void )
{
    if(sem_post(&sem) != 0)
    {
        return errno;
    }

    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxSem::getCount;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxSem::getCount ( int* count )
{
    int value = 0;
    if(sem_getvalue(&sem, &value) != 0)
    {
        return errno;
    }
    
    *count = value;
    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxSem::setCount;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxSem::setCount ( int count )
{
    if(sem_init(&sem, 0, count) != 0)
    {
        return errno;
    }

    return 0;
}

/********************************** END **********************************************/

