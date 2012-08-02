#include<stdio.h>
#include<linux/types.h>

struct EMPLOYEE {
  struct EMPLOYEE *EMP_1;
  struct EMPLOYEE *EMP_2;
};

void kmain(name)
     char *name;
{
  printf("given string is: %s \n", name);
}

void main(void)
{
  struct EMPLOYEE EMP;
  printf("Total size is : %d \n", sizeof EMP);

  kmain();
  kmain("Mohanraj", "Ramanujam");
}
