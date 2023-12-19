#include "monty.h"

/**
 * _push - entry point
 * @stack: the stack
 * @line_number: the line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int n;
	int i = 0, flag = 0;

	if (var.mp)
	{
		if (var.mp[0] == '-')
		{
			i++;
		}

		for (; var.mp[i] != '\0'; i++)
		{
			if (var.mp[i] > '9' || var.mp[i] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(var.mp);
	if (var.num == 0)
		node_add(stack, n);
	else
		queue_add(stack, n);
}

/**
 * _pall - entry point
 * @stack: the stack
 * @line_number: line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void)line_number;

	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

