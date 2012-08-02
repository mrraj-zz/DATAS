#include<stdio.h>

void main(void)
{
	const int x1 __attribute__((at(0x10000))) = 10; /* RO */
	int x2 __attribute__((at(0x12000))) = 10; /* RW */
	int x3 __attribute__((at(0x14000))) = 0; /* RVCT 3.1 and earlier: RW.
						  * RVCT 4.0 and later: ZI. */
	int x4 __attribute__((at(0x16000))); /* ZI */
}
