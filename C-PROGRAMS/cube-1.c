#include<stdio.h>

void main()
{   
    int x=2,y;   
    y=++x*++x*++x;            
    printf("%d %d",++x,y);    
}

