#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 *
 * Return: No return.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int new;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		op_free(*stack);
	}

	new = (*stack)->n;
	(*stack)->n += new;
	pop(stack, line_number);
	free(*stack);
}
