#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "../inc/stack.h"
#include "../inc/interpreter.h"


// Pops two numbers from the stack and pushes their sum
// Made by me
int op_add(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_add: Stack is empty or less then two elements\n");
        return -1;
    }

    // Pops two numbers from the stack, checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_add: second of first is NULL\n");
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_add: second or first is not int\n");
        free(second);
        free(first);
        return -1;
    }
    
    int result = *(int*)first->data + *(int*)second->data;

    // allocate memory for the result
    stack_value* copy_result = malloc(sizeof(stack_value));
    if (copy_result == NULL) {
        printf("Error op_add: Failed to allocate memory for copy_result\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("Error op_add: Failed to allocate memory for result_data\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    // Store the result as an integer, push to stack
    *result_data = result;
    copy_result->data = result_data;
    copy_result->type = VALUE_INT;

    stack_push(stack, copy_result);

    free(first->data);
    free(second->data);
    free(first);
    free(second);
    return 1;
}

// Pops two numbers from the stack and pushes their difference
// Made by me
int op_sub(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_sub: Stack is empty or less then two elements\n");
        return -1;
    }

    // Pops two numbers from the stack, checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_sub: second of first is NULL\n");
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_sub: second or first is not int\n");
        free(second);
        free(first);
        return -1;
    }
    
    int result = *(int*)first->data - *(int*)second->data;

    // allocate memory for the result
    stack_value* copy_result = malloc(sizeof(stack_value));
    if (copy_result == NULL) {
        printf("Error op_sub: Failed to allocate memory for copy_result\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("Error op_sub: Failed to allocate memory for result_data\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    // Store the result as an integer, push to stack
    *result_data = result;
    copy_result->data = result_data;
    copy_result->type = VALUE_INT;

    stack_push(stack, copy_result);
    
    free(first->data);
    free(second->data);
    free(first);
    free(second);
    return 1;
}

// Pops two numbers from the stack and pushes their multiple
// Made by me
int op_mul(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_mul: Stack is empty or less then two elements\n");
        return -1;
    }

    // Pops two numbers from the stack, checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_mul: second of first is NULL\n");
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_mul: second or first is not int\n");
        free(second);
        free(first);
        return -1;
    }
    
    int result = *(int*)first->data * *(int*)second->data;

    // alocate memory for the result
    stack_value* copy_result = malloc(sizeof(stack_value));
    if (copy_result == NULL) {
        printf("Error op_mul: Failed to allocate memory for copy_result\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("Error op_mul: Failed to allocate memory for result_data\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    // Store the result as an integer, push to stack
    *result_data = result;
    copy_result->data = result_data;
    copy_result->type = VALUE_INT;

    stack_push(stack, copy_result);
    
    free(first->data);
    free(second->data);
    free(first);
    free(second);
    return 1;
}

// Pops two numbers from the stack and pushes the quotient of the second
// divided by the first.
// Made by me, cant hande float values, wasn't able to implemnt it
int op_div(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_div: Stack is empty or less then two elements\n");
        return -1;
    }

    // Pops two numbers from the stack, checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_div: second of first is NULL\n");
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_div: second or first is not int\n");
        free(second);
        free(first);
        return -1;
    }

    // Cant divide by 0
    if (second == 0) {
        printf("op_div: Cant divide by 0\n");
        free(first);
        free(second);
        return -1;
    }
    
    int result = *(int*)first->data / *(int*)second->data;

    // allocate memory for the result
    stack_value* copy_result = malloc(sizeof(stack_value));
    if (copy_result == NULL) {
        printf("Error op_div: Failed to allocate memory for copy_result\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("Error op_div: Failed to allocate memory for result_data\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    // Store the result as an integer, push to stack
    *result_data = result;
    copy_result->data = result_data;
    copy_result->type = VALUE_INT;

    stack_push(stack, copy_result);
    
    free(first->data);
    free(second->data);
    free(first);
    free(second);
    return 1;
}

// pops two numbers from the stack and pushes the remainder of the second
// divided by the first.
int op_mod(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_mod: Stack is empty or less then two elements\n");
        return -1;
    }

    // Pops two numbers from the stack, checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_mod: second of first is NULL\n");
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_mod: second or first is not int\n");
        free(second);
        free(first);
        return -1;
    }

    // Cant divide by 0
    if (second == 0) {
        printf("op_mod: Cant divide by 0\n");
        free(first);
        free(second);
        return -1;
    }
    
    int result = *(int*)first->data % *(int*)second->data;

    // allocate memory for the result
    stack_value* copy_result = malloc(sizeof(stack_value));
    if (copy_result == NULL) {
        printf("Error op_mod: Failed to allocate memory for copy_result\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("Error op_mod: Failed to allocate memory for result_data\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    // Store the result as an integer, push to stack
    *result_data = result;
    copy_result->data = result_data;
    copy_result->type = VALUE_INT;

    stack_push(stack, copy_result);
    
    free(first->data);
    free(second->data);
    free(first);
    free(second);
    return 1;
}

// pops two numbers from the stack and pushes `1` if they are equal, `0`
// otherwise
// Made by me
int op_equal(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_equal: Stack is empty or less then two elements\n");
        return -1;
    }

    // Pops two numbers from the stack, checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_equal: second of first is NULL\n");
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_equal: second or first is not int\n");
        free(second);
        free(first);
        return -1;
    }
    
    int result = *(int*)first->data == *(int*)second->data ? 1 : 0;

    // allocate memory for the result
    stack_value* copy_result = malloc(sizeof(stack_value));
    if (copy_result == NULL) {
        printf("Error op_equal: Failed to allocate memory for copy_result\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("Error op_equal: Failed to allocate memory for result_data\n");
        free(first->data);
        free(second->data);
        free(first);
        free(second);
        return -1;
    }

    // Store the result as an integer, push to stack
    *result_data = result;
    copy_result->data = result_data;
    copy_result->type = VALUE_INT;

    stack_push(stack, copy_result);

    free(first->data);
    free(second->data);
    free(first);
    free(second);
    return 1;
}

