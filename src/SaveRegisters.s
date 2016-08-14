								PRESERVE8
                THUMB

; Global data
								AREA    MyData, DATA, READWRITE, ALIGN=2
								EXPORT  tcb_data
tcb_data				DCD			1
mainSp					DCD			1
							
								AREA		MyCode, CODE, READONLY
saveRegs				PROC
								EXPORT	saveRegs
								IMPORT	tcbVal
								
								LDR			R10,=mainSp
								STR			R13,[R10]
								LDR			SP,=tcbVal
								LDR			SP, [SP]
								
								PUSH		{r0-r12}
								
								LDR			R13,=mainSp
								LDR			R13,[R13]
								BX			LR
								ENDP
								
								END