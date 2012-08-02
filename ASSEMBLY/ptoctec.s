	.text
	.globl _start
_start:
	movw $0x0B800, %ax
	movw %ax, %es  
	movl $0x0076b076f, %es:0
	movl $0x1, %eax
	int $0x80

