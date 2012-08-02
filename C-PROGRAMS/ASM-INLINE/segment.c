#include<stdio.h>
#include<linux/types.h>

void main(void)
{
  __u32 *eip;
  __asm__ ("movl %%edi, %0;" : "=r"(eip));
  printf("EIP addres is %p and value is \n", eip);
}
