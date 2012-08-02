/*   using interupt 12H  BIOS)              */
#include<stdio.h>
#include<bios.h>
int main(void)
 {
  printf("memory size %d kbite\n", biosmemory());
  return 0;
 }
