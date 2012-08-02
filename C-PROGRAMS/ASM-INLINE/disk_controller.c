
#include <stdio.h>

void main(void)
{
  __asm__ ("movw $0x0000, %ax;"
           "movb $0x80, %dl;"
           "int $0x13;");
}
