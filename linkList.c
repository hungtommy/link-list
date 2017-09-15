#include "linkList.h"
#include "stdint.h"

// initialize node
void nodeInit(listNode * node)
{
	node->list = (linkList *)0;
	
	node->preNode = node;
	node->nextNode = node;
}

// check if the node is already linked
uint8_t isLinkNode(listNode * node)
{
	if (node->list != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t isOnList(linkList * list, listNode * node)
{
	if (node->list == list)
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}

#define firstNode headNode.nextNode
#define lastNode headNode.preNode

void listInit(linkList * list)
{	
	// list address is zero for list object
	nodeInit(&(list->headNode));
	
	list->nodeCount = 0;	
}

// obtain the number of node linked within the list
uint32_t listCount(linkList * list)
{
	return list->nodeCount;
}

// return first node without remove the node from list
listNode * listFirstNode(linkList * list)
{
	listNode * node = (listNode *)0;
	
	if (list->nodeCount > 0)
	{
		node = list->firstNode;
	}
	
	return node;
}

//return last node without remove the node from list
listNode * listLastNode(linkList * list)
{
	listNode * node = (listNode *)0;
	
	if (list->nodeCount > 0)
	{
		node = list->lastNode;
	}
	
	return node;
}

// obtain the previous node of the node without remove from list
listNode * nodePreNode(listNode * node)
{
	if (isLinkNode(node))
	{
		return node->preNode;		
	}
	else
	{
		return (listNode *)0;		
	}
}

// obtain the next node of the node without remove from list
listNode * nodeNextNode(listNode * node)
{
	if (isLinkNode(node))
	{
		return node->nextNode;		
	}
	else
	{
		return (listNode *)0;		
	}
}

void listRemoveAll (linkList * list)
{
	uint32_t count;
	listNode * nextNode;
	listNode * currentNode;
	
	nextNode = list->firstNode;
	
	for (count = 0; count < list->nodeCount; count++)
	{
		currentNode = nextNode;
		nextNode = currentNode->nextNode;
		
		// reset link node
		nodeInit(currentNode);
	}
	
	// reset link list
	listInit(list);
}

listStatus listAdd2First (linkList * list, listNode * node)
{
	if (isLinkNode(node))
	{
		return LINK_LIST_FAILURE;
	}
	else
	{
		node->list = list;
		node->preNode = &(list->headNode);
		node->nextNode =  list->firstNode;
	
		list->firstNode->preNode = node;
		list->firstNode = node;	
	
		list->nodeCount++;		
		
		return LINK_LIST_SUCCESS;
	}
}

listStatus listAdd2Last (linkList * list, listNode * node)
{
	if (isLinkNode(node))
	{
		return LINK_LIST_FAILURE;
	}
	else
	{
		node->list = list;
		node->nextNode = &(list->headNode);
		node->preNode = list->lastNode;
		
		list->lastNode->nextNode = node;
		list->lastNode = node;
		
		list->nodeCount++;
		
		return LINK_LIST_SUCCESS;
	}	
}

listNode * listRemoveFirst (linkList * list)
{
	listNode * node = (listNode *)0;
	
	if (list->nodeCount > 0)
	{
		node = list->firstNode;
		
		//remove node
		list->firstNode = node->nextNode;
		list->firstNode->preNode = &(list->headNode);
				
		//clear node
		nodeInit(node);		
		
		list->nodeCount--;
	}
	
	return node;
}

listStatus listInsertAfter(listNode * refNode, listNode * node)
{
	if (isLinkNode(refNode))
	{		
		node->preNode = refNode;
		node->nextNode = refNode->nextNode;
			
		refNode->nextNode->preNode = node;
		refNode->nextNode = node;
			
		refNode->list->nodeCount++;
		
		return LINK_LIST_SUCCESS;
	}
	else
	{				
		return LINK_LIST_FAILURE;
	}
}

listStatus listRemoveNode(listNode * node)
{
	if (isLinkNode(node))
	{
		node->preNode->nextNode = node->nextNode;
		node->nextNode->preNode = node->preNode;
		node->list->nodeCount--;
		
		nodeInit(node);
		
		return LINK_LIST_SUCCESS;
	}
	else
	{
		return LINK_LIST_FAILURE;
	}
}


