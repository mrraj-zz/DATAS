#include<stdio.h>

struct struct_usage {
	int id:2;
};

char *name(char *path);
void main()
{
	struct struct_usage usage;
	printf("%d \n", usage.id);
	char *path = name("/home/mohanraj");
	printf("%s \n", path);
}
