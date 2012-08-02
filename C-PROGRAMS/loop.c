#include <stdio.h>

int main (void) {
    int value = 58;
    int guess;

    printf("Please enter a value: ");
    scanf("%i", &guess);

    if (guess == value) {
        printf("Congratulations, you guessed the right value");
    }
    else if (guess > value) {
        printf("That value is too high. Please guess again: ");
        scanf("%i", &guess);
    }
    else if (guess < value) {
        printf("That value is too low. Please guess again: ");
        scanf("%i", &guess);
    }

    return 0;
}

