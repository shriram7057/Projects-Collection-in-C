#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int val)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = val;
    printf("%d pushed.\n", val);
}

void pop()
{
    if (top < 0)
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped.\n", stack[top--]);
}

void display()
{
    if (top < 0)
    {
        printf("Stack empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int choice, val;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
