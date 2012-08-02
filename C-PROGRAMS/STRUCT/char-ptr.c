#include<stdio.h>

void main(void)
{
  unsigned short ax;
  __asm__ ("xorw %%ax, %%ax;"
	   "int $0x12;"
	   "movw %%ax, 0%;" : "=r"(ax));
  printf("Address is : %d", ax);
}
