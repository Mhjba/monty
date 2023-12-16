#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: pointer of the stack
 * @line_number: line number.
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *str;
	stack_t *new;
	int node;

	new = malloc(sizeof(stack_t));
	str = strtok(NULL, "\n\t\r ");
	new = *stack;
	if (str == NULL || check_str(str) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node = atoi(str);
	new->n = node;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * check_str - check if a string is an integer.
 * @str: string.
 * Return: 0.
*/
int check_str(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (-1);
		str++;
	}
	return (0);
}

/**
 * _pall - Prints all the elements of the stack.
 * @stack: Pointer of the stack.
 * @line_number: line_number.
 *
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)line_number;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
