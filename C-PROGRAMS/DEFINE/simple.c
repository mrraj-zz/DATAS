#include<stdio.h>

#define MohanrajRamanujam "mohanraj"
#define __AC(X, Y) (X##Y)
#define __AT(X, Y) ((X)(Y))
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
void main()
{
	__AC(1, 1);
}
