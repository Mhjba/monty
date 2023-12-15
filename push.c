#include "monty.h"

/**
 * _push - pushes a node to the top of stack
 * @stack: Pointer of the stack.
 * @line_number: line number
 * Return: void.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
		if (*stack)
		{
			new->next = *stack;
			(*stack)->prev = new;
		}
		else
		{
			new->next = NULL;
		}
	*stack = new;
}

/**
 * _pall - Prints all the elements, starting from the top of the stack.
 * @stack: Pointer of the stack.
 * @line_number: line_number.
 *
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)(line_number);
	while (new != NULL)
	{
		new = new->next;
		printf("%d\n", new->n);
	}
}

