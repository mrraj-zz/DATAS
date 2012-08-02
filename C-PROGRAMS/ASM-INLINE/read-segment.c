#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u32 cs;
        asm volatile("movl %%cs,%0" : "=rm" (cs));
	printf("%u \n", cs);
}
