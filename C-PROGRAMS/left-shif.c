#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u32 shift = 2;
	printf("left shift two times : %u \n", shift << 2);
	printf("right shift two times : %u \n", shift >> 2);
}
