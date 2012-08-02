#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u32 ds;
	asm ("movl %%ds, %0" : "=rm"(ds));
	printf("DS value is : %u \n", ds);
}
