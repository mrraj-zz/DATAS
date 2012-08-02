#include<stdio.h>
#include<stdlib.h>

void main()
{
  	int *ptr = malloc(sizeof(int));
	*ptr = 100;
  	printf("%p \n", ptr);
	printf("%d \n" , *ptr);
	printf("%p \n", ptr);

	for(;;)
	{
		printf("%d \n", *ptr);
		printf("%p \n", ptr);
		ptr++;
	}
}
