/*
 **************************************************************************************
 *       Filename:  omx_list.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-28 00:18:18
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_LIST_H_INCLUDED
#define OMX_LIST_H_INCLUDED

#include "omx_mutex.h"

struct OmxListNode
{
    OmxListNode()
    {
        data = NULL;
        prev = NULL;
        next = NULL;
    }
    void* data;
    OmxListNode* prev;
    OmxListNode* next;
};
typedef OmxListNode* OmxListHead;

class OmxList
{
public:
    OmxList();
    ~OmxList();

    int getCount() 
    {
        return totalCount;
    }
    OmxListNode* getHead()
    {
        return head;
    }

    int pushBack(void* data);
    int pushFront(void* data);
    int eraseNode(void* data);
    void clearAll();

    void dump();

private:
    OmxListHead head;
    OmxMutex    mutex;
    int totalCount;
};

#endif /*OMX_LIST_H_INCLUDED*/

/********************************* END ***********************************************/

