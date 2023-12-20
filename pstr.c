#include "monty.h"

/**
 * _pstr - Prints the string.
 * @stack: Pointer of the stack.
 * @line_number: line number.
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)(line_number);
	if (!(*stack))
	{
		printf("\n");
		return;
	}
	while (new)
	{
		if (isascii(new->n) && new->n != 0)
			putchar(new->n);
		else
			break;
		new = new->next;
	}
	putchar('\n');
}
