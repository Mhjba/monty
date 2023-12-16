#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line)
{
	stack_t *node = NULL;
	char *arg;

	arg = strtok(NULL, " \n");
	if (arg != NULL && check_str(arg))
	node = *stack;
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", line);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(arg);
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;

	(*stack) = node;
}

/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void)line;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

