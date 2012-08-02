	.text
	.globl _start
_string:	.ascii "This is a string\0"
_main:
	pushl $_string
	call _printString
	addl $4, %esp
	ret
_printString:
	pushl %ebp
	movl %esp, %ebp
	pushl 8(%ebp)
	call _printf
	addl $4, %esp
	leave
	ret
