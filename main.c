#include "monty.h"

/**
 * free_all - frees a stack_t list.
 * @stack: Pointer of the stack.
 * Return: void.
 */
void free_all(stack_t *stack)
{
	stack_t *head;

	while (stack != NULL)
	{
		head = stack;
		stack = stack->next;
		free(head);
	}
}

/**
 * main - entry point for the monty program
 * @argc: number arguments
 * @argv: array arguments.
 *
 * Return: success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(file);
	free_all(stack);
	return (EXIT_SUCCESS);
}

/**
 * read_file - reads opcodes from a file.
 * @stack: Pointer of the stack.
 * @line_number: line number.
 * @file: poiter to file.
 * Return: void.
 */
void read_file(stack_t **stack, unsigned int line_number, FILE *file)
{

	char *node = NULL;
	size_t len = 0;
	ssize_t read;
	char *line;

	while ((read = getline(&line, &len, file)) != EOF)
	{
		line_number++;

		node = strtok(NULL, " \n\t");
		if (node == NULL || *node == '#')
			continue;
		op_fun(node, stack, line_number);
	}
}
