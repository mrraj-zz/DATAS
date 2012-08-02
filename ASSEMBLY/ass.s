.code16
.globl _start
.globl label2
.text
_start:
    jmp label2
    movl $label2, %ecx
label2:
    movl $0x100, %eax
