/*
 **************************************************************************************
 *       Filename:  omx_sem.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-26 23:40:44
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_SEM_H_INCLUDED
#define OMX_SEM_H_INCLUDED

#include <semaphore.h>

class OmxSem
{
public:
    OmxSem(int count = 0);
    ~OmxSem();

    int wait();
    int post();
    int getCount(int* count);
    int setCount(int count);

private:
    sem_t sem;
};

#endif /*OMX_SEM_H_INCLUDED*/

/********************************* END ***********************************************/

