	.text
	.globl _start
_start:
	xor %ax, %ax
	int $0x12
	jc 1f
	test %ax, %ax
	jz 1f
1:	movl $0x1, %eax
	int $0x80
