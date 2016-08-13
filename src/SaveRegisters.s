								PRESERVE8
                THUMB

; Global data
								AREA    MyData, DATA, READWRITE, ALIGN=2
								EXPORT  tcb_data
tcb_data				DCD			1
							
								AREA		MyCode, CODE, READONLY
saveRegs				PROC
								EXPORT	saveRegs
								IMPORT	tcbVal
								
								LDR			SP,=tcbVal
								LDR			SP, [SP]
								
								PUSH		{r0-r12}
								
								BX			LR
								ENDP
								
								END