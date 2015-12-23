/*
 **************************************************************************************
 *       Filename:  omx_stateimpl.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-12-02 15:42:19
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_STATEIMPL_H_INCLUDED
#define OMX_STATEIMPL_H_INCLUDED

#include "omx_stateinterface.h"
class OmxStateLoaded : public OmxStateInterface
{
public:
    OmxStateLoaded(){}
    ~OmxStateLoaded(){}
};

class OmxStateWaitForResource : public OmxStateInterface
{
public:
    OmxStateWaitForResource(){}
    ~OmxStateWaitForResource(){}
};

class OmxStateIdle : public OmxStateInterface
{
public:
    OmxStateIdle(){}
    ~OmxStateIdle(){}
};

class OmxStatePause : public OmxStateInterface
{
public:
    OmxStatePause(){}
    ~OmxStatePause() {}
};

class OmxStateExecuting : public OmxStateInterface
{
public:
    OmxStateExecuting(){}
    ~OmxStateExecuting(){}
};

class OmxStateInvalid : public OmxStateInterface
{
public:
    OmxStateInvalid() {}
    ~OmxStateInvalid(){}
};

#endif /*OMX_STATEIMPL_H_INCLUDED*/
/********************************* END ***********************************************/


