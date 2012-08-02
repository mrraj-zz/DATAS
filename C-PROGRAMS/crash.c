#include<stdio.h>
#include<stdlib.h>

int main()
{
   int *ptr;
   int x;
   x = 5;
   ptr = malloc(1);
   *ptr = 6;
   printf("The value at *ptr = %d \n", *ptr);
   ptr++;      //Now ptr is address has been changed
   free(ptr); // Program should crash here
   ptr = NULL;
   /* *ptr = 5;*/ // This statement is crashing
return 0;
}

