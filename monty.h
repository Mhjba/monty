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
 * struct t_data - entry point
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @life_cycle: flag change stack <-> queue
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int life_cycle;
}  bus_t;
extern bus_t bus;


void push_func(stack_t **stack, unsigned int line_num);
void pall_func(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *head);
/*void addnode(stack_t **head, int n);*/
/*void addqueue(stack_t **head, int n);*/
void addnode(stack_t **head, int n);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);

#endif
