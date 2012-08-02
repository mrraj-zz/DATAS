
#include<stdio.h>
#include<stdlib.h>

void main()
{
	const int *ids = malloc(sizeof(int));
	printf("%p \n", ids);
}
