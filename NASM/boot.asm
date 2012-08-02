[ org 0 x7c00 ]

mov bx , HELLO_MSG
call print_string
mov bx , GOODBYE_MSG
call print_string
jmp $
% include "print_string. a s m"
HELLO_MSG :
db ’ Hello , World ! ’ , 0

