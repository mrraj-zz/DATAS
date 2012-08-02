#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u32 neg_value = 0x200;
	printf("%u is : %u \n", neg_value, ~neg_value);
}
