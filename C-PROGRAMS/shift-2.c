#include<stdio.h>

  main()
  {
    unsigned int Value=4;          /*  4 = 0000 0100 */  
    unsigned int Shift=2;

    Value = Value << Shift;        /* 16 = 0001 0000 */  

    Value <<= Shift;               /* 64 = 0100 0000 */  

    printf("%d\n", Value);         /* Prints 64      */  
  }
