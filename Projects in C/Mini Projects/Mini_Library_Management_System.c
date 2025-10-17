#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "library.txt"

struct Book
{
    int id;
    char title[50];
    char author[50];
};

void addBook()
{
    struct Book b;
    FILE *f = fopen(FILENAME, "a");
    if (!f)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Book Author: ");
    scanf(" %[^\n]", b.author);

    fprintf(f, "%d,%s,%s\n", b.id, b.title, b.author);
    fclose(f);
    printf("Book added successfully!\n");
}

void viewBooks()
{
    struct Book b;
    FILE *f = fopen(FILENAME, "r");
    if (!f)
    {
        printf("No books found!\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    while (fscanf(f, "%d,%[^,],%[^\n]\n", &b.id, b.title, b.author) != EOF)
    {
        printf("ID: %d | Title: %s | Author: %s\n", b.id, b.title, b.author);
    }
    fclose(f);
}

void searchBook()
{
    struct Book b;
    int id;
    char title[50];
    FILE *f = fopen(FILENAME, "r");
    if (!f)
    {
        printf("No books found!\n");
        return;
    }

    int choice;
    printf("Search by 1. ID  2. Title: ");
    scanf("%d", &choice);
    int found = 0;
    if (choice == 1)
    {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        while (fscanf(f, "%d,%[^,],%[^\n]\n", &b.id, b.title, b.author) != EOF)
        {
            if (b.id == id)
            {
                printf("Found: ID:%d | Title:%s | Author:%s\n", b.id, b.title, b.author);
                found = 1;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter Book Title: ");
        scanf(" %[^\n]", title);
        while (fscanf(f, "%d,%[^,],%[^\n]\n", &b.id, b.title, b.author) != EOF)
        {
            if (strcmp(b.title, title) == 0)
            {
                printf("Found: ID:%d | Title:%s | Author:%s\n", b.id, b.title, b.author);
                found = 1;
                break;
            }
        }
    }
    if (!found)
        printf("Book not found!\n");
    fclose(f);
}

void deleteBook()
{
    struct Book b;
    int id, found = 0;
    FILE *f = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!f)
    {
        printf("No books found!\n");
        fclose(temp);
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    while (fscanf(f, "%d,%[^,],%[^\n]\n", &b.id, b.title, b.author) != EOF)
    {
        if (b.id == id)
            found = 1;
        else
            fprintf(temp, "%d,%s,%s\n", b.id, b.title, b.author);
    }
    fclose(f);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
        printf("Book deleted successfully!\n");
    else
        printf("Book not found!\n");
}

int main()
{
    int choice;
    printf("=== Mini Library Management System ===\n");

    do
    {
        printf("\n1. Add Book\n2. View Books\n3. Search Book\n4. Delete Book\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            viewBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printf("Thank you for using Library System!\n");
            break;
        default:
            printf("Invalid choice! Select 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}
