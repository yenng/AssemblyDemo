								PRESERVE8
								THUMB
									
; GLOBAL DATA
								AREA		MyData, DATA, READWRITE, ALIGN=2
								EXPORT	x
x								DCD			1
mainSp					DCD			1
	
								AREA		MyCoDE, CODE, READONLY
pushRegs				PROC
								EXPORT	pushRegs
								IMPORT	taskAdd
								
								LDR			R10,=mainSp
								STR			R13,[R10]
								
								LDR			R1,=x
								STR			R0,[R1]
								LDR			R1,[R1]
								LDR			R2,=0X01000000
								PUSH		{R0-R2}
								PUSH		{R12}
								PUSH		{R0-R3}
								
								LDR			R13,=mainSp
								LDR			R13,[R13]
								
								BX			LR
								ENDP
								END