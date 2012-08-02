#include<stdio.h>
#include<linux/types.h>

void main(void)
{
  __u8 reg_out, reg_in = 0xff;
  __asm__ ("movb %%fs:%1, %0" : "=q"(reg_out) : "m"(reg_in));
  printf("out is : %u \n", reg_out);
}
