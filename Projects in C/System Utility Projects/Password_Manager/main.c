#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char site[50];
    char password[50];
} Entry;

Entry entries[100];
int count = 0;

void addEntry()
{
    printf("Enter site name: ");
    scanf("%s", entries[count].site);
    printf("Enter password: ");
    scanf("%s", entries[count].password);
    count++;
    printf("Password saved!\n");
}

void viewEntries()
{
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s : %s\n", i + 1, entries[i].site, entries[i].password);
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n1.Add Entry\n2.View Entries\n3.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}
