/*
 **************************************************************************************
 *       Filename:  omx_interface.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-12-01 21:36:20
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "omx_interface"

#include <stdio.h>
#include "omx_log.h"
#include "omx_interface.h"
#include "omx_component.h"


OMX_ERRORTYPE omxGetComponentVersion(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_OUT OMX_STRING pComponentName,
        OMX_OUT OMX_VERSIONTYPE* pComponentVersion,
        OMX_OUT OMX_VERSIONTYPE* pSpecVersion,
        OMX_OUT OMX_UUIDTYPE* pComponentUUID)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->getVersion(pComponentName, pComponentVersion, pSpecVersion, pComponentUUID);
}

OMX_ERRORTYPE omxSendCommand(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_COMMANDTYPE Cmd,
        OMX_IN  OMX_U32 nParam1,
        OMX_IN  OMX_PTR pCmdData)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->sendCmd(Cmd, nParam1, pCmdData);
}


OMX_ERRORTYPE omxGetParameter(
        OMX_IN  OMX_HANDLETYPE hComponent, 
        OMX_IN  OMX_INDEXTYPE nParamIndex,  
        OMX_INOUT OMX_PTR pComponentParameterStructure)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->getParameter(nParamIndex, pComponentParameterStructure);
}

OMX_ERRORTYPE omxSetParameter(
        OMX_IN  OMX_HANDLETYPE hComponent, 
        OMX_IN  OMX_INDEXTYPE nIndex,
        OMX_IN  OMX_PTR pComponentParameterStructure)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->setParameter(nIndex, pComponentParameterStructure);
}


OMX_ERRORTYPE omxGetConfig(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_INDEXTYPE nIndex, 
        OMX_INOUT OMX_PTR pComponentConfigStructure)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->getConfig(nIndex, pComponentConfigStructure);
}

OMX_ERRORTYPE omxSetConfig(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_INDEXTYPE nIndex, 
        OMX_IN  OMX_PTR pComponentConfigStructure)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->setConfig(nIndex, pComponentConfigStructure);
}

OMX_ERRORTYPE omxGetExtensionIndex(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_STRING cParameterName,
        OMX_OUT OMX_INDEXTYPE* pIndexType)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->getExtensionIndex(cParameterName, pIndexType);
}

OMX_ERRORTYPE omxGetState(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_OUT OMX_STATETYPE* pState)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->getState(pState);
}

OMX_ERRORTYPE omxComponentTunnelRequest(
    OMX_IN  OMX_HANDLETYPE hComponent,
    OMX_IN  OMX_U32 nPort,
    OMX_IN  OMX_HANDLETYPE hTunneledComp,
    OMX_IN  OMX_U32 nTunneledPort,
    OMX_INOUT  OMX_TUNNELSETUPTYPE* pTunnelSetup)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->componentTunnelRequest(nPort, hTunneledComp, nTunneledPort, pTunnelSetup);
}

OMX_ERRORTYPE omxUseBuffer(
        OMX_IN OMX_HANDLETYPE hComponent,
        OMX_INOUT OMX_BUFFERHEADERTYPE** ppBufferHdr,
        OMX_IN OMX_U32 nPortIndex,
        OMX_IN OMX_PTR pAppPrivate,
        OMX_IN OMX_U32 nSizeBytes,
        OMX_IN OMX_U8* pBuffer)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->useBuffer(ppBufferHdr, nPortIndex, pAppPrivate, nSizeBytes, pBuffer);
}

OMX_ERRORTYPE omxAllocateBuffer(
        OMX_IN OMX_HANDLETYPE hComponent,
        OMX_INOUT OMX_BUFFERHEADERTYPE** ppBuffer,
        OMX_IN OMX_U32 nPortIndex,
        OMX_IN OMX_PTR pAppPrivate,
        OMX_IN OMX_U32 nSizeBytes)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->allocateBuffer(ppBuffer, nPortIndex, pAppPrivate, nSizeBytes);
}

OMX_ERRORTYPE omxFreeBuffer(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_U32 nPortIndex,
        OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->freeBuffer(nPortIndex, pBuffer);
}

OMX_ERRORTYPE omxEmptyThisBuffer(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->emptyThisBuffer(pBuffer);
}

OMX_ERRORTYPE omxFillThisBuffer(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->fillThisBuffer(pBuffer);
}

OMX_ERRORTYPE omxSetCallbacks(
        OMX_IN  OMX_HANDLETYPE hComponent,
        OMX_IN  OMX_CALLBACKTYPE* pCallbacks, 
        OMX_IN  OMX_PTR pAppData)
{
    OMX_LOGV("enter %s()", __FUNCTION__);

    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->setCallbacks(pAppData, pCallbacks);
}

OMX_ERRORTYPE omxComponentDeInit(
        OMX_IN  OMX_HANDLETYPE hComponent)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->componentDeinit();
}

OMX_ERRORTYPE omxUseEGLImage(
        OMX_IN OMX_HANDLETYPE hComponent,
        OMX_INOUT OMX_BUFFERHEADERTYPE** ppBufferHdr,
        OMX_IN OMX_U32 nPortIndex,
        OMX_IN OMX_PTR pAppPrivate,
        OMX_IN void* eglImage)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
}

OMX_ERRORTYPE omxComponentRoleEnum(
    OMX_IN OMX_HANDLETYPE hComponent,
    OMX_OUT OMX_U8 *cRole,
    OMX_IN OMX_U32 nIndex)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    OMX_COMPONENTTYPE* comp = (OMX_COMPONENTTYPE*)hComponent;
    OmxComponent* vendorComp = (OmxComponent*)comp->pComponentPrivate;
    vendorComp->componentRoleEnum(cRole, nIndex);
}

/********************************** END **********************************************/
