#include<stdio.h>

#define cube(v) (v*v*v)
void main()
{   
    int x=2,y;   
    printf("%d \n",x);    
    printf("%d \n", cube(++x));    
    printf("%d \n",x);    
}

