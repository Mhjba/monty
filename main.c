#include "monty.h"

head_t var = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	unsigned int i = 0;
	FILE *file;
	size_t len = 0;
	ssize_t element;
	stack_t *stack = NULL;
	char *line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	var.file = file;
	while (element > 0)
	{
		line = NULL;
		element = getline(&line, &len, file);
		i++;
		var.op = line;
		if (element > 0)
		{
			op_fun(line, &stack, i);
		}
		free(line);
	}
	free_stack(stack);
	fclose(file);
return (0);
}

/**
* free_stack - entry point
* @stack: head of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *new;

	new = stack;
	while (stack)
	{
		new = stack->next;
		free(stack);
		stack = new;
	}
}