// pops two numbers from the stack and pushes `1` if the second one is
// larger than the first one, `0` otherwise
// Made by me
int op_greater(stack_t* stack) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("op_greater: Stack is empty or less than two elements\n");
        return -1;
    }

    // pops two numbers from the stack, and checks if they are integers
    stack_value* second = stack_pop(stack);
    stack_value* first = stack_pop(stack);

    if (second == NULL || first == NULL) {
        printf("op_greater: Failed to pop values from stack\n");
        if (second != NULL) {
            free(second->data);
            free(second);
        }
        if (first != NULL) {
            free(first->data);
            free(first);
        }
        return -1;
    }

    if (second->type != VALUE_INT || first->type != VALUE_INT) {
        printf("op_greater: Values must be integers\n");
        free(second->data);
        free(first->data);
        free(second);
        free(first);
        return -1;
    }

    int result = *(int*)first->data > *(int*)second->data ? 1 : 0;

    // allocate memory for the result
    stack_value* result_value = malloc(sizeof(stack_value));
    if (result_value == NULL) {
        printf("op_greater: Failed to allocate memory for result value\n");
        free(second->data);
        free(first->data);
        free(second);
        free(first);
        return -1;
    }

    int* result_data = malloc(sizeof(int));
    if (result_data == NULL) {
        printf("op_greater: Failed to allocate memory for result data\n");
        free(second->data);
        free(first->data);
        free(second);
        free(first);
        free(result_value);
        return -1;
    }

    // Store the result as an integer, and push it onto the stack
    *result_data = result;
    result_value->type = VALUE_INT;
    result_value->data = result_data;

    stack_push(stack, result_value);

    free(second->data);
    free(first->data);
    free(second);
    free(first);

    return 1;
}

// push a copy of the top word
// Made by me
int op_dup(stack_t* stack) {
    stack_dup(stack);
    return 1;
}

// swaps the two top values on the stack
// Made by me
void op_swap(stack_t* stack) {
    stack_swap(stack);
}

// pops two numbers off the stack. if the second number is not `0` the
// program jumps by as many words as the first number indicates.
// Made by me
void op_cjump(stack_t* stack, char** program, int* pc, int program_len) {
    if (stack_is_empty(stack) || stack->top->next == NULL) {
        printf("cjump: Stack is empty or less than two elements\n");
        return;
    }

    // pops jump offset and condition from the stack
    stack_value* jump_value = stack_pop(stack);
    stack_value* condition_value = stack_pop(stack);

    // check if it failed to pop
    if (jump_value == NULL || condition_value == NULL) {
        printf("cjump: Failed to pop values from stack\n");
        if (jump_value != NULL) {
            free(jump_value->data);
            free(jump_value);
        }
        if (condition_value != NULL) {
            free(condition_value->data);
            free(condition_value);
        }
        return;
    }

    // check if the values are integers
    if (jump_value->type != VALUE_INT || condition_value->type != VALUE_INT) {
        printf("cjump: Values must be integers\n");
        free(jump_value->data);
        free(condition_value->data);
        free(jump_value);
        free(condition_value);
        return;
    }

    int condition = *(int*)condition_value->data;
    int jump_offset = *(int*)jump_value->data;

    // handle conditional jump
    // upate program counter based on condition and jump offsett 
    if (condition != 0) {
        // update the program counter based on the jump offset
        *pc += jump_offset;

        // make sure we don't jump past the end of the program or the start, remain within a valid range
        if (*pc < 0) {
            *pc = 0; // 
        } else if (*pc >= program_len) {
            *pc = program_len - 1;
        }
    } else {
        // if the condition is false, do nothing and continue to the next instruction
        (*pc)++;
    }

    free(condition_value->data);
    free(jump_value->data);
    free(condition_value);
    free(jump_value);
}

