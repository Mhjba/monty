#include "monty.h"

/**
 * _push - function that pushes an element to the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 * Return: No return.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *opcode;
	int num;

	if (!element)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(NULL, "\n\t\r ");
	if (opcode == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(opcode);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}
/**
 * _pall - function that print all values on the stack from the top.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * If the stack is empty, don’t print anything.
 *
 * Return: No return.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	(void)(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}
