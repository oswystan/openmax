/*
 **************************************************************************************
 *       Filename:  omx_component.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-12-01 17:30:53
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxComponent"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "omx_log.h"
#include "omx_component.h"
#include "omx_interface.h"

/*
 **************************************************************************
 * FunctionName: OmxComponent::OmxComponent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxComponent::OmxComponent ( OMX_HANDLETYPE* handle )
{
    /* init native component interface */
    nativeComponent.GetComponentVersion     = omxGetComponentVersion;
    nativeComponent.SendCommand             = omxSendCommand;
    nativeComponent.GetParameter            = omxGetParameter;
    nativeComponent.SetParameter            = omxSetParameter;
    nativeComponent.GetConfig               = omxGetConfig;
    nativeComponent.SetConfig               = omxSetConfig;
    nativeComponent.GetExtensionIndex       = omxGetExtensionIndex;
    nativeComponent.GetState                = omxGetState;
    nativeComponent.ComponentTunnelRequest  = omxComponentTunnelRequest;
    nativeComponent.UseBuffer               = omxUseBuffer;
    nativeComponent.AllocateBuffer          = omxAllocateBuffer;
    nativeComponent.FreeBuffer              = omxFreeBuffer;
    nativeComponent.EmptyThisBuffer         = omxEmptyThisBuffer;
    nativeComponent.FillThisBuffer          = omxFillThisBuffer;
    nativeComponent.SetCallbacks            = omxSetCallbacks;
    nativeComponent.ComponentDeInit         = omxComponentDeInit;
    nativeComponent.UseEGLImage             = omxUseEGLImage;
    nativeComponent.ComponentRoleEnum       = omxComponentRoleEnum;
    nativeComponent.pComponentPrivate       = this;
    nativeComponent.nSize                   = sizeof(nativeComponent);

    OMX_INIT_VERSION(nativeComponent.nVersion, 1, 0, 0, 1);
    memset(componentName, 0x00, sizeof(componentName));

    *handle = &nativeComponent;
}
OmxComponent::~OmxComponent ( void )
{
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::setCallbacks;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::setCallbacks ( OMX_PTR appData, OMX_CALLBACKTYPE* callback )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    nativeComponent.pApplicationPrivate = appData;
    nativeCallbacks = *callback;
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::getVersion;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::getVersion ( OMX_STRING compName,
                                         OMX_VERSIONTYPE* compVersion,
                                         OMX_VERSIONTYPE* specVersion, 
                                         OMX_UUIDTYPE* uuid)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    if(compName)
    {
        snprintf(compName, OMX_MAX_STRINGNAME_SIZE, "%s", componentName);
    }
    if(compVersion)
    {
        *compVersion = nativeComponent.nVersion;
    }
    if(specVersion)
    {
        OMX_INIT_VERSION(*specVersion, 1, 1, 2, 1);
    }
    if(uuid)
    {
        OMX_U32 _uuid[2];
        _uuid[0] = (OMX_U32)this;
        _uuid[1] = getpid();
        memset(uuid, 0x00, sizeof(OMX_UUIDTYPE));
        memcpy(uuid, uuid, sizeof(_uuid));
    }
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::getParameter;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::getParameter ( OMX_INDEXTYPE index, OMX_PTR para )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}
OMX_ERRORTYPE OmxComponent::setParameter ( OMX_INDEXTYPE index, OMX_PTR para )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::getConfig;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::getConfig ( OMX_INDEXTYPE index, OMX_PTR config )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}
OMX_ERRORTYPE OmxComponent::setConfig ( OMX_INDEXTYPE index, OMX_PTR config )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::getState;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::getState ( OMX_STATETYPE* state )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::getExtensionIndex;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::getExtensionIndex(OMX_STRING paraName, OMX_INDEXTYPE* indexType)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::componentTunnelRequest;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::componentTunnelRequest(OMX_U32 port,
                    OMX_HANDLETYPE tunnelComp,
                    OMX_U32 tunnelPort,
                    OMX_TUNNELSETUPTYPE* tunnelTSetup)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::useBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::useBuffer(OMX_BUFFERHEADERTYPE** header,
                OMX_U32 portIndex,
                OMX_PTR appPriv, 
                OMX_U32 size, 
                OMX_U8* buffer)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::allocateBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::allocateBuffer(OMX_BUFFERHEADERTYPE** buffer,
                OMX_U32 portIndex,
                OMX_PTR appPriv,
                OMX_U32 size)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::freeBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::freeBuffer(OMX_U32 portIndex, OMX_BUFFERHEADERTYPE* header)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::emptyThisBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::emptyThisBuffer(OMX_BUFFERHEADERTYPE* header)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}
                
/*
 **************************************************************************
 * FunctionName: OmxComponent::fillThisBuffer;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::fillThisBuffer(OMX_BUFFERHEADERTYPE* header)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::componentDeinit;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::componentDeinit()
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::componentRoleEnum;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::componentRoleEnum(OMX_U8* role, OMX_U32 index)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxComponent::sendCmd;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OmxComponent::sendCmd(OMX_COMMANDTYPE cmd, OMX_U32 para, OMX_PTR cmdData)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/********************************** END **********************************************/
