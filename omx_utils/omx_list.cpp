/*
 **************************************************************************************
 *       Filename:  omx_list.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2012-11-28 22:24:08
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#define LOG_TAG "OmxList"
#include <stdio.h>

#include "omx_log.h"
#include "omx_list.h"


/*
 **************************************************************************
 * FunctionName: OmxList::OmxList;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxList::OmxList ( void )
{
    head       = NULL;
    totalCount = 0;
}

/*
 **************************************************************************
 * FunctionName: OmxList::~OmxList;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
OmxList::~OmxList ( void )
{
    clearAll();
}

/*
 **************************************************************************
 * FunctionName: OmxList::pushBack;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxList::pushBack ( void* data )
{
    OmxAutolock lock(mutex);

    OmxListNode* node = new OmxListNode;
    if(!node)
    {
        OMX_LOGE("no memory for OmxListNode");
        return -1;
    }
    node->data = data;
    if(!head)
    {
        head = node;
    }
    else
    {
        OmxListNode* tmp = head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = node;
        node->prev = tmp;
    }

    totalCount++;
    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxList::pushFront;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxList::pushFront ( void* data )
{
    OmxAutolock lock(mutex);
    OmxListNode* node = new OmxListNode;
    if(!node)
    {
        OMX_LOGE("no memory for OmxListNode");
        return -1;
    }
    node->data = data;

    if(head)
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
    else
    {
        head = node;
    }

    ++totalCount;
    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxList::clearAll;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
void OmxList::clearAll ( void )
{
    OmxAutolock lock(mutex);
    OmxListNode* tmp = head;
    OmxListNode* node;
    while(tmp)
    {
        node = tmp;
        tmp = tmp->next;
        delete node;
    }
    head = NULL;
    totalCount = 0;
}

/*
 **************************************************************************
 * FunctionName: OmxList::eraseNode;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
int OmxList::eraseNode ( void* data )
{
    OmxAutolock lock(mutex);
    OmxListNode* tmp = head;
    while(tmp)
    {
        if(data == tmp->data)
        {
            break;
        }
        tmp = tmp->next;
    }

    if(!tmp)
    {
        OMX_LOGE("can not found data <%p>", data);
        return -1;
    }

    /* find it */
    OmxListNode* prevOne = tmp->prev;
    OmxListNode* nextOne = tmp->next;
    if(prevOne)
    {
        prevOne->next = nextOne;
        if(nextOne)
        {
            nextOne->prev = prevOne;
        }
        delete tmp;
    }
    else
    {
        head = nextOne;
        if(nextOne)
        {
            nextOne->prev = NULL;
        }
    }

    --totalCount;
    return 0;
}

/*
 **************************************************************************
 * FunctionName: OmxList::dump;
 * Description : NA;
 * Input       : NA;
 * Output      : NA;
 * ReturnValue : NA;
 * Other       : NA;
 **************************************************************************
 */
void OmxList::dump ( void )
{
    OmxAutolock lock(mutex);
    OmxListNode* tmp = head;
    int i = 0;
    
    OMX_LOGD("total list node=%d, data as follows:", totalCount);
    OMX_LOGD("===============================");
    while(tmp)
    {
        OMX_LOGD("list[%d]=%p", i, tmp->data);
        tmp = tmp->next;
        i++;
    }
}

/********************************** END **********************************************/

