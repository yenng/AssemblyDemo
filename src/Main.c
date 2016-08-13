/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "SaveRegisters.h"
#include "TCB.h"
#include "LinkList.h"
#include "PushRegister.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
extern LinkList *tcbList;

uint32_t variableInC = 0xdeaf;
uint32_t tcbVal;
uint32_t taskAdd;

void waitForever(void) {
	volatile int counter = 500000;
	while(counter--);
//	NVIC_DisableIRQ(SysTick_IRQn);
	disableSysTickInterrupt();
}

void task1(){
	while(1) {
	}
}
	
void task2(){
	while(1) {
	}
}

uint32_t taskSwitching(LinkList *list){
	Tcb *tcbFirst = removeFirstList(list);
	addLinkList(list,tcbFirst);
	return (list->head->sp);
}

int main() {
	//pushRegs((uint32_t)*main);
	
	fourBytes = 0xdeadbeef;
	noArgFunc();
	initMain(main);
	tcbVal = task1Tcb.sp;
	saveRegs(tcbVal);
	
	initTcb1(task1);
	initTcb2(task2);
	
	addLinkList(tcbList,&taskMain);
	addLinkList(tcbList,&task1Tcb);
	addLinkList(tcbList,&task2Tcb);
	
	initSysTick();
  //waitForever();

	while(1) {
	}

	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;
}
