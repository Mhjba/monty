#include "monty.h"

/**
 * _pop - removes the top element of the stack.
 * @stack: pointer of the stack.
 * @line_number: line_number.
 * Return: void.
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = *stack;
	*stack = new->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(new);
}
