SECTION .text

global s_func
extern c_str
extern printf

s_func:
    sub esp, 4
    mov dword [esp], c_str
    call printf
    add esp, 4
    ret
