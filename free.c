#include "monty.h"
/**
 * free_stack - frees a list.
 * @head: head of list
 * Description: free list
 * Return: Nothing
 */
void free_stack(stack_t **head)
{

	stack_t *temp = NULL;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
}
