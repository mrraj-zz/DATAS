#include<stdio.h>

void main(void)
{
    int f;
    asm volatile ( "pushf\n\t;"
                   "popl %0;"
                   : "=g"(f) );

	printf("%d \n", f & (1 << 9));
}
