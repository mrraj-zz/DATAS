#include<stdio.h>

int a = 10000;
char *alb = (char *)a;

void main()
{
	while(*alb)
	{
		printf("char is : %c \n", *alb);
		alb = alb + 1;
	}
}
