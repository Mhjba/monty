#include "monty.h"
/**
 * node_add - entry point
 * @stack: head of the stack
 * @line_number: line_number
 * Return: no return
*/
void node_add(stack_t **stack, unsigned int line_number)
{

	stack_t *new;
	stack_t *head = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (head)
		head->prev = new;
	new->n = line_number;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}


/**
 * queue_add - entry point
 * @line_number: line_number
 * @stack: head of the stack
 * Return: no return
*/
void queue_add(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *head = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = line_number;
	new->next = NULL;
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	if (!head)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		head->next = new;
		new->prev = head;
	}
}
