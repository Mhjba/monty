#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * @arg: arguments
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line, char *arg)
{
	stack_t *node = NULL;

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
	/*printf("haciendo pall:%d\n", line);*/
}
