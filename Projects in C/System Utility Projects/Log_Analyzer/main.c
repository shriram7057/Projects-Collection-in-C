#include <stdio.h>
#include <string.h>

int main()
{
    char filename[100], line[500], keyword[50];
    int count = 0;

    printf("Enter log file name: ");
    scanf("%s", filename);
    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("File not found!\n");
        return 0;
    }

    while (fgets(line, sizeof(line), f))
    {
        if (strstr(line, keyword))
        {
            printf("%s", line);
            count++;
        }
    }
    fclose(f);
    printf("\nTotal occurrences: %d\n", count);
    return 0;
}
