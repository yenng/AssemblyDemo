#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

 #include "TCB.h"

typedef struct{
	Tcb* head;
	Tcb* tail;
	int length;
}LinkList;
extern LinkList TcbList;


void initLinkList();
void addLinkList(LinkList *list, Tcb *tcb1);
uint32_t taskSwitching(LinkList *list);
Tcb *removeFirstList(LinkList *list);
#endif	// __LINK_LIST_H__
