 .data
 
 value:
         .long   2
 
 .text
         .global _start
 
 _start:
         movl    $6, %eax
         # %eax is now 6
 
         movw    %ax, value
         # value is now 6
 
         movl    $0, %ebx
         # %ebx is now 0
 
         movb    %al, %bl
         # %ebx is now 6
 
         movl    value, %ebx
         # %ebx is now 6
 
         movl    $value, %esi
         # %esi is now the address of value
 
         xorl    %ebx, %ebx
         # %ebx is now 0
 
         movw    value(, %ebx, 1), %bx
         # %ebx is now 6
 
 # Linux sys_exit
         mov     $1, %eax
         xorl    %ebx, %ebx
         int     $0x80
