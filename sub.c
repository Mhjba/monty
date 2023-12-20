#include "monty.h"

/**
 * _sub - subtracts the top two elements of the stack..
 * @stack: pointer of stack
 * @line_number: line number
 * Return: void.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(new);
}
