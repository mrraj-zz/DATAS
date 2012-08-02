	.text
	.globl _start
_start:
	movb $0x01, %al
	and $~0x1, %al
	movl $0x1, %eax
	int $0x80
