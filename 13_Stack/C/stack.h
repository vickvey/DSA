#ifndef STACK_H_IMPLEMENTATION_
#define STACK_H_IMPLEMENTATION_

#ifndef _DATATYPE
typedef int _DATATYPE;
#endif

typedef struct stack stack;

struct stack {
    int capacity;
    _DATATYPE *array;

    int top_index; 
    // Other member values if needed
};

void create_stack(stack *stack_ref);
void destroy_stack(stack *stack_ref);

void push(stack *stack_ref, _DATATYPE data);
_DATATYPE pop(stack *stack_ref);
_DATATYPE front(stack *stack_ref);
int is_empty(stack *stack_ref);
int is_full(stack *stack_ref);
int count_elems(stack *stack_ref);

#endif // STACK_H_IMPLEMENTATION_