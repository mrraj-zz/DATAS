#include<stdio.h>

void main()
{
	int val;
	asm ("movl %%eax, %0;" : "=r" ( val ));
	printf("%d \n", val);
}
