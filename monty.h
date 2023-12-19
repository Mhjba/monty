#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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

/**
 * struct head_t - opcode and the function.
 * @file: the opcode.
 * @op: value.
 * @mp: ponter.
 * @num: function to handle the opcode.
 */
typedef struct head_t
{
	FILE *file;
	char *op;
	char *mp;
	int num;
}  head_t;
extern head_t var;


void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void node_add(stack_t **stack, unsigned int line_number);
void queue_add(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
int op_fun(char *ptr, stack_t **stack, unsigned int line_number);


#endif

