#include <stdio.h>

int main()
{
    float temp;
    int choice;
    printf("=== Temperature Converter ===\n");

    do
    {
        printf("\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Kelvin to Celsius\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Celsius: ");
            scanf("%f", &temp);
            printf("Fahrenheit: %.2f\n", (temp * 9 / 5) + 32);
        }
        else if (choice == 2)
        {
            printf("Enter Fahrenheit: ");
            scanf("%f", &temp);
            printf("Celsius: %.2f\n", (temp - 32) * 5 / 9);
        }
        else if (choice == 3)
        {
            printf("Enter Kelvin: ");
            scanf("%f", &temp);
            printf("Celsius: %.2f\n", temp - 273.15);
        }
        else if (choice != 4)
            printf("Invalid choice!\n");
    } while (choice != 4);

    printf("Thank you for using Temperature Converter!\n");
    return 0;
}
