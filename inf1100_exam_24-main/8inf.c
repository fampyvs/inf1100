#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/stack.h"
#include "inc/interpreter.h"
#include "inc/lexer_preprocessor.h"

char **program;


/**
 * The main function for the program.
 *
 * This function takes in a file name as an argument and interprets the
 * contents of that file. The program is stored in memory and
 * then executed. The memory for the program is allocated using the
 * `load_program` function and freed with a call to `free_program`.
 */
int main(int argc, char **argv) {


// Cheack if the user provided a file with more then two elements
  if (argc < 2) {
    printf("no program supplied\n");
    return 0;
  }

  // program is an array of strings, the end of the program is signified by a
  // NULL pointer.
  program = load_program(argv[1]);
  if (program == NULL) {
    printf("Failed to load program\n");
    return 1;
  }

  // get the number of instructions or length of the program 
  int program_length = 0;
  while (program[program_length] != NULL) {
    program_length++;
  }

  // create the stack for the program
  stack_t *stack = stack_create();
  if (stack == NULL) {
    printf("Failed to create stack\n");
    return 1;
  }

  // runs the program
  int pc = 0;
  while (pc < program_length) {
    execute_instruction(stack, program, &pc, program_length);
  }

  stack_destroy(stack);

  for (int i = 0; i < program_length; i++) {
    free(program[i]);
  }
  free(program);

  return 0;
}