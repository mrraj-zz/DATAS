#include<stdio.h>

struct startup_info {
	int value;
}info = { 10 };

void main()
{
	struct startup_info *startup_info;
	startup_info = &info;
	printf("%d \n", startup_info -> value);
}
