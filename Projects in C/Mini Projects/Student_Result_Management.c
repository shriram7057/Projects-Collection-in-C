#include <stdio.h>
#include <string.h>

int main()
{
    int choice;
    char studentName[50];
    char subjects[3][50];
    int marks[3];
    float total, avg, gpa[3], cgpa;

    printf("=== Student Result Management System with GPA/CGPA ===\n");

    do
    {
        printf("\n-------------------------------\n");
        printf("1. Enter Student Result\n");
        printf("2. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            total = 0;
            cgpa = 0;

            printf("Enter student name: ");
            scanf("%s", studentName);

            // Enter subject names
            for (int i = 0; i < 3; i++)
            {
                printf("Enter name of subject %d: ", i + 1);
                scanf("%s", subjects[i]);
            }

            // Enter marks and calculate GPA
            for (int i = 0; i < 3; i++)
            {
                do
                {
                    printf("Enter marks for %s (0-100): ", subjects[i]);
                    scanf("%d", &marks[i]);
                    if (marks[i] < 0 || marks[i] > 100)
                        printf("Invalid marks! Please enter between 0 and 100.\n");
                } while (marks[i] < 0 || marks[i] > 100);

                total += marks[i];

                // Calculate GPA per subject (4.0 scale)
                if (marks[i] >= 90)
                    gpa[i] = 4.0;
                else if (marks[i] >= 75)
                    gpa[i] = 3.0;
                else if (marks[i] >= 50)
                    gpa[i] = 2.0;
                else
                    gpa[i] = 0.0;

                cgpa += gpa[i];
            }

            avg = total / 3;
            cgpa /= 3; // Average GPA = CGPA

            // Display results
            printf("\n--- Result ---\n");
            printf("Student Name: %s\n", studentName);
            printf("Subject\tMarks\tGrade\tGPA\n");
            for (int i = 0; i < 3; i++)
            {
                char grade;
                if (marks[i] >= 90)
                    grade = 'A';
                else if (marks[i] >= 75)
                    grade = 'B';
                else if (marks[i] >= 50)
                    grade = 'C';
                else
                    grade = 'F';

                printf("%s\t%d\t%c\t%.1f\n", subjects[i], marks[i], grade, gpa[i]);
            }

            printf("Total Marks: %.2f\n", total);
            printf("Average Marks: %.2f\n", avg);
            printf("CGPA: %.2f / 4.0\n", cgpa);

            break;

        case 2:
            printf("\nThank you for using Student Result Management System. Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please select 1 or 2.\n");
        }

    } while (choice != 2);

    return 0;
}
