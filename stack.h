#ifndef _stack_h
#define _stack_h

#define STACK_SIZE 500 

void push(int val, int stack[]);
int pop(int stack[]);
void pushp(int val, int* stack);
int popp(int* stack);

#endif // _stack_h