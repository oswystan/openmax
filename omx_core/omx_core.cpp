/*
 **************************************************************************************
 *       Filename:  omx_core.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-29 19:16:38
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxCore"

#include <stdio.h>
#include <string.h>

#include "omx_log.h"
#include "omx_mutex.h"
#include "omx_loader.h"
#include "omx_libinterface.h"
#include "OMX_Core.h"

#define MAX_ROLES_NUM       16
#define MAX_COMPONENT_NUM   16
#define MAX_INSTANCES_NUM   32

struct OmxRolesTab
{
    int num;
    char roles[MAX_ROLES_NUM][OMX_MAX_STRINGNAME_SIZE];
};
struct OmxComponentsTab
{
    int num;
    char components[MAX_COMPONENT_NUM][OMX_MAX_STRINGNAME_SIZE];
    char libs[MAX_COMPONENT_NUM][OMX_MAX_STRINGNAME_SIZE];
};

struct OmxCoreData
{
    OmxCoreData()
    {
        reset();
    }
    void reset()
    {
        memset(this, 0x00, sizeof(*this));
    }

    char omxMap[MAX_ROLES_NUM][MAX_COMPONENT_NUM];
    OMX_HANDLETYPE   componentInstaces[MAX_INSTANCES_NUM];
    OmxComponentsTab tabComponents;
    OmxRolesTab      tabRoles;
    OmxMutex         mutex;
};

static OmxCoreData g_coreData;

static int getIndexOfKey(const char array[][OMX_MAX_STRINGNAME_SIZE], int count, const char* key)
{
    int ret  = -1;
    for(int i=0; i<count; i++)
    {
        if(strcmp(array[i], key) == 0)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

/*
 **************************************************************************
 * FunctionName: omxAddComponent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
static int omxAddComponent ( const char* component, const char* role, const char* lib )
{
    if(g_coreData.tabComponents.num >= MAX_COMPONENT_NUM ||
        g_coreData.tabRoles.num >= MAX_ROLES_NUM)
    {
        OMX_LOGE("too much components<%d> or roles<%d>", g_coreData.tabComponents.num, g_coreData.tabRoles.num);
        return OMX_ErrorInsufficientResources;
    }
    int ci = getIndexOfKey(g_coreData.tabComponents.components, g_coreData.tabComponents.num, component);
    int ri = getIndexOfKey(g_coreData.tabRoles.roles, g_coreData.tabRoles.num, role);
    if(ci >= 0 && ri >= 0)
    {
        OMX_LOGW("component <%s> role <%s> has been add to omx core", component, role);
        return OMX_ErrorNone;
    }

    if(ci < 0)
    {
        OMX_LOGV("add new component <%s>", component);
        ci = g_coreData.tabComponents.num;
        g_coreData.tabComponents.num++;
        snprintf(g_coreData.tabComponents.components[ci], OMX_MAX_STRINGNAME_SIZE, "%s", component);
        snprintf(g_coreData.tabComponents.libs[ci], OMX_MAX_STRINGNAME_SIZE, "%s", lib);
    }
    if(ri < 0)
    {
        OMX_LOGV("add new role <%s>", role);
        ri = g_coreData.tabRoles.num;
        g_coreData.tabRoles.num++;
        snprintf(g_coreData.tabRoles.roles[ri], OMX_MAX_STRINGNAME_SIZE, "%s", role);
    }

    g_coreData.omxMap[ri][ci] = 1;
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: omxAddNewInstance;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int omxAddNewInstance ( OMX_HANDLETYPE handle )
{
    int i = 0;
    for(; i<MAX_INSTANCES_NUM; i++)
    {
        if(NULL == g_coreData.componentInstaces[i])
        {
            g_coreData.componentInstaces[i] = handle;
            return OMX_ErrorNone;
        }
    }

    OMX_LOGE("too much component run in this process");
    return OMX_ErrorInsufficientResources;
}

/*
 **************************************************************************
 * FunctionName: omxRmInstance;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
void omxRmInstance ( OMX_HANDLETYPE handle )
{
    int i = 0;
    for(; i<MAX_INSTANCES_NUM; i++)
    {
        if(handle == g_coreData.componentInstaces[i])
        {
            g_coreData.componentInstaces[i] = NULL;
            return;
        }
    }
    
    OMX_LOGW("omx handle <%p> is not owned by this omx core", handle);
}

/*
 **************************************************************************
 * FunctionName: OMX_Init;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_Init ( void )
{
    OMX_LOGV("enter %s()", __FUNCTION__);

    OmxAutolock lock(g_coreData.mutex);
    omxAddComponent("OMX.cnc.video.decoder.avc",   "video_decoder.avc",   "libcnc_omxdecoder_avc.so");
    omxAddComponent("OMX.cnc.video.decoder.mpeg4", "video_decoder.mpeg4", "libcnc_omxdecoder_mpeg4.so");
    omxAddComponent("OMX.cnc.video.decoder.mpeg4", "video_decoder.h263",  "libcnc_omxdecoder_mpeg4.so");
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_Deinit;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_Deinit ( void )
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_ComponentNameEnum;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_ComponentNameEnum(
            OMX_STRING cComponentName,
            OMX_U32 nNameLength,
            OMX_U32 nIndex)
{
    OMX_LOGV("enter %s()", __FUNCTION__);

    OmxAutolock lock(g_coreData.mutex);

    if(nIndex >= g_coreData.tabComponents.num)
    {
        return OMX_ErrorNoMore;
    }
    
    snprintf(cComponentName, nNameLength, "%s", g_coreData.tabComponents.components[nIndex]);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_GetHandle;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_GetHandle(
            OMX_HANDLETYPE* pHandle,
            OMX_STRING cComponentName,
            OMX_PTR pAppData,
            OMX_CALLBACKTYPE* pCallBacks)
{
    OMX_LOGV("enter %s()", __FUNCTION__);

    OmxAutolock lock(g_coreData.mutex);

    int ret = 0;
    
    int ci = getIndexOfKey(g_coreData.tabComponents.components, g_coreData.tabComponents.num, cComponentName);
    if(ci < 0)
    {
        OMX_LOGE("invalid component name <%s>", cComponentName);
        return OMX_ErrorComponentNotFound;
    }

    OmxLoader* loader = new OmxLoader;
    if(!loader)
    {
        OMX_LOGE("allocate memory for loader failed");
        return OMX_ErrorInsufficientResources;
    }
    ret  = loader->loadIt(g_coreData.tabComponents.libs[ci]);
    if(ret < 0)
    {
        return OMX_ErrorComponentNotFound;
    }

    OmxLibInterface* libInterface = (OmxLibInterface*)loader->queryInterface(OMX_LIB_INTERFACE_ID);
    if(!libInterface)
    {
        return OMX_ErrorComponentNotFound;
    }

    ret = libInterface->createComponent(pHandle, cComponentName, pAppData, pCallBacks);
    if(ret != OMX_ErrorNone || !pHandle)
    {
        return OMX_ErrorComponentNotFound;
    }

    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_FreeHandle;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_FreeHandle(OMX_HANDLETYPE hComponent)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_GetComponentsOfRole;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_GetComponentsOfRole (
        OMX_STRING role,
        OMX_U32 *pNumComps,
        OMX_U8  **compNames)
{
    OMX_LOGV("enter %s()", __FUNCTION__);

    OmxAutolock lock(g_coreData.mutex);
    
    int ri = getIndexOfKey(g_coreData.tabRoles.roles, g_coreData.tabRoles.num, role);
    if(ri < 0)
    {
        OMX_LOGW("no role <%s> in omx", role);
        *pNumComps = 0;
        return OMX_ErrorNoMore;
    }

    int totalCount = 0;

    for(int i=0; i<g_coreData.tabComponents.num; i++)
    {
        if(g_coreData.omxMap[ri][i] != 0)
        {
            if(NULL != compNames)
            {
                sprintf((char*)(compNames[totalCount]), "%s", g_coreData.tabComponents.components[i]);
            }
            totalCount++;
        }
    }

    *pNumComps = totalCount;
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_GetRolesOfComponent;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_GetRolesOfComponent (
        OMX_STRING compName,
        OMX_U32 *pNumRoles,
        OMX_U8 **roles)
{
    OMX_LOGV("enter %s()", __FUNCTION__);

    OmxAutolock lock(g_coreData.mutex);
    
    int ci = getIndexOfKey(g_coreData.tabComponents.components, g_coreData.tabComponents.num, compName);
    if(ci < 0)
    {
        OMX_LOGE("can not found component <%s>", compName);
        *pNumRoles = 0;
        return OMX_ErrorNone;
    }

    int totalCount = 0;
    for(int i=0; i<g_coreData.tabRoles.num; i++)
    {
        if(g_coreData.omxMap[i][ci] != 0)
        {
            if(NULL != roles)
            {
                sprintf((char*)(roles[totalCount]), "%s", g_coreData.tabRoles.roles[i]);
            }
            totalCount++;
        }
    }

    *pNumRoles = totalCount;
    return OMX_ErrorNone;
}

/*
 **************************************************************************
 * FunctionName: OMX_SetupTunnel;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_SetupTunnel(
        OMX_HANDLETYPE hOutput,
        OMX_U32 nPortOutput,
        OMX_HANDLETYPE hInput,
        OMX_U32 nPortInput)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNotImplemented;
}

/*
 **************************************************************************
 * FunctionName: OMX_GetContentPipe;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OMX_ERRORTYPE OMX_GetContentPipe(
        OMX_HANDLETYPE *hPipe,
        OMX_STRING szURI)
{
    OMX_LOGV("enter %s()", __FUNCTION__);
    return OMX_ErrorNotImplemented;
}

/********************************** END **********************************************/

