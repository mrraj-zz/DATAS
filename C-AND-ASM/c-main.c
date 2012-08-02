#include <stdio.h>
 
/* prototype for asm function */
int * asm_mod_array(int *ptr,int size);
 
int main(void)
{
  int fren[5]={ 1, 2, 3, 4, 5 };
 
  /* call the asm function */
  printf("Mod is : %d \n", *asm_mod_array(fren, 5));
 
  return 0;
}
