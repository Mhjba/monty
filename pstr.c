#include "monty.h"

/**
 * _pstr - Prints the string.
 * @stack: Pointer of the stack.
 * @line_number: line number.
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int ascii;
	stack_t *new;

	(void)(line_number);
	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	new = *stack;
	while (new != NULL)
	{
		ascii = new->n;
		if (ascii <= 0 || ascii > 0)
			break;
		printf("%c", ascii);
		new = new->next;
	}
	printf("\n");
}
