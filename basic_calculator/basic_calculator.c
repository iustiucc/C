#include <stdio.h>
#include <stdlib.h>

float summation(float a, float b) {
    return a + b;
}

float subtraction(float a, float b) {
    return a - b;
}

float multiplication(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

int main() {
    float a, b;

    printf("Enter first number: ");
    if (scanf("%f", &a) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%f", &b) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    while (1) {
        printf("\nOperations:\n");
        printf(" 1. Addition\n");
        printf(" 2. Subtraction\n");
        printf(" 3. Multiplication\n");
        printf(" 4. Division\n");
        printf(" 5. Exit\n");
        printf("Enter your choice (1-5): ");

        int choice;
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Result: %.2f\n", summation(a, b));
                break;
            case 2:
                printf("Result: %.2f\n", subtraction(a, b));
                break;
            case 3:
                printf("Result: %.2f\n", multiplication(a, b));
                break;
            case 4:
                printf("Result: %.2f\n", division(a, b));
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}