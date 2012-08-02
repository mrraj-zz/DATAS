	.text
	.global check_a20
check_a20:
    pushf
    push %ds
    push %es
    push %di
    push %si
 
    cli
 
    xor %ax, %ax
    mov %ax, %es
 
    not %ax
    mov %ds, %ax
 
    mov $0x0500, %di
    mov $0x0510, %si
 
    mov %di, %ax
    push %ax
 
    mov %si, %ax
    push %ax
 
    mov $0x00, %di
    mov $0xff, %si
 
    cmp $0xff, %di
 
    pop %ax
    mov %ax, %si
 
    pop %ax
    mov %ax, %di
 
    mov $0x0, %ax
    je check_a20__exit
 
    mov $0x1, %ax
 
check_a20__exit:
    pop %si
    pop %di
    pop %es
    pop %ds
    popf
 
    ret
