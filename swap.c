 #include "monty.h"
/**
 * swap - swaps the top tow elements of the stack.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 *
 * Return: No return.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		op_free(*stack);
	}

	new = (*stack)->next;
	(*stack)->next = new->next;
	if (new->next)
		new->next->prev = *stack;
	new->next = *stack;
	(*stack) = (*stack)->prev;

}
