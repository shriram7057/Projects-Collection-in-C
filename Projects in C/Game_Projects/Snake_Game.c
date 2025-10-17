#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail = 0;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
} dir;

void Setup()
{
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    score = 0;

    srand(time(NULL));
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else
            {
                int printed = 0;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        printed = 1;
                        break;
                    }
                }
                if (!printed)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\nScore: %d\n", score);
}

void Input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            printf("Game Over!\nFinal Score: %d\n", score);
            exit(0);
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Check wall collision
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
        Draw();
        printf("Game Over!\nFinal Score: %d\n", score);
        getch();
        exit(0);
    }

    // Check tail collision
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            Draw();
            printf("Game Over!\nFinal Score: %d\n", score);
            getch();
            exit(0);
        }
    }

    // Eat fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        nTail++;

        // Respawn fruit not on snake
        int valid = 0;
        while (!valid)
        {
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;
            valid = 1;
            for (int i = 0; i < nTail; i++)
            {
                if (tailX[i] == fruitX && tailY[i] == fruitY)
                {
                    valid = 0;
                    break;
                }
            }
        }
    }
}

int main()
{
    Setup();
    while (1)
    {
        Draw();
        Input();
        Logic();
        Sleep(100); // Adjust speed here
    }
    return 0;
}
