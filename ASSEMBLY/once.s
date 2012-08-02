	.text
	.globl _start
_start:
	movl $0x2, %eax
	xorl $0x2, %eax
	movl $0x1, %eax
	int $0x1
