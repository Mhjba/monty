#include "monty.h"
/**
 * node_add - entry point
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void node_add(stack_t **head, int n)
{

	stack_t *new_node;

	stack_t *current = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (current)
		current->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}


/**
 * queue_add - entry point
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void queue_add(stack_t **head, int n)
{
	stack_t *new_node;

	stack_t *current = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}

