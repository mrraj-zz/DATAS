#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u32 shift = 100;
	printf("left shift to 4 bit : %u \n", shift << 5);
	printf("mul by 16 : %u \n", shift * 32);
}
