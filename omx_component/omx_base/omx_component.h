/*
 **************************************************************************************
 *       Filename:  omx_component.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-29 22:36:20
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_COMPONENT_H_INCLUDED
#define OMX_COMPONENT_H_INCLUDED

#include "OMX_Component.h"
#include "omx_thread.h"
#include "omx_list.h"

#define OMX_INIT_VERSION(ver, major, minor, rev, step) \
    do\
    {\
        (ver).s.nVersionMajor = major;\
        (ver).s.nVersionMinor = minor;\
        (ver).s.nRevision     = rev;\
        (ver).s.nStep         = step;\
    }\
    while(0)

class OmxComponent
{
public:
    OmxComponent(OMX_HANDLETYPE* handle);
    virtual ~OmxComponent();

    OMX_ERRORTYPE setCallbacks(OMX_PTR appData, OMX_CALLBACKTYPE* callback);

    OMX_ERRORTYPE getVersion(OMX_STRING compName, 
                    OMX_VERSIONTYPE* compVersion, 
                    OMX_VERSIONTYPE* specVersion, 
                    OMX_UUIDTYPE* uuid);

    virtual OMX_ERRORTYPE getParameter(OMX_INDEXTYPE index, OMX_PTR para);

    virtual OMX_ERRORTYPE setParameter(OMX_INDEXTYPE index, OMX_PTR para);

    virtual OMX_ERRORTYPE getConfig(OMX_INDEXTYPE index, OMX_PTR config);

    virtual OMX_ERRORTYPE setConfig(OMX_INDEXTYPE index, OMX_PTR config);

    virtual OMX_ERRORTYPE getState(OMX_STATETYPE* state);

    virtual OMX_ERRORTYPE getExtensionIndex(OMX_STRING paraName, OMX_INDEXTYPE* indexType);

    virtual OMX_ERRORTYPE componentTunnelRequest(OMX_U32 port, 
                    OMX_HANDLETYPE tunnelComp, 
                    OMX_U32 tunnelPort, 
                    OMX_TUNNELSETUPTYPE* tunnelTSetup);

    virtual OMX_ERRORTYPE useBuffer(OMX_BUFFERHEADERTYPE** header, 
                    OMX_U32 portIndex, 
                    OMX_PTR appPriv, 
                    OMX_U32 size, 
                    OMX_U8* buffer);

    virtual OMX_ERRORTYPE allocateBuffer(OMX_BUFFERHEADERTYPE** buffer,
                    OMX_U32 portIndex,
                    OMX_PTR appPriv,
                    OMX_U32 size);

    virtual OMX_ERRORTYPE freeBuffer(OMX_U32 portIndex, OMX_BUFFERHEADERTYPE* header);

    virtual OMX_ERRORTYPE emptyThisBuffer(OMX_BUFFERHEADERTYPE* header);

    virtual OMX_ERRORTYPE fillThisBuffer(OMX_BUFFERHEADERTYPE* header);

    virtual OMX_ERRORTYPE componentDeinit();

    virtual OMX_ERRORTYPE componentRoleEnum(OMX_U8* role, OMX_U32 index);

    OMX_ERRORTYPE sendCmd(OMX_COMMANDTYPE cmd, OMX_U32 para, OMX_PTR cmdData);

protected:
    OMX_COMPONENTTYPE nativeComponent;    
    OMX_CALLBACKTYPE  nativeCallbacks;
    OMX_STATETYPE     currentState;

    char              componentName[OMX_MAX_STRINGNAME_SIZE];
};

#endif /*OMX_COMPONENT_H_INCLUDED*/

/********************************* END ***********************************************/

