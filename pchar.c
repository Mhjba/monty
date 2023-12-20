#include "monty.h"

/**
 * _pchar - Prints the Ascii value.
 * @stack: Pointer of the stack.
 * @line_number: line_number.
 * Return: void.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int new;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->n;
	if (new < 0 || new > 127)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", new);
}
