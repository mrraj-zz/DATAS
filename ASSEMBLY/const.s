BOOT	= 0x07c0
boot:	.long 0x07c0
	.text
	.globl _start
_start:
	movl $BOOT, %eax
	movl $boot, %ebx
	
	movl $0x1, %eax
	int $0x80
