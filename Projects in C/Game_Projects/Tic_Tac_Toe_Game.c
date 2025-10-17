#include <stdio.h>

char board[3][3];

void initBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}

int main()
{
    int row, col, turn = 0;
    char player;
    initBoard();

    while (turn < 9)
    {
        displayBoard();
        player = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = player;

        if (checkWin())
        {
            displayBoard();
            printf("Player %c wins!\n", player);
            return 0;
        }

        turn++;
    }

    displayBoard();
    printf("It's a draw!\n");
    return 0;
}
