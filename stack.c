#include <stdio.h>
#include "stack.h"

int DistanceFromTop = -1; //initialize array

void push(int val, int stack[]) {
    if (DistanceFromTop >= STACK_SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }
    DistanceFromTop++;//increment array size for pop and popp
    stack[DistanceFromTop] = val;
}

int pop(int stack[]) {
    if (DistanceFromTop == -1) {
        printf("Stack is empty.\n");
        return -1; 
    }
    int val = stack[DistanceFromTop];
    DistanceFromTop--;
    return val;
}

void pushp(int val, int* stack) {
    if (DistanceFromTop >= STACK_SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }
    DistanceFromTop++;
    *(stack + DistanceFromTop) = val;
}

int popp(int* stack) {
    if (DistanceFromTop == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    int val = *(stack + DistanceFromTop);
    DistanceFromTop--;
    return val;
}

