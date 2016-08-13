 #include "LinkList.h"
 #include "TCB.h"
 #include <stdlib.h>
 
 LinkList TcbList;
 
 void initLinkList(){
	 TcbList.head = NULL;
	 TcbList.tail = NULL;
	 TcbList.length = 0;
 }
 
void addLinkList(LinkList *list, Tcb *tcb1){
	if(tcb1 == NULL){
		list = list;
	}
	else{
		if (list->head == NULL)
			list->head = tcb1;
		else{
			Tcb *tcb_t = list->head;
			while(tcb_t->nextTcb!=NULL)
				tcb_t = tcb_t->nextTcb;
			tcb_t->nextTcb=tcb1;
		}
	}
	list->tail = tcb1;
	list->length++;
}

Tcb *removeFirstList(LinkList *list){
	Tcb *tcbFirst;
	if(list->head==NULL)
		tcbFirst = NULL;
	else{
		tcbFirst = list->head;
		tcbFirst->nextTcb = NULL;
		list->length--;
		if(list->tail==list->head){
			list->head = NULL;
			list->tail = NULL;
		}
		else
			list->head = list->head->nextTcb;
	}
	return tcbFirst;
}