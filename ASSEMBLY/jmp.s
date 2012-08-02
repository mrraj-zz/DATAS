	.text
	.globl _start
_start:
	movl $1000, %eax
	movl $1000, %ebx
	cmpl %eax, %ebx
	je 50f
	movl $0x1, %eax
	int $0x80

50:
	addl %ebx, %eax
	movl $3000, %ecx
	addl %ecx, %eax
	movl $0x1, %eax
	int $0x80
