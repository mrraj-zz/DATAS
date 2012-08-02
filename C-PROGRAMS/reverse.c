#include <stdio.h>
#include<string.h>

void main(void)
{
  char *name = "Mohanraj";
  char *reverse = (char *)name;
  reverse = reverse + strlen(name) - 1;
  while(*reverse)
    printf("%c", *(reverse--));
}
