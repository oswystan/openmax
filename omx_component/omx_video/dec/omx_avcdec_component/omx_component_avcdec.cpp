/*
 **************************************************************************************
 *       Filename:  omx_component_avcdec.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-12-01 22:02:45
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxAvcDecComponent"

#include <stdio.h>
#include "omx_log.h"
#include "omx_component_avcdec.h"



/*
 **************************************************************************
 * FunctionName: OmxAvcDecComponent::OmxAvcDecComponent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxAvcDecComponent::OmxAvcDecComponent ( OMX_HANDLETYPE* handle )
        : OmxComponent(handle)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
}
OmxAvcDecComponent::~OmxAvcDecComponent ( void )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
}








/********************************** END **********************************************/


