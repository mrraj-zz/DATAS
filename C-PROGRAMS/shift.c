#include<stdio.h>

void main(void)
{
	unsigned int x, y, z;

	x = 0x00AA;
	y = 0x5500;

	printf("%u \n", 2 >> 2);
	printf("%u \n", x << 1);
	z = ( x << 8 ) + ( y >> 8 );
	printf("%u \n", z);
}
