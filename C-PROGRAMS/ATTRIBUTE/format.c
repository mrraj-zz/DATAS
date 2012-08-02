#include<stdio.h>

/* like printf() but to standard error only */
extern void eprintf(const char *format, ...)__attribute__((format(printf, 1, 2)));  /* 1=format 2=params */

void main()
{
	eprintf("This is test string \n");
}

void eprintf(const char *format, ...)
{
	printf("Hi \n");
}
