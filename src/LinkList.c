 #include "LinkList.h"
 #include "TCB.h"
 #include <stdlib.h>
 
 LinkList TcbList;
 
 void initLinkList(){
	 TcbList.head = NULL;
	 TcbList.tail = NULL;
	 TcbList.length = 0;
 }

uint32_t taskSwitching(LinkList *list, uint32_t currentSp){
	Tcb *tcbFirst = removeFirstList(list);
	tcbFirst->sp	= currentSp;
	addLinkList(list,tcbFirst);
	return (list->head->sp);
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
		list->length--;
		if(list->tail==list->head){
			list->head = NULL;
			list->tail = NULL;
		}
		else
			list->head = list->head->nextTcb;
	}
	tcbFirst->nextTcb = NULL;

	return tcbFirst;
}