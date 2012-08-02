#include<stdio.h>
#include<linux/types.h>

void main(void)
{
  __u32 *esp_first, *esp_second;
  __asm__ ("pushl $200;"
	   "movl %%esp, %%eax;"
	   "movl %%eax, %0;"
	   "movl %%eax, %%esp;"
	   "pushl $100;"
	   "movl %%esp, %1;" : "=r"(esp_first), "=r"(esp_second));
  printf("esp value is : %u \n", *esp_first);
  printf("esp value is : %u \n", *esp_second);
}
