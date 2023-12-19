#include "monty.h"
/**
 * _swap - swap top of stack .
 * @stack: pointer to lists for stack
 * @line_number: line_number.
 * Return: void.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *element;
	int new;

	element = *stack;
	if (element == NULL || element->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = element->n;
	element->n = element->next->n;
	element->next->n = new;
}
