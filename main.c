/*
 * Basic Calculator
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Declarations
 */

int rangeSum(int a, int b);

/*
 * Functions
 */

int main(void) {
    int scan_count;
    char operation;
    int first_number;
    int second_number;
    int result;

    printf("Please choose an operation (+/-/$):\n");
    scan_count = scanf("%c", &operation);
    if (scan_count != 1
        || (operation != '+'
            && operation != '-'
            && operation != '$')) {
        printf("Invalid Operation\n");
        return EXIT_FAILURE;
    }

    printf("Please enter the first operand:\n");
    scan_count = scanf("%d", &first_number);
    if (scan_count != 1) {
        printf("Invalid Number\n");
        return EXIT_FAILURE;
    }

    printf("Please enter the second operand:\n");
    scan_count = scanf("%d", &second_number);
    if (scan_count != 1) {
        printf("Invalid Number\n");
        return EXIT_FAILURE;
    }

    switch (operation) {
        case '+':
            result = first_number + second_number;
            break;
        case '-':
            result = first_number - second_number;
            break;
        case '$':
            if (first_number > second_number) {
                printf("The Result is: Not Valid\n");
                return EXIT_FAILURE;
            }
            result = rangeSum(first_number, second_number);
            break;
        default:
            /* Flow shouldn't reach here */
            return EXIT_FAILURE;
    }

    printf("The Result is: %d\n", result);

    return EXIT_SUCCESS;
}

/*
 * Return the sum of all integers in the range [a, b].
 * Preconditions: b >= a
 */
int rangeSum(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}
