#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../inc/stack.h"


// Create stack
// Made by me, inspired by previous assignment and https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/
stack_t* stack_create(void) {
    // allocate memory to the stack
    stack_t* new_stack = malloc(sizeof(stack_t));
    if (new_stack == NULL) {
        printf("stack_create: malloc failed\n");
        return NULL;
    }
    // intialize and return the stack
    new_stack->top = NULL;
    return new_stack;
}


// Add element to the top of stack
// Code is inspired by previous assignment, made by me
int stack_push(stack_t* stack, stack_value* value) {
    if ((stack == NULL) || (value == NULL)) {
        printf("push: Stack or value is NULL\n");
        return -1;
    }

    // allocate memory for new node
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("push: malloc failed for new node\n");
        return -1;
    }

    // Initializing/updating the new node
    new_node->data = value;
    new_node->next = stack->top;
    new_node->prev = NULL;

    if (stack->top != NULL) {
        stack->top->prev = new_node;
    }
    stack->top = new_node;

    return 1;
}



// Remove and return element from the top of stack
// Code is inspired by previous assignment, made my me
stack_value* stack_pop(stack_t* stack) {
    if (stack == NULL) {
        printf("pop: Stack is NULL (not initialized)\n");
        return NULL;
    }

    if (stack_is_empty(stack)) {
        printf("pop: Stack is empty, cannot pop\n");
        return NULL;
    }

    // Retrieve top node and value
    // Update stack and free poped node, return value
    Node* top_node = stack->top;
    stack_value* value = top_node->data;
    stack->top = top_node->next;

    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }

    free(top_node);
    return value;
}



// Return value of the top of stack
// Made by me
stack_value* stack_peek(stack_t* stack) {
    if (stack == NULL) {
        printf("peek: Stack is NULL\n");
        return NULL;
    }
    if (stack->top == NULL) {
        printf("peek: Stack is empty\n");
        return NULL;
    }
    return stack->top->data;
}


// Check if stack is empty
// Made by me
int stack_is_empty(stack_t* stack) {
    if (stack == NULL) {
        printf("is_empty: Stack is NULL (not initialized)\n");
        return 1;
    }
    if (stack->top == NULL) {
        printf("is_empty: Stack is empty (top is NULL)\n");
        return 1;
    }
    return 0;
}



// Push a copy of the top word
// Made by me
int stack_dup(stack_t* stack) {
    if ((stack == NULL) || (stack->top == NULL)) {
        printf("dup: Stack is NULL\n");
        return -1;
    }

    // make a copy of the top value
    stack_value* value = stack_peek(stack);
    if (value == NULL) {
        printf("dup: Stack is empty\n");
        return -1;
    }

    // allocate memory for new value
    stack_value* copy_value = malloc(sizeof(stack_value));
    if (copy_value == NULL) {
        printf("dup: malloc failed\n");
        return -1;
    }
    // Handle date based on value type: int
    if (value->type == VALUE_INT) {
        int* copy_data = malloc(sizeof(int));
        if (copy_data == NULL) {
            printf("dup: copy_data malloc failed\n");
            free(copy_value);
            return -1;
        }
        // Arrange the data, and push to stack
        *copy_data = *(int*)value->data;
        copy_value->type = VALUE_INT;
        copy_value->data = copy_data;

    // Handle date based on value type: string
    } else if (value->type == VALUE_STRING) {
        char* copy_data = strdup((char*)value->data);
        if (copy_data == NULL) {
            printf("dup: copy_data string strdup failed\n");
            free(copy_value);
            return -1;
        }
        // Arrange the data, and push to stack
        copy_value->type = VALUE_STRING;
        copy_value->data = copy_data;

    } else {
        printf("dup: Unknown value type\n");
        free(copy_value);
        return -1;
    }

    // Push the copy to the stack
    if (stack_push(stack, copy_value) == -1) {
        printf("dup: stack_push failed\n");
        free(copy_value->data);
        free(copy_value);
        return -1;
    }

    return 1;
}


// Swaps the two top values
// Made by me
int stack_swap(stack_t* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        printf("swap: Stack is empty or less then two elements\n");
        return -1;
    }
    stack_value* temp = stack->top->data;
    stack->top->data = stack->top->next->data;
    stack->top->next->data = temp;

    return 1;
}

// Destroy the stack, nodes and data
// Made by me, inspired by previous assignment
void stack_destroy(stack_t* stack) {
    if (stack != NULL) {

        Node* current = stack->top;
        Node* next;

        // iterate through the stack, freeing each node and its data
        while (current != NULL) {
            next = current->next;

            if (current->data != NULL) {
                if (current->data->type == VALUE_STRING) {
                    free(current->data->data);
                } else if (current->data->type == VALUE_INT) {
                    free(current->data->data);
                }

                free(current->data);
            }
            free(current);
            current = next;
        }
    }
    free(stack);
}
