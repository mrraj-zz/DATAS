#include <stdio.h>

void main (void) {
    int value = 58;
    int guess;

    do
    {
        printf("please enter a value : ");
        scanf("%i", &guess);
	if(guess > value)
	    printf("this value is too big, ");
	else if(guess < value)
	    printf("this value is too small, ");
    }while(guess != value);

    printf("Congradulation You Guessed The Right Number. \n");
}

