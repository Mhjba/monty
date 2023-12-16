#include "monty.h"

global gl = {NULL, NULL, NULL};

/**
 *ultrafree - List free
 * @ptr: Pointer.
 */
void ultrafree(stack_t *ptr)
{
	stack_t *head;

	while (ptr != NULL)
	{
		head = ptr->next;
		free(ptr);
		ptr = head;
	}
	fclose(gl.file);
	free(gl.buff);
}

/**
 * main - Main funtion.
 * @argc: Argc.
 * @argv: Argv.
 * Return: Success or Failure.
 */

int main(int argc, char *argv[])
{
	unsigned int cnt = 0;
	ssize_t chr;
	size_t size = 32;
	char *cmd, *tkn;
	stack_t *head = NULL;

	if (argc != 2)
	{fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gl.file = fopen(argv[1], "r");
	if (!gl.file)
	{fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((chr = getline(&gl.buff, &size, gl.file) != EOF))
	{
		cnt++;
		cmd = strtok(gl.buff, " \n\t\r");
		tkn = strtok(NULL, " \n\t\r");
		gl.num = tkn;
		if (cmd[0] != '#')
			op_cmd(&head, cnt, cmd);
	}
	ultrafree(head);
	exit(EXIT_SUCCESS);
}
