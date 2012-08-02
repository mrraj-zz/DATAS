#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	FILE *file = fopen("noah.diff", "r");
	char line[100];

	if(file  != NULL)
	{
		while(fgets(line, sizeof line, file) != NULL)
		printf("%s", line);
		fclose(file);
	}
}
