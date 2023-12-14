#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 *
 * Return: No return.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
		op_free(*stack);
	}
	new = *stack;
	*stack = new->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(new);
}
