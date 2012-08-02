#include<stdio.h>
#include<stdarg.h>

void print_args(int arg, ...)
{
	va_list va;
	int p_arg;

	va_start(va, arg);
	for(p_arg=0; p_arg<arg; p_arg++ )
		printf("%d ", va_arg(va, int));

	va_end(va);
}

int main()
{
	print_args(10, 20, 30, 40, 50);
}
