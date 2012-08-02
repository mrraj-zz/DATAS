	.text
	.globl _start
_start:
	movl $100, %ebx
	movl $200, %ecx
	addl %ecx, %ebx
