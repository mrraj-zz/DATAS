#include <stdio.h>
#include <stdlib.h>

int main()
{
  unsigned int new_esp;
  unsigned int eax, ebx, ecx, edx, esi, edi, ebp, esp;
  printf("Hello asm\n");
  asm( 
    "pusha
     movl %%esp, %0
     movl (%%esp), %%eax
     movl %%eax, %1
     movl 0x04(%%esp), %%eax
     movl %%eax, %2
     movl 0x08(%%esp), %%eax
     movl %%eax, %3
     movl 0x0c(%%esp), %%eax
     movl %%eax, %4
     movl 0x10(%%esp), %%eax
     movl %%eax, %5
     movl 0x14(%%esp), %%eax
     movl %%eax, %6
     movl 0x18(%%esp), %%eax
     movl %%eax, %7
     movl 0x1c(%%esp), %%eax
     movl %%eax, %8
     popa
    "
    : "=m" (new_esp), "=m" (edi), "=m" (esi), "=m" (ebp), "=m" (esp),
      "=m" (ebx), "=m" (edx), "=m" (ecx), "=m" (eax)
    : 
  );
  printf("EAX %x \n", eax);
  printf("EBX %x \n", ebx);
  printf("ECX %x \n", ecx);
  printf("EDX %x \n", edx);
  printf("ESP %x \n", esp);
  printf("EBP %x \n", ebp);
  printf("ESI %x \n", esi);
  printf("EDI %x \n", edi);
  printf("ESP %x NEW \n", new_esp);
  return 0;
}     