// pop a word from the stack and print it to terminal
// Made by me
void op_print(stack_t* stack) {
    stack_value* value = stack_pop(stack);
    if (value == NULL) {
        printf("op_print: Stack is empty\n");
        return;
    }
    // makes a check to see if the value is a string or an integer, so it doesnt print garbage
    if (value->type == VALUE_STRING) {
        printf("%s", (char*)value->data);
    } else if (value->type == VALUE_INT) {
        printf("%d", *(int*)value->data);
    } else {
        printf("op_print: Unknown type\n");
    }
    
    free(value->data);
    free(value);
}

// output a newline character to terminal; does not alter the stack.
// Made by me
void op_newline(stack_t* stack) {
    printf("\n");
}

// execute the instruction at the current program counter, and update the program counter
// interprets and executes a single instruction, one at at time.
// Made by me
void execute_instruction(stack_t* stack, char** program, int* pc, int program_len) {

    // we prvent the program counter form exceeding the length of the program, avoidign infinite loops
    if (*pc >= program_len) {
        return;
    }

    char* instruction = program[*pc];

    // handle string instruction if the first character is tilde (~)
    // strdup and strlen from https://stackoverflow.com/questions/14947821/how-do-i-use-strdup
    // and https://stackoverflow.com/questions/252782/strdup-what-does-it-do-in-c
    if (instruction[0] == '~') {
        stack_value* text_value = malloc(sizeof(stack_value));
        if (text_value == NULL) {
            printf("Error: Failed to allocate memory\n");    
            exit(1);
        }
        // duplicates the string starting from the second character
        // (i.e. the tilde is ignored, the rest of the string is duplicated)
        char* text = strdup(&instruction[1]); 
        if (text == NULL) {
            printf("Error: Failed to dublicate string\n");
            free(text_value);
            exit(1);
        }

        // removes the last tilde, replacing it with a null character, so it can be properly printed
        text[strlen(text) - 1] = '\0';

        // set the type and data now so i dont have to check it later or multiple times, push to stack
        text_value->type = VALUE_STRING;
        text_value->data = text;
        stack_push(stack, text_value);

    // handles the dot-prefix instructions
    // insphttps://stackoverflow.com/questions/8004237/how-do-i-properly-compare-strings-in-c
    } else if (instruction[0] == '.') {
        // 
        if (strcmp(instruction, ".+") == 0) {
            op_add(stack);
        } else if (strcmp(instruction, ".-") == 0) {
            op_sub(stack);
        } else if (strcmp(instruction, ".*") == 0) {
            op_mul(stack);
        } else if (strcmp(instruction, "./") == 0) {
            op_div(stack);
        } else if (strcmp(instruction, ".mod") == 0) {
            op_mod(stack);
        } else if (strcmp(instruction, ".=?") == 0) {
            op_equal(stack);
        } else if (strcmp(instruction, ".>?") == 0) {
            op_greater(stack);
        } else if (strcmp(instruction, ".dup") == 0) {
            op_dup(stack);
        } else if (strcmp(instruction, ".swap") == 0) {
            op_swap(stack);
        } else if (strcmp(instruction, ".cjump") == 0) {
            op_cjump(stack, program, pc, program_len);
            return;
        } else if (strcmp(instruction, ".print") == 0) {
            op_print(stack);
        } else if (strcmp(instruction, ".newline") == 0) {
            op_newline(stack);
        } else {
            printf("Unknown operation: %s\n", instruction);
        }

    // Parse and push integer value onto stack
    } else {
        // parse as logn int
        char *endptr;
        long value = strtol(instruction, &endptr, 10);

        // checks if the parsing failed or out of range
        if (*endptr != '\0') {
            printf("Error: '%s' is not a valid integer\n", instruction);
            exit(1);
        }

        // checks if the value given is in range of min and max integers allowed
        if (value < INT_MIN || value > INT_MAX) {
            printf("Error: Value '%ld' is out of range for int\n", value);
            exit(1);
        }

        int *value_ptr = malloc(sizeof(int));
        if (value_ptr == NULL) {
            printf("Error: Failed to allocate memory for integer value\n");
            return;
        }

        // in part allows to push the value onto the stack
        *value_ptr = (int)value;
        stack_value* value_struct = malloc(sizeof(stack_value));
        if (value_struct == NULL) {
            printf("Error: Failed to allocate memory for stack value\n");
            free(value_ptr);
            return;
        }

        // Set the type and data here so i dont have to do it more then once
        // This only applies to integers being interpreted
        value_struct->type = VALUE_INT;
        value_struct->data = value_ptr;

        // push onto stack
        if (stack_push(stack, value_struct) == -1) {
            printf("Error: Failed to push value onto stack\n");
            free(value_struct);
            free(value_ptr);
            return;
        }
    }
    // increment program counter
    (*pc)++;
}
