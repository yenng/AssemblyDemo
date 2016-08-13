#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

 #include "TCB.h"

typedef struct{
	Tcb* head;
	Tcb* tail;
	int length;
}LinkList;

void initLinkList();
void addLinkList(LinkList *list, Tcb *tcb1);
Tcb *removeFirstList(LinkList *list);
#endif	// __LINK_LIST_H__
