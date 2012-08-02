	.text
	.globl intcall
	.type intcall, @function
intcall:
	movl $100, %eax
	retl
