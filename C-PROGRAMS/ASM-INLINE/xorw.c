#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	__u16 value = 100, result = 0, result_1 = 0;
	asm volatile("xorw %%ax, %%bx;": "=a"(result), "=b"(result_1): "a"(value), "b"(value));
	printf("%u \n", result);
	printf("%u \n", result_1);
}
