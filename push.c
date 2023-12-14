#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 * @value: value
 * Return: no return.
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node;
	(void)(line_number);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack)
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	}
	else
	{
	new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * pall - Prints all the elements, starting from the top of the stack.
 * @stack: Pointer.
 * @line_number: integer.
 * Return: No return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)(line_number);
	while (current != NULL)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}
