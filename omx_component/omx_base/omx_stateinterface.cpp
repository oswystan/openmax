/*
 **************************************************************************************
 *       Filename:  omx_stateinterface.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-12-02 15:39:00
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxStateInterface"
#include <stdio.h>
#include "omx_log.h"
#include "omx_stateinterface.h"


/*
 **************************************************************************
 * FunctionName: OmxStateInterface::getParameter;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::getParameter ( OMX_INDEXTYPE index, OMX_PTR para )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}
OMX_ERRORTYPE OmxStateInterface::setParameter ( OMX_INDEXTYPE index, OMX_PTR para )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::getConfig;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::getConfig ( OMX_INDEXTYPE index, OMX_PTR config )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}
OMX_ERRORTYPE OmxStateInterface::setConfig ( OMX_INDEXTYPE index, OMX_PTR config )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::getState;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::getState ( OMX_STATETYPE* state )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::getExtensionIndex;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::getExtensionIndex(OMX_STRING paraName, OMX_INDEXTYPE* indexType)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::componentTunnelRequest;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::componentTunnelRequest(OMX_U32 port,
                    OMX_HANDLETYPE tunnelComp,
                    OMX_U32 tunnelPort,
                    OMX_TUNNELSETUPTYPE* tunnelTSetup)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::useBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::useBuffer(OMX_BUFFERHEADERTYPE** header,
                OMX_U32 portIndex,
                OMX_PTR appPriv, 
                OMX_U32 size, 
                OMX_U8* buffer)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::allocateBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::allocateBuffer(OMX_BUFFERHEADERTYPE** buffer,
                OMX_U32 portIndex,
                OMX_PTR appPriv,
                OMX_U32 size)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::freeBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::freeBuffer(OMX_U32 portIndex, OMX_BUFFERHEADERTYPE* header)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::emptyThisBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::emptyThisBuffer(OMX_BUFFERHEADERTYPE* header)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}
                
/*
 **************************************************************************
 * FunctionName: OmxStateInterface::fillThisBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::fillThisBuffer(OMX_BUFFERHEADERTYPE* header)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::componentDeinit;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::componentDeinit()
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::componentRoleEnum;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::componentRoleEnum(OMX_U8* role, OMX_U32 index)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/*
 **************************************************************************
 * FunctionName: OmxStateInterface::sendCmd;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxStateInterface::sendCmd(OMX_COMMANDTYPE cmd, OMX_U32 para, OMX_PTR cmdData)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorInvalidState;
}

/********************************** END **********************************************/
