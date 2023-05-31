#include <stdio.h>
#include <stdlib.h>
#include "intstack.h"
#include <string.h>
#include <stdbool.h>


int main(int argc, char **argv) {
    if (argc != 3) {
        printf("%s <operand one> <operand two>\n", argv[0]);
        return 1;
    }

    char *FirstOperand = argv[1];
    char *SecondOperand = argv[2];

    IntStack FirstStack = int_make_stack();
    IntStack SecondStack = int_make_stack();
    IntStack result = int_make_stack();

    int FirstLength = strlen(FirstOperand);
    int SecondLength = strlen(SecondOperand);

    for (int i = 0; i < FirstLength; i++) { 
        int digit = FirstOperand[i]-'0';
        int_stack_push(FirstStack, digit);
    }

    for (int i = 0; i < SecondLength; i++) { 
        int digit = SecondOperand[i]-'0';
        int_stack_push(SecondStack, digit);
    }

    int carryOver= 0;

    while (!int_stack_is_empty(FirstStack) || !int_stack_is_empty(SecondStack) || carryOver > 0) {
        int sum = carryOver;

        if (!int_stack_is_empty(FirstStack)) {
            sum += int_stack_pop(FirstStack);
        }

        if (!int_stack_is_empty(SecondStack)) {
            sum += int_stack_pop(SecondStack);
        }

        carryOver = sum / 10;
        int digit = sum % 10;
        int_stack_push(result, digit);
    }


    while (int_stack_is_empty(result)==false) {
        printf("%d", int_stack_pop(result));
    }
    printf("\n");


    free(FirstStack);
    free(SecondStack);
    free(result);

    return 0;
}