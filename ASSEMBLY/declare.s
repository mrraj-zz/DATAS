	.text
	.global _start
_start:
	movl $0x100, %eax
	movl $0x200, %ebx
	addl %ebx, %eax
	
