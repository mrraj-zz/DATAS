#include<stdio.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

void main()
{
	char *name = BUILD_BUG_ON(0);
}

