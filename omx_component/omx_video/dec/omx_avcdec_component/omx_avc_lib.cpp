/*
 **************************************************************************************
 *       Filename:  omx_avc_lib.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-12-01 16:59:39
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include "omx_log.h"
#include "omx_libinterface.h"
#include "omx_component_avcdec.h"

#define CNC_OMX_AVCDECODER_NAME "OMX.cnc.video.decoder.avc"

class OmxAvcLibInterface : public OmxLibInterface
{
public:
    OmxAvcLibInterface()
    {
    }
    ~OmxAvcLibInterface()
    {
    }

    const char* enumComponent(int index);
    const char* enumRoles(int index, const char* component);
    int createComponent(OMX_HANDLETYPE* handle, OMX_STRING name, OMX_PTR appData, OMX_CALLBACKTYPE* callback);
    void destoryComonent(OMX_HANDLETYPE handle);
};

/*
 **************************************************************************
 * FunctionName: OmxAvcLibInterface::enumComponent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
const char* OmxAvcLibInterface::enumComponent ( int index )
{
    const char* ret = NULL;
    if(0 == index)
    {
        ret = CNC_OMX_AVCDECODER_NAME;
    }
    return ret;
}

/*
 **************************************************************************
 * FunctionName: OmxAvcLibInterface::enumRoles;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
const char* OmxAvcLibInterface::enumRoles ( int index, const char* component )
{
    const char* ret = NULL;
    if(0 == index && 0 == strcmp(component, CNC_OMX_AVCDECODER_NAME))
    {
        ret = "video_decoder.avc";
    }
    return ret;
}

/*
 **************************************************************************
 * FunctionName: OmxAvcLibInterface::createComponent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxAvcLibInterface::createComponent ( OMX_HANDLETYPE* handle, OMX_STRING name, OMX_PTR appData, OMX_CALLBACKTYPE* callback )
{
    OmxComponent* comp = new OmxAvcDecComponent(handle);
    if(!comp)
    {
        OMX_LOGE("fail to allocate memory for avc decoder");
        return OMX_ErrorInsufficientResources;
    }

    comp->setCallbacks(appData, callback);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OmxAvcLibInterface::destoryComonent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
void OmxAvcLibInterface::destoryComonent ( OMX_HANDLETYPE handle )
{
    return;
}

extern "C"
{

static OmxAvcLibInterface g_avcLib;
void* queryInterface(unsigned int interfaceId)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return &g_avcLib;
}

};
/********************************** END **********************************************/
