	.text
	.globl _start
_start:
	movl $0xe820, %eax
	pushfl
	popl %ebx
	int $0x15

	movl $0x1, %eax
	int $0x80
