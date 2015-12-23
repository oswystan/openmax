/*
 **************************************************************************************
 *       Filename:  omx_component_avcdec.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-12-01 22:02:55
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_COMPONENT_AVCDEC_H_INCLUDED
#define OMX_COMPONENT_AVCDEC_H_INCLUDED

#include "omx_component.h"

class OmxAvcDecComponent : public OmxComponent
{
public:
    OmxAvcDecComponent(OMX_HANDLETYPE* handle);
    ~OmxAvcDecComponent();
};

#endif /*OMX_COMPONENT_AVCDEC_H_INCLUDED*/

/********************************* END ***********************************************/

