#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[100];

    while (1)
    {
        printf("myshell> ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\n");
            break; // handle EOF (Ctrl+D)
        }

        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0)
            break;

        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process
            execlp("/bin/sh", "sh", "-c", command, NULL);
            perror("exec failed"); // exec only returns on error
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}
