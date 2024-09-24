#ifndef MONTY_H

#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <stdarg.h>

#define USAGE "USAGE: monty file\n"
#define ERR_OPEN "Error: Can't open file %s\n"
#define INVALID_INST "L%d: unknown instruction %s\n"
#define MALLOC_FAILD "Error: malloc failed\n"
#define ERR_PUSH "L%d: usage: push integer\n"
#define ERR_PINT "L%d: can't pint, stack empty\n"
#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERR_SWAP "L%d: can't swap, stack too short\n"
#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERR_SUB "L%d: can't sub, stack too short\n"
#define ERR_DIV "L%d: can't div, stack too short\n"
#define DIV_ZERO "L%d: division by zero\n"
#define ERR_MUL "L%d: can't mul, stack too short\n"
#define ERR_MOD "L%d: can't mod, stack too short\n"
#define ERR_PCHAR_OUT "L%d: can't pchar, value out of range\n"
#define ERR_PCHAR_EMPTY "L%d: can't pchar, stack empty\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct info_s - Structure to hold significant program information
 * @value: The stored value
 * @monty_file: Pointer to a Monty file
 * @line_content: Content of a line
 * @stack_mode: Flag to switch between stack and queue modes
 *
 * Description:
 * This structure is used to carry significant program information
 * throughout the execution of the Monty program.
 */
typedef struct info_s
{
	char *value;
	FILE *monty_file;
	char *line_content;
	int stack_mode;
} info_t;

info_t *get_info(void);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Execution handler */
void execute(char *, stack_t **, unsigned int);

/* Stack Operations */
void push(stack_t **, unsigned int);
void pall(stack_t **, __attribute__((unused)) unsigned int);
void pint(stack_t **, unsigned int);

void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/* Math Operations */
void __add(stack_t **, unsigned int);
void __sub(stack_t **, unsigned int);
void __div(stack_t **, unsigned int);
void __mul(stack_t **, unsigned int);
void __mod(stack_t **, unsigned int);

/* String hundlers */
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

/* Rotation handlers */
void rotl(stack_t **, __attribute__((unused)) unsigned int);
void rotr(stack_t **, __attribute__((unused)) unsigned int);

/* Queue hanlders */
void queue(stack_t **, unsigned int);
void add_queue(stack_t **, int);

/* Stack handlers */
void stack(stack_t **, unsigned int);
void add_node(stack_t **, int);
void free_stack(stack_t *);

/* Handle Errors */
void p_error(int, ...);

#endif
