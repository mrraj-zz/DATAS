#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u32 shr_in = 10, shr_out;
	__asm__ ("mov %0, %%eax;"
		 "shll $2, %%eax;" : "=a"(shr_out) : "a"(shr_in));
	printf("shrl of %u is : %u \n", shr_in, shr_out);
}
