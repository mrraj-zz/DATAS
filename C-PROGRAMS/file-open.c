#include<stdio.h>

void main()
{
	FILE *file = fopen("test.c", "r");
	
	char chr;
	if(file == NULL)
		printf("Could not open file");
	while(1)
	{
		chr = fgetc(file);
		if(chr == EOF)
			break;
		else
			printf("%c", chr);
	}
	fclose(file);
	printf("File has beed red and printed");
}
