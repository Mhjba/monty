#include "monty.h"

head gb;

/**
 * main - Main funtion.
 * @argc: Argc.
 * @argv: Argv.
 * Return: Success or Failure.
 */

int main(int argc, char *argv[])
{
	unsigned int i = 0;
	size_t len;
	stack_t *node = NULL;
	char *num, *line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	gb.opc = fopen(argv[1], "r");
	if (gb.opc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, gb.opc) != -1)
	{
		i++;
		num = strtok(line, " \n\t\r");
		if (num[0] != '#')
			op_fun(&node, i, num);
	}
	op_free(node);
	exit(EXIT_SUCCESS);
}

/**
 *op_free - List free
 * @stack: Pointer.
 * Return: no return.
 */

void op_free(stack_t *stack)
{
	stack_t *new;

	if (stack != NULL)
		while (stack != NULL)
		{
			new = stack;
			stack = stack->next;
			free(new);
		}
}
