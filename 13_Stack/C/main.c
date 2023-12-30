#include <stdio.h>
#include "stack.h"

int main() {
    // Initialised the stack variable
    stack st;

    // Created the stack variable
    create_stack(&st);

    // Now using the common stack functions 
    if(is_full(&st)) {
        puts("The stack is full!!");
    }

    push(&st, 10);
    push(&st, 20);

    printf("The data at top now is : %d!\n", front(&st));

    // Now lets pop back the data
    pop(&st);
    printf("The data at top now is : %d\n", front(&st));

    printf("The data at top is used and popped : %d!\n", pop(&st));

    printf("The data at top now is : %d!\n", front(&st));

    // Destroy the stack
    destroy_stack(&st);
    return 0;
}