#ifndef __LINK_LIST_H
#define __LINK_LIST_H

#include "stdint.h"

typedef struct _linkList linkList;

typedef struct _listNode{
	linkList * list;
	
	struct _listNode *preNode;
	struct _listNode *nextNode;
}listNode;

struct _linkList{
	listNode headNode;
	uint32_t nodeCount;
};

typedef enum {
	LINK_LIST_SUCCESS,
	LINK_LIST_FAILURE
}listStatus;

typedef struct{
	uint8_t var1;
	uint16_t var2;
	uint32_t var3;
	listNode node;	
}parent;

#define findParentAddress(actualMemberAddress, parent, varName) (parent *)( (uint32_t)actualMemberAddress - (uint32_t)&((parent *)0)->varName)



#endif
