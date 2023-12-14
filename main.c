#include "monty.h"

/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
	fprintf(stderr, "Error: Couldn't open file %s\n", argv[1]);
	return (EXIT_FAILURE);
	}

	 execute_opcodes(file);

	fclose(file);

	return (EXIT_SUCCESS);
}
