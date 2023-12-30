# Stack Data Structure Library

This library provides a simple implementation of a stack data structure in C. It includes basic stack operations and error handling.

## Table of Contents

- [Features](#features)
- [Functions](#functions)
- [Usage](#usage)
- [Building](#building)
- [Example](#example)
- [License](#license)

## Features

- Dynamic resizing for variable-size stacks.
- Error handling for null pointers and memory allocation failures.
- Basic stack operations: push, pop, top/front, and more.

## Functions
```c
void create_stack(stack *stack_ref)
```
Creates a new stack.

```c
void destroy_stack(stack *stack_ref)
```
Destroys the stack, freeing allocated memory.

```c
void push(stack *stack_ref, _DATATYPE data)
```
Pushes an element onto the stack.

```c
_DATATYPE pop(stack *stack_ref)
```
Pops an element from the stack.

```c
_DATATYPE front(stack *stack_ref)
```
Returns the element at the top of the stack without removing it.

```c
int is_full(stack *stack_ref)
```
Checks if the stack is full.

```c
int count_elems(stack *stack_ref)
```
Returns the number of elements in the stack.

## Usage

To use this library, include the `stack.h` header file in your C program.

```c
#include "stack.h"
```
Ensure that you have the stack.c file compiled and linked with your program.

## Building

Compile and link the stack.c file along with your program:

```bash
gcc your_program.c stack.c -o your_program
```
