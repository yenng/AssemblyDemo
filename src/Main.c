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

void task1();
void task2();


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

int main() {	
	fourBytes = 0xdeadbeef;
	noArgFunc();
	initMain();
	initLinkList();
	tcbVal = taskMain.sp;
	saveRegs(tcbVal);
	//pushRegs((uint32_t)*main);
	initTcb1();
	taskAdd = task1Tcb.sp;
	pushRegs((uint32_t)*task1);
	initTcb2();
	taskAdd = task2Tcb.sp;
	pushRegs((uint32_t)*task2);
	
	addLinkList(&TcbList,&taskMain);
	addLinkList(&TcbList,&task1Tcb);
	addLinkList(&TcbList,&task2Tcb);
	
	initSysTick();
  //waitForever();

	while(1) {
	}

	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;
}
