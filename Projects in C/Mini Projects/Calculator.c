#include <stdio.h>

int main() {
    char op;
    float num1, num2, result;
    int choice;

    printf("=== Welcome to Professional C Calculator ===\n");

    do {
        printf("\nSelect an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);

            switch(choice) {
                case 1:
                    result = num1 + num2;
                    op = '+';
                    break;
                case 2:
                    result = num1 - num2;
                    op = '-';
                    break;
                case 3:
                    result = num1 * num2;
                    op = '*';
                    break;
                case 4:
                    op = '/';
                    if(num2 != 0)
                        result = num1 / num2;
                    else {
                        printf("Error: Division by zero is not allowed!\n");
                        continue;
                    }
                    break;
            }
            printf("Result: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
        }
        else if(choice != 5)
            printf("Invalid choice! Please select 1-5.\n");

    } while(choice != 5);

    printf("\nThank you for using the Professional C Calculator. Goodbye!\n");
    return 0;
}
