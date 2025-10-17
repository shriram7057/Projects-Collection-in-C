#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf(" %c ", board[i][j]);
        printf("\n");
    }
}

int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int main()
{
    int choice, player = 1, position;
    char mark;
    printf("=== Tic-Tac-Toe Game ===\n");

    for (int i = 0; i < 9; i++)
    {
        displayBoard();
        player = (i % 2) + 1;
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d enter position (1-9): ", player);
        scanf("%d", &position);

        int row = (position - 1) / 3, col = (position - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Invalid move! Try again.\n");
            i--;
            continue;
        }
        board[row][col] = mark;

        if (checkWin())
        {
            displayBoard();
            printf("Player %d wins!\n", player);
            return 0;
        }
    }
    displayBoard();
    printf("It's a draw!\n");
    return 0;
}
