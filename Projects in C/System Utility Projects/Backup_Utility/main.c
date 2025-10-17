#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void backupFile(char *source, char *dest)
{
    struct stat src_stat, dest_stat;
    char cmd[500];

    if (stat(source, &src_stat) != 0)
    {
        printf("Source file %s does not exist!\n", source);
        return;
    }

    if (stat(dest, &dest_stat) == 0)
    {
        if (src_stat.st_mtime <= dest_stat.st_mtime)
        {
            printf("Skipping %s (already up-to-date)\n", source);
            return;
        }
    }

    sprintf(cmd, "cp -u %s %s", source, dest);
    system(cmd);
    printf("Backed up %s to %s\n", source, dest);
}

int main()
{
    char source[200], dest[200];
    int choice;

    printf("=== Advanced Backup Utility ===\n");

    do
    {
        printf("\n1. Backup File\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source file path: ");
            scanf(" %[^\n]", source);
            printf("Enter destination path: ");
            scanf(" %[^\n]", dest);
            backupFile(source, dest);
            break;
        case 2:
            printf("Exiting Backup Utility.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 2);

    return 0;
}
