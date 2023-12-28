#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"

const int STACK_CAPACITY_INIT = 4;
const int _DATATYPE_DEFAULT = INT_MIN;

static void resize_stack(stack *stack_ref) {
    assert(stack_ref != NULL);

    stack_ref->capacity *= 2;
    _DATATYPE *new_array = NULL;

    new_array = (_DATATYPE *) 
        realloc(stack_ref->array, stack_ref->capacity * sizeof(_DATATYPE));
    
    // Verify memory reallocation
    assert(new_array != NULL);

    free(stack_ref->array);
    stack_ref->array = new_array;
    
    new_array = NULL;
}

void create_stack(stack *stack_ref) {
    assert(stack_ref != NULL && stack_ref->array == NULL);
    // TODO: 
    stack_ref->capacity = STACK_CAPACITY_INIT;
    stack_ref->array = 
        (_DATATYPE *) malloc(stack_ref->capacity * sizeof(_DATATYPE));

    // Verify memory allocation 
    // if(stack_ref->array == NULL) exit(1);
    assert(stack_ref->array != NULL);

    stack_ref->top_index = -1;
}

void destroy_stack(stack *stack_ref) {
    assert(stack_ref != NULL);
    // TODO:
    free(stack_ref->array);
    stack_ref->array = NULL;
    stack_ref->capacity = 0;
    stack_ref->top_index = -1;
}

void push(stack *stack_ref, _DATATYPE data) {
    assert(stack_ref != NULL);
    if(is_full(stack_ref)) {
        resize_stack(stack_ref);
    }

    // Now insert data at top of stack
    stack_ref->array[stack_ref->top_index + 1] = data;
    stack_ref->top_index++;
}

_DATATYPE pop(stack *stack_ref) {
    assert(stack_ref != NULL);

    if(stack_ref->top_index == -1) return _DATATYPE_DEFAULT;

    _DATATYPE temp = front(stack_ref); 
    stack_ref->top_index--;

    return temp;
}

_DATATYPE front(stack *stack_ref) {
    assert(stack_ref != NULL);

    if(stack_ref->top_index == -1) return _DATATYPE_DEFAULT;

    return stack_ref->array[stack_ref->top_index];
}

int is_full(stack *stack_ref) {
    assert(stack_ref != NULL);
    
    // Indicate stack is full
    if(stack_ref->top_index + 1 == stack_ref->capacity) return 1;

    return 0; // Indicate that stack is not full
}

int count_elems(stack *stack_ref) {
    assert(stack_ref != NULL);
    return stack_ref->top_index + 1;
}
