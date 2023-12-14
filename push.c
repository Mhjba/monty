#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 *
 * Return: No return.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int element = 0;

	new = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE); }

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		op_free(*stack);
	}

		new->n = element;
		element = atoi(gb.op);
		new->next = *stack;
		new->prev = NULL;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
}
