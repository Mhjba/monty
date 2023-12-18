#include "monty.h"

/**
 * push_func - entry point
 * @stack: the stack
 * @line_num: the line number
 */

void push_func(stack_t **stack, unsigned int line_num)
{
	int n;
	int i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		{
			i++;
		}

		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.life_cycle == 0)
		addqueue(stack, n);
}

/**
 * pall_func - entry point
 * @stack: the stack
 * @line_num: line number
 */

void pall_func(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	(void)line_num;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
