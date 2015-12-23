/*
 **************************************************************************************
 *       Filename:  omx_loader.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 00:19:10
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxLoader"

#include <string.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdio.h>

#include "omx_log.h"
#include "omx_loader.h"

/*
 **************************************************************************
 * FunctionName: OmxLoader::OmxLoader;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxLoader::OmxLoader ( void )
{
    handle = NULL;
    memset(libName, 0x00, sizeof(libName));
}
OmxLoader::~OmxLoader ( void )
{
    unloadIt();
}

/*
 **************************************************************************
 * FunctionName: OmxLoader::loadIt;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxLoader::loadIt ( const char* name )
{
    if(handle)
    {
        unloadIt();
    }

    handle = dlopen(name, RTLD_LAZY);
    if(!handle)
    {
        OMX_LOGE("fail to load <%s><%s>", name, dlerror());
        return -1;
    }
    snprintf(libName, sizeof(libName), "%s", name);
    OMX_LOGD("load <%s> OK", name);

    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxLoader::unloadIt;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxLoader::unloadIt ( void )
{
    if(handle)
    {
        OMX_LOGD("unload <%s>", libName);
        dlclose(handle);
        handle = NULL;
        memset(libName, 0x00, sizeof(libName));
    }

    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxLoader::queryInterface;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
void* OmxLoader::queryInterface ( unsigned int interfaceId )
{
    if(!handle)
    {
        OMX_LOGE("null handle while query interface");
        return NULL;
    }

    typedef void* (*FUNC_QUERY_INTERFACE)(unsigned interfaceId);
    FUNC_QUERY_INTERFACE func = (FUNC_QUERY_INTERFACE)dlsym(handle, "queryInterface");
    if(!func)
    {
        OMX_LOGE("fail to get interface <queryInterface> in <%s>", libName);
        return NULL;
    }

    void* ret = (*func)(interfaceId);
    return ret;
}

/********************************** END **********************************************/

