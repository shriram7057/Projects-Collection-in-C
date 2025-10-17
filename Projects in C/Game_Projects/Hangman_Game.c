#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char word[50], guessed[50];
    int len, attempts = 6, i;
    printf("Enter word to guess: ");
    scanf("%s", word);
    len = strlen(word);
    for (i = 0; i < len; i++)
        guessed[i] = '_';
    guessed[len] = '\0';

    while (attempts > 0)
    {
        char ch;
        int correct = 0;
        printf("Word: %s\n", guessed);
        printf("Enter a letter: ");
        scanf(" %c", &ch);
        for (i = 0; i < len; i++)
        {
            if (word[i] == ch)
            {
                guessed[i] = ch;
                correct = 1;
            }
        }
        if (!correct)
            attempts--;
        if (strcmp(word, guessed) == 0)
        {
            printf("You win! Word: %s\n", word);
            return 0;
        }
        printf("Attempts left: %d\n", attempts);
    }
    printf("Game Over! Word was: %s\n", word);
    return 0;
}
