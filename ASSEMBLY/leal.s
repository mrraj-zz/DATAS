	.text
	.globl _start
_start:
	leal (%esp), %eax
	movl $0x1, %eax
	int $0x80
