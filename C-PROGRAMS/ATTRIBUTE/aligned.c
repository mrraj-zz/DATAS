#include<stdio.h>

struct kernel {
  char *name;
  long id;
  long address;
  short v;
};

struct kernel kernel __attribute__((aligned(16)));

void main(void)
{
  printf("size of kernel is : %p \n", &kernel);
  printf("size of kernel is : %p \n", &kernel.name);
  printf("size of kernel is : %p \n", &kernel.id);
  printf("size of kernel is : %p \n", &kernel.address);
  printf("size of kernel is : %p \n", &kernel.v);
}
