#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "stack.h"

// Executes an instruction
void execute_instruction(stack_t* stack, char** program, int* pc, int program_length);


// Pops two numbers from the stack and pushes their sum
int op_add(stack_t* stack);

// Pops two numbers from the stack and pushes their difference
int op_sub(stack_t* stack);

// Pops two numbers from the stack and pushes their multiple
int op_mul(stack_t* stack);

// Pops two numbers from the stack and pushes the quotient of the second
// divided by the first.
int op_div(stack_t* stack);

// pops two numbers from the stack and pushes the remainder of the second
// divided by the first.
int op_mod(stack_t* stack);

// pops two numbers from the stack and pushes `1` if they are equal, `0`
// otherwise
int op_equal(stack_t* stack);

// pops two numbers from the stack and pushes `1` if the second one is
// larger than the first one, `0` otherwise
int op_greater(stack_t* stack);

// push a copy of the top word
int op_dup(stack_t* stack);

// swaps the two top values on the stack
void op_swap(stack_t* stack);

// pops two numbers off the stack. if the second number is not `0` the
// program jumps by as many words as the first number indicates.
void op_cjump(stack_t* stack, char** program, int* pc, int program_len);

// pop a word from the stack and print it to terminal
void op_print(stack_t* stack);

// output a newline character to terminal; does not alter the stack.
void op_newline(stack_t* stack);


#endif