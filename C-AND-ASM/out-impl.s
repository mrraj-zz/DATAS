.data
.section        .rodata
.Lout:
        .string "Data %02x %02x %02x %02x \n"
.text
        .align 4
.globl outreg
        .type outreg,@function  
outreg:
        pushl %ebp                /*  push Frame Pointer on the stack */
        movl  %esp, %ebp          /*  save Stack Pointer in Frame Pointer */
        push  %eax                /*  save EAX: avoid side effects */
        movl  8(%ebp), %eax       /*  move the parameter in the register EAX */
        andl  $0x000000ff, %eax   /*  Least Significant Byte */
        pushl %eax            
        movl  8(%ebp), %eax
        shrl  $8, %eax            /*  shift 8 bit to the right */
        andl  $0x000000ff, %eax   /*  Second Least Significant Byte */
        pushl %eax
        movl  8(%ebp), %eax
        shrl  $16, %eax
        andl  $0x000000ff, %eax   /*  Third Byte */
        pushl %eax
        movl  8(%ebp), %eax
        shrl  $24, %eax
        andl  $0x000000ff, %eax   /*  Most Significal Byte */
        pushl %eax
        pushl $.Lout              /*  push the (address of the) format string */
        call  printf
        addl  $20, %esp           /*  5 args * 4 = 20 bytes */
        popl  %eax                /*  restore register EAX */
        movl  %ebp, %esp
        popl  %ebp
        ret
Lfoutreg:
        .size outreg,Lfoutreg-outreg

