#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "cvector.h"

#ifndef DEFAULT_SIZE_OF_VECTOR_ARRAY
    #define DEFAULT_SIZE_OF_VECTOR_ARRAY 4
#endif // DEFAULT_SIZE_OF_VECTOR_ARRAY

#ifndef DEFAULT_VALUE_OF_DATATYPE 
    #define DEFAULT_VALUE_OF_DATATYPE 0
#endif // DEFAULT_VALUE_OF_DATATYPE

#ifndef RESIZING_FACTOR_OF_VECTOR
    #define RESIZING_FACTOR_OF_VECTOR (double)0.5
#endif // RESIZING_FACTOR_OF_VECTOR

static void vector_resize_increase(vector *vector_ref) {
    assert(vector_ref != NULL);

    // Calculate the new_capacity (using resizing factor)
    int new_capacity = (int)((double)vector_ref->capacity * (1.0 + RESIZING_FACTOR_OF_VECTOR));

    // Resize the array and store it in new array
    _DATATYPE *new_array = realloc(vector_ref->arr, new_capacity * sizeof(_DATATYPE));
    
    // Checking the memory allocation succeeded or not
    assert(new_array != NULL);
        vector_ref->arr = new_array;

    // Update the capacity
    vector_ref->capacity = new_capacity;
}

// Note : Shrinking of the vector by 50 percent
static void vector_resize_decrease(vector *vector_ref) {
    assert(vector_ref != NULL);

    if (vector_ref->size < vector_ref->capacity / 2) {
        int new_capacity = vector_ref->capacity / 2;

        // Ensure that the new size is at least the minimum size (e.g., 1)
        new_capacity = new_capacity > 0 ? new_capacity : 1;

        _DATATYPE *new_array = realloc(vector_ref->arr, new_capacity * sizeof(_DATATYPE));

        // Check for reallocation success
        assert(new_array != NULL);
            vector_ref->arr = new_array;
            vector_ref->capacity = new_capacity;
    }
}

void vector_initialize(vector *vector_ref) {
    assert(vector_ref != NULL);

    vector_ref->capacity = DEFAULT_SIZE_OF_VECTOR_ARRAY;
    vector_ref->size = 0;

    vector_ref->arr = (_DATATYPE *) malloc(vector_ref->capacity * sizeof(_DATATYPE));
    assert(vector_ref->arr != NULL);

    // assigning them all to a default value
    for(int i = 0; i<DEFAULT_SIZE_OF_VECTOR_ARRAY; i++) {
        vector_ref->arr[i] = DEFAULT_VALUE_OF_DATATYPE;
    }    
}

void vector_destroy(vector *vector_ref) {
    assert(vector_ref != NULL);

    if(vector_ref->arr != NULL) free(vector_ref->arr);
    vector_ref->size = 0;
    vector_ref->capacity = 0;
}

void vector_push_back(vector *vector_ref, _DATATYPE data) {
    assert(vector_ref != NULL && vector_ref->arr != NULL);

    if(vector_ref->size == vector_ref->capacity) vector_resize_increase(vector_ref);

    vector_ref->arr[vector_ref->size - 1] = data;
    vector_ref->size++;
}

void vector_pop_back(vector *vector_ref) {
    assert(vector_ref != NULL && vector_ref->arr != NULL);

    if (vector_ref->size > 0) {
        vector_ref->size--;

        if (vector_ref->size < vector_ref->capacity / 2) {
            // Shrink the vector
            vector_resize_decrease(vector_ref);
        }
    }
}

// Here returning a copy of data not const pointer return (TODO: for future)
_DATATYPE vector_get_element(const vector *vector_ref, size_t index) {
    assert(vector_ref != NULL);
    assert(0 <= index && index < (size_t)vector_ref->capacity);

    return vector_ref->arr[index];
}

void vector_set_element(vector *vector_ref, size_t index, _DATATYPE data) {
    assert(vector_ref != NULL);
    assert(0 <= index && index < (size_t)vector_ref->capacity);

    vector_ref->arr[index] = data;
}