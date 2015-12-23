/*
 **************************************************************************************
 *       Filename:  omx_condition.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 23:52:53
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_CONDITION_H_INCLUDED
#define OMX_CONDITION_H_INCLUDED

#include "omx_mutex.h"

class OmxCondition
{
public:
    OmxCondition();
    ~OmxCondition();

    int wait(OmxMutex& m);
    int broadcast();
    int signal();

private:
    pthread_cond_t cond;
};




#endif /*OMX_CONDITION_H_INCLUDED*/

/********************************* END ***********************************************/

