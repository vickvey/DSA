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

- Creates a new stack.

```c
void create_stack(stack *stack_ref)
```

- Destroys the stack, freeing allocated memory.

```c
void destroy_stack(stack *stack_ref)
```

- Pushes an element onto the stack.

```c
void push(stack *stack_ref, _DATATYPE data)
```

- Pops an element from the stack.

```c
_DATATYPE pop(stack *stack_ref)
```

- Returns the element at the top of the stack without removing it.

```c
_DATATYPE front(stack *stack_ref)
```

- Checks if the stack is full.

```c
int is_full(stack *stack_ref)
```

- Returns the number of elements in the stack.

```c
int count_elems(stack *stack_ref)
```

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

## Example 

Here is an example usage of the library: 

- Demo code
```c
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
```

- Compiling and generating executable

```bash
$ gcc main.c stack.c -o main
```

- Running the executable
```bash
$ ./main
```

- Output 
```
The data at top now is : 20!
The data at top now is : 10
The data at top is used and popped : 10!
The data at top now is : -2147483648!
```

## License

This library is licensed under the MIT License - see the LICENSE file for details.
Author: [vickvey](https://github.com/vickvey)
copyright @2023
