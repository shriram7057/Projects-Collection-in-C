#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile()
{
    char filename[50];
    printf("Enter filename to create: ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    if (f)
    {
        printf("File created successfully!\n");
        fclose(f);
    }
    else
        printf("Error creating file!\n");
}

void writeFile()
{
    char filename[50], text[200];
    printf("Enter filename to write: ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "a");
    if (!f)
    {
        printf("File not found!\n");
        return;
    }
    printf("Enter text: ");
    scanf(" %[^\n]", text);
    fprintf(f, "%s\n", text);
    fclose(f);
    printf("Text written successfully!\n");
}

void readFile()
{
    char filename[50], line[200];
    printf("Enter filename to read: ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("File not found!\n");
        return;
    }
    printf("File content:\n");
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
}

void deleteFile()
{
    char filename[50];
    printf("Enter filename to delete: ");
    scanf("%s", filename);
    if (remove(filename) == 0)
        printf("File deleted successfully!\n");
    else
        printf("Error deleting file!\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n1.Create File\n2.Write File\n3.Read File\n4.Delete File\n5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createFile();
            break;
        case 2:
            writeFile();
            break;
        case 3:
            readFile();
            break;
        case 4:
            deleteFile();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
