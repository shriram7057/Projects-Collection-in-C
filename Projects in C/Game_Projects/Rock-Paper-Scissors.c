#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *choices[] = {"Rock", "Paper", "Scissors"};
    int player, computer;

    srand(time(NULL));
    printf("=== Rock-Paper-Scissors ===\n");
    printf("0: Rock\n1: Paper\n2: Scissors\n");

    printf("Enter your choice: ");
    scanf("%d", &player);
    computer = rand() % 3;

    printf("Player chose %s, Computer chose %s\n", choices[player], choices[computer]);

    if (player == computer)
        printf("It's a draw!\n");
    else if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1))
        printf("You win!\n");
    else
        printf("Computer wins!\n");

    return 0;
}
