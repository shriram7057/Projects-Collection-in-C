#include <stdio.h>

int main()
{
    int choice;
    float balance = 0.0, amount;

    printf("=== Welcome to Mini Banking System ===\n");

    do
    {
        printf("\n-------------------------------\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0)
            {
                printf("Invalid amount! Please enter a positive value.\n");
            }
            else
            {
                balance += amount;
                printf("Successfully deposited: %.2f\n", amount);
            }
            break;

        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0)
            {
                printf("Invalid amount! Please enter a positive value.\n");
            }
            else if (amount > balance)
            {
                printf("Insufficient balance! Current balance: %.2f\n", balance);
            }
            else
            {
                balance -= amount;
                printf("Successfully withdrawn: %.2f\n", amount);
            }
            break;

        case 3:
            printf("Your current balance: %.2f\n", balance);
            break;

        case 4:
            printf("\nThank you for using Mini Banking System. Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
