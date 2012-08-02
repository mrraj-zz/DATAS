	.data
a:	.long 100
b:	.long 200
c:	.long 0

	.text
	.global _start
_start:
	movl a, %eax
	movl b, %ebx
	addl %ebx, %eax
	movl $c, %ebp
	movl %eax, (%ebp)

	movl $4, %eax
	movl $1, %ebx
	movl $c, %ecx
	movl $1, %edx
	int $0x80

	movl $1, %eax
	int $0x80
