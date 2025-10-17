#include <stdio.h>

int main()
{
    float amount;
    int choice;
    const float USD_TO_INR = 83.0, EUR_TO_INR = 90.0;

    printf("=== Currency Converter ===\n");
    do
    {
        printf("\n1. USD to INR\n2. INR to USD\n3. EUR to INR\n4. INR to EUR\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (amount <= 0)
            {
                printf("Invalid amount!\n");
                continue;
            }

            switch (choice)
            {
            case 1:
                printf("%.2f USD = %.2f INR\n", amount, amount * USD_TO_INR);
                break;
            case 2:
                printf("%.2f INR = %.2f USD\n", amount, amount / USD_TO_INR);
                break;
            case 3:
                printf("%.2f EUR = %.2f INR\n", amount, amount * EUR_TO_INR);
                break;
            case 4:
                printf("%.2f INR = %.2f EUR\n", amount, amount / EUR_TO_INR);
                break;
            }
        }
        else if (choice != 5)
            printf("Invalid choice!\n");
    } while (choice != 5);

    printf("Thank you for using Currency Converter!\n");
    return 0;
}
