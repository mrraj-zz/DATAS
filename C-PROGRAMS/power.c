#include<stdio.h>
#include<linux/types.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

void main(void)
{
	int exp_1 = 100 << 4;
	int exp_2 = 100 >> 10;
	int exp_3 = 100 & 500;

	printf("%d \n", exp_1);
	printf("%d \n", exp_2);
	printf("%d \n", exp_3);

	printf("%d \n", 1 << 20);

	__u16 sht = 10000;
	printf("After 4 times left shift: %u \n", sht << 4);
	BUILD_BUG_ON(sizeof sht != 2);

	printf("bool is: %d \n", sizeof(char[1 - 2*!!(1)]));
}
