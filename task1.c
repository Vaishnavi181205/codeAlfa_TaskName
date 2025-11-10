//TASK 1: Basic Calculator Program in C

/*Objective:
Perform basic arithmetic operations — Addition, Subtraction, Multiplication, and Division
using switch-case statements*/


#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("----- Basic Calculator -----\n");
    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            if (num2 != 0)
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;

        default:
            printf("Invalid operator! Please use +, -, *, or /.\n");
            break;
    }

    return 0;
}


    char operator;
    double num1, num2, result;
    printf(" Basic Calculator\n");
    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            if (num2 != 0)
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;

        default:
            printf("Invalid operator! Please use +, -, *, or /.\n");
            break;
    }

    return 0;
}


