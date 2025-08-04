#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

// Code inspired by https://riptutorial.com/c/example/6564/typedef-enum 
// and https://blog.ryanmartin.me/tagged-unions
typedef enum {
    VALUE_INT,
    VALUE_STRING,
} value_type;

// Made by me, but with some inspiration and explanation from ChatGPT
// See chatlog_1
typedef struct Value {
    value_type type;
    void* data;
} stack_value;


/* Make stack function, push, pop, peek, is_empty, dup, swap, and create.
stack.h is inspired by a previous assignment and https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/ */
typedef struct Node {
    stack_value* data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node* top;
} stack_t;


// Create stack
stack_t* stack_create(void);

// Add element to the top of stack
int stack_push(stack_t* stack, stack_value* value);


// Remove and return element from the top of stack
stack_value* stack_pop(stack_t* stack);


// Return value of the top of stack
stack_value* stack_peek(stack_t* stack);


// Check if stack is empty
int stack_is_empty(stack_t* stack);


// Push a copy of the top word
int stack_dup(stack_t* stack);


// Swaps the two top values
int stack_swap(stack_t* stack);


// Destroys the stack
void stack_destroy(stack_t* stack);

#endif
