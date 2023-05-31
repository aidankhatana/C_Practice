#ifndef INT_STACK
#define INT_STACK

struct int_node {
    int value;
    struct int_node *next;
};

typedef struct int_node** IntStack;

void        int_stack_push      (IntStack stack, int value);
int         int_stack_is_empty  (IntStack stack);
int         int_stack_pop       (IntStack stack);
void        int_stack_print     (IntStack stack);
IntStack    int_make_stack      (void);

#endif