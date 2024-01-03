/**
 * @file cvector.h
 * @details This is a simple dynamic array implementation in C.
 * @date 03/01/2024
 * @author vickvey (https://github.com/vickvey) 
 */

#ifndef CVECTOR_H_
#define CVECTOR_H_

typedef struct vector vector;

#ifndef _DATATYPE
    #define _DATATYPE int 
#endif // _DATATYPE

struct vector {
    int capacity;
    int size;
    _DATATYPE *arr;
};

void vector_initialize(vector *vector_ref);
void vector_destroy(vector *vector_ref);

void vector_push_back(vector *vector_ref, _DATATYPE data);
void vector_pop_back(vector *vector_ref);

// Here returning a copy of data not const pointer return (TODO: for future)
_DATATYPE vector_get_element(const vector *vector_ref, size_t index);
void vector_set_element(vector *vector_ref, size_t index, _DATATYPE data);

#endif // CVECTOR_H_