
#include<stdio.h>

struct employee {
	int id;
	char name[1];
}emp;

void main()
{
	printf("%d \n", sizeof(emp));
}
