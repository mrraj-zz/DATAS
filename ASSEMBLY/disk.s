	.text
	.globl _start
_start:
	movb $0x8, %ah
	movb $0x80, %dl
	int $0x13

	movl $1, %eax
	int $0x80
