#include "monty.h"

/**
 * execute_opcodes - executes a file
 * @file: pointer
 * Return: void
 */

void execute_opcodes(FILE *file)
{
	char opcode[100];
	int value;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	while (fscanf(file, "%99s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
			}
		push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	line_number++;
	}
}
