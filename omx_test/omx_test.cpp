/*
 **************************************************************************************
 *       Filename:  main.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-26 23:13:38
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LOG_TAG "main"

#include "omx_mutex.h"
#include "omx_sem.h"
#include "omx_log.h"
#include "omx_loader.h"
#include "omx_thread.h"
#include "omx_list.h"
#include "OMX_Core.h"
#include "OMX_Component.h"

void omx_core_test()
{
    OMX_U32 totalCount = 0;
    OMX_STRING component = (OMX_STRING)"OMX.cnc.video.decoder.mpeg4";
    OMX_U8* roles[2];
    roles[0] = (OMX_U8*)new OMX_U8[128];
    roles[1] = (OMX_U8*)new OMX_U8[128];

    OMX_LOGV("=================================");
    OMX_LOGV("omx test OMX_GetRolesOfComponent<%s>:", component);
    OMX_GetRolesOfComponent(component, &totalCount, roles);
    for(int i=0; i<totalCount; i++)
    {
        OMX_LOGI("roles[%d]=%s", i, roles[i]);
    }
    OMX_LOGI("totalCount = %u", (unsigned int)totalCount);

    OMX_STRING role = (OMX_STRING)"video_decoder.avc";
    OMX_LOGV("=================================");
    OMX_LOGV("omx test OMX_GetComponentsOfRole<%s>", role);
    OMX_U8* comp[2];
    comp[0] = (OMX_U8*)new OMX_U8[128];
    comp[1] = (OMX_U8*)new OMX_U8[128];
    OMX_GetComponentsOfRole(role, &totalCount, comp);
    for(int j=0; j<totalCount; j++)
    {
        OMX_LOGI("comp[%d]=%s", j, comp[j]);
    }
    OMX_LOGI("totalCount = %u", (unsigned int)totalCount);
}

void omx_component_test()
{
    OMX_HANDLETYPE handle;
    OMX_CALLBACKTYPE callback;
    OMX_GetHandle(&handle, (OMX_STRING)"OMX.cnc.video.decoder.avc", NULL, &callback);
    char componentName[128];
    OMX_STRING cmpname = componentName;
    OMX_VERSIONTYPE compVersion;
    OMX_VERSIONTYPE specVersion;
    OMX_UUIDTYPE uuid;
    OMX_GetComponentVersion(handle, cmpname, &compVersion, &specVersion, &uuid);
}

int main()
{
    OMX_Init();

    /* run all cases here */
    //omx_core_test();
    omx_component_test();

    OMX_Deinit();
    return 0;
}

/********************************** END **********************************************/


