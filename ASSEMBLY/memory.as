	XOR CX, CX
	XOR DX, DX
	MOV AX, 0xE801
	INT 0x15		; request upper memory size
	JC SHORT .ERR
	CMP AH, 0x86		; unsupported function
	JE SHORT .ERR
	CMP AH, 0x80		; invalid command
	JE SHORT .ERR
	JCXZ .USEAX		; was the CX result invalid?
 
	MOV AX, CX
	MOV BX, DX
.USEAX:
	; AX = number of contiguous Kb, 1M to 16M
	; BX = contiguous 64Kb pages above 16M
