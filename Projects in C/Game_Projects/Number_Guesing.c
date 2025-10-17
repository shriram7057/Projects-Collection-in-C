#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    do
    {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;
        if (guess > number)
            printf("Too high!\n");
        else if (guess < number)
            printf("Too low!\n");
        else
            printf("Correct! You guessed in %d attempts.\n", attempts);
    } while (guess != number);
    return 0;
}
