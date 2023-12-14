#include "monty.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: pointer of the stack.
 * @line_number: integer.
 *
 * Return: No return.
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		op_free(*stack);
	}

	printf("%d\n", (*stack)->n);
}
