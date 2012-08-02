	.text
	.globl _start
_start:
	pushl %ebp
	movl %esp, %ebp
	andl $-16, %esp
        subl $0x32, %esp
	leave
