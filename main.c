#include "monty.h"

/**
 * free_stack_list - frees a stack_t list.
 * @stack: Pointer of the stack.
 *
 * Return: void.
*/
void free_stack_list(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1], &stack);
	return (EXIT_SUCCESS);
}

/**
 * open_file - opens a file.
 * @file_name: the file name.
 * @stack: Pointer of the stack.
 * Return: void.
*/
void open_file(char *file_name, stack_t **stack)
{
	FILE *file;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	read_file(stack, file);
	fclose(file);
}

/**
 * read_file - reads opcodes from a file.
 * @stack: Pointer of the stack.
 * @file: poiter to file.
 * Return: void.
 */
void read_file(stack_t **stack,  FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *new;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		new = strtok(line, " \n\t");
		if (new == NULL || *new == '#')
		{
			continue;
		}
		op_fun(new, stack, line_number);
		free(new);
	}
	free(line);
}
