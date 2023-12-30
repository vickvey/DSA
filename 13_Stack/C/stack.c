#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"

#define STACK_CAPACITY_INIT 4
#define _DATATYPE_DEFAULT INT_MIN

#define CHECK_NULL(ptr) \
    do { \
        if ((ptr) == NULL) { \
            fprintf(stderr, "Error: Null pointer at %s:%d\n", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); \
        } \
    } while(0)

#define CHECK_ALLOC(ptr) \
    do { \
        if ((ptr) == NULL) { \
            fprintf(stderr, "Error: Memory allocation failed at %s:%d\n", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); \
        } \
    } while(0)

static void resize_stack(stack *stack_ref) {
    CHECK_NULL(stack_ref);

    stack_ref->capacity += stack_ref->capacity / 2; // Increase by 50%
    _DATATYPE *new_array = NULL;

    new_array = (_DATATYPE *) 
        realloc(stack_ref->array, stack_ref->capacity * sizeof(_DATATYPE));
    
    // Verify memory reallocation
    CHECK_ALLOC(stack_ref->array);

    free(stack_ref->array);
    stack_ref->array = new_array;
}

void create_stack(stack *stack_ref) {
    // Check for a null pointer
    if (stack_ref == NULL) {
        fprintf(stderr, "Error: Null pointer passed to create_stack at %s:%d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // Initialize the stack
    stack_ref->capacity = STACK_CAPACITY_INIT;
    stack_ref->array = (_DATATYPE *) malloc(stack_ref->capacity * sizeof(_DATATYPE));

    // Verify memory allocation
    CHECK_ALLOC(stack_ref->array);

    stack_ref->top_index = -1;
}

void destroy_stack(stack *stack_ref) {
    CHECK_NULL(stack_ref);

    free(stack_ref->array);
    stack_ref->array = NULL;
    stack_ref->capacity = 0;
    stack_ref->top_index = -1;
}

void push(stack *stack_ref, _DATATYPE data) {
    CHECK_NULL(stack_ref);

    if(is_full(stack_ref)) {
        resize_stack(stack_ref);
    }

    // Now insert data at top of stack
    stack_ref->array[stack_ref->top_index + 1] = data;
    stack_ref->top_index++;
}

_DATATYPE pop(stack *stack_ref) {
    CHECK_NULL(stack_ref);

    if(stack_ref->top_index == -1) return _DATATYPE_DEFAULT;

    _DATATYPE temp = front(stack_ref); 
    stack_ref->top_index--;

    return temp;
}

_DATATYPE front(stack *stack_ref) {
    CHECK_NULL(stack_ref);

    if(stack_ref->top_index == -1) return _DATATYPE_DEFAULT;

    return stack_ref->array[stack_ref->top_index];
}

int is_empty(stack *stack_ref) {
    CHECK_NULL(stack_ref);

    if(stack_ref->top_index <= -1) return 1; // Indicate success
    return 0; // Indicate failure
}

int is_full(stack *stack_ref) {
    CHECK_NULL(stack_ref);
    
    // Indicate stack is full
    if(stack_ref->top_index + 1 == stack_ref->capacity) return 1;

    return 0; // Indicate that stack is not full
}

int count_elems(stack *stack_ref) {
    CHECK_NULL(stack_ref);
    return stack_ref->top_index + 1;
}
