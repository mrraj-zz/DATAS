#include<stdio.h>
#include<linux/types.h>

void main()
{
	typedef __u16 u16;
	__u32 id = 1000000;
	u16 sno = 1000;
	printf("%d \n", id);
	printf("%d \n", sno);
}
