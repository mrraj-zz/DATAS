
#include<stdio.h>
#include<linux/types.h>

void main(void)
{
  __u32 *esp;
  __asm__ ("pushl $100;"
	   "pushl $200;"
	   "pushl $300;"
	   "movl %%esp, %0;" : "=r"(esp));
  printf("ESP address is %p, and the value is %u \n", esp, *esp);

  __asm__("popl %%eax;"
	  "popl %%eax;"
	  "popl %%eax;"
	  "popl %%eax;"
	  "movl %%esp, %0;" : "=r"(esp));
  printf("ESP address is %p, and the value is %u \n", esp, *esp);
}
