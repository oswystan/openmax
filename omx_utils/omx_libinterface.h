/*
 **************************************************************************************
 *       Filename:  omx_libinterface.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-12-01 16:25:35
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_LIBINTERFACE_H_INCLUDED
#define OMX_LIBINTERFACE_H_INCLUDED

#include "OMX_Core.h"
#define OMX_LIB_INTERFACE_ID 0x77797374

class OmxLibInterface
{
public:
    OmxLibInterface()
    {
    }
    virtual ~OmxLibInterface()
    {
    }

    virtual const char* enumComponent(int index) = 0;
    virtual const char* enumRoles(int index, const char* component) = 0;
    virtual int createComponent(OMX_HANDLETYPE* handle, OMX_STRING name, OMX_PTR appData, OMX_CALLBACKTYPE* callback) = 0;
    virtual void destoryComonent(OMX_HANDLETYPE handle) = 0;
};

#endif /*OMX_LIBINTERFACE_H_INCLUDED*/
/********************************* END ***********************************************/


