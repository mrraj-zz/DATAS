#include<stdio.h>
#include<linux/types.h>

void main(void)
{
  __u8 ah = 0x0f, al;
  __asm__ ("movb $0x0f, %%ah;"
	   "int $0x10;"
	   "movb %%al, %0;"
	   : : "r"(al));
  printf("vidoe mode is %u \n", al);
}
