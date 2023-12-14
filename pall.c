#include "monty.h"

/**
 * pall - Prints all the elements, starting from the top of the stack.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 *
 * Return: No return.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void)(line_number);
	while (new != NULL)
	{
		new = new->next;
		printf("%d\n", new->n);
	}
}
