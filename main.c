/*
 * Basic Calculator
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Declarations
 */

typedef enum {
    OP_ADD,
    OP_SUBTRACT,
    OP_RANGE_SUM
} Operation;


typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef int (*OperationFunction)(int a, int b);

Bool getOperation(Operation *operation, OperationFunction *operation_function);
int add(int a, int b);
int subtract(int a, int b);
int rangeSum(int a, int b);

/*
 * Functions
 */

int main(void) {
    int first_number;
    int second_number;
    Operation operation;
    OperationFunction function;
    Bool success;
    int scan_count;
    int result;

    success = getOperation(&operation, &function);
    if (!success) {
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

    if (operation == OP_RANGE_SUM && first_number > second_number) {
        printf("The Result is: Not Valid\n");
        return EXIT_FAILURE;
    }

    result = function(first_number, second_number);
    printf("The Result is: %d\n", result);

    return EXIT_SUCCESS;
}

/*
 * Get operation from user.
 * operation - the operation the user chose
 * operation_function - function corresponding to the operation the user chose.
 * return True iff a valid operation was entered.
 */
Bool getOperation(Operation *operation, OperationFunction *operation_function) {
    char c;
    int scan_count;

    printf("Please choose an operation (+/-/$):\n");
    scan_count = scanf("%c", &c);
    if (scan_count != 1) {
        return FALSE;
    }

    switch (c) {
        case '+':
            *operation = OP_ADD;
            *operation_function = add;
            break;
        case '-':
            *operation = OP_SUBTRACT;
            *operation_function = subtract;
            break;
        case '$':
            *operation = OP_RANGE_SUM;
            *operation_function = rangeSum;
            break;
        default:
            return FALSE;
    }
    return TRUE;
}

/*
 * Add operation
 */
int add(int a, int b) {
    return a + b;
}

/*
 * Subtract operation
 */
int subtract(int a, int b) {
    return a - b;
}

/*
 * Range sum operation
 */
int rangeSum(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}
