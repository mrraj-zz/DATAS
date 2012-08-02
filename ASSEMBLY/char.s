	.text
	.globl _start
_start:
	movb $0x0A, %ah
	movb $0x68, %al
	int $0x10
