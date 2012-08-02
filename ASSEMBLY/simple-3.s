        .global _start
	.global _get_addition
        .text
_start:
        # write(1, message, 13)
	movl $100, %eax
	movl $200, %ebx
	movl %ebx, %eax
	movl %eax, %ebp
	calll _get_addition
        # exit(0)
        mov     $1, %eax                # system call 1 is exit
        xor     %ebx, %ebx              # we want return code 0
        int     $0x80                   # invoke operating system code
	.data
message:
        .ascii  "Hello, World This is mohanraj new operating system call\n"

_get_addition:
        movl $4, %eax
        movl $1, %ebx
	addl %eax, %ebx
        movl %ebp, %ecx 
        movl $100, %edx 
        int $0x80
	ret 
