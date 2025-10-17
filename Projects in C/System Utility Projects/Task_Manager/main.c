#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    do
    {
        printf("\n1.List Processes\n2.Kill Process\n3.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1)
            system("ps -e");
        else if (choice == 2)
        {
            int pid;
            printf("Enter PID to kill: ");
            scanf("%d", &pid);
            char cmd[50];
            sprintf(cmd, "kill -9 %d", pid);
            system(cmd);
        }
        else if (choice != 3)
            printf("Invalid choice!\n");
    } while (choice != 3);
    return 0;
}
