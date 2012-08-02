#include <stdio.h>

int main()
{
	FILE *filepointer;
	int character;
	filepointer=fopen("test.c", "r"); //filepointer points to data.txt
	if (filepointer==NULL) { //error opening file returns NULL
		printf("Could not open data.txt!\n"); //error message
		return 1; //exit with failure
	}
	/* while character is not end of file */
	while ((character=fgetc(filepointer)) != EOF) {
		printf("%c", character); //print the character
	}
	fclose(filepointer); //close the file
	return 0; //success
}
