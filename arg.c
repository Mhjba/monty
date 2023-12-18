#include "monty.h"
/**
* free_stack - entry point
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * addnode - entry point
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
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
 * addqueue - entry point
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
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
