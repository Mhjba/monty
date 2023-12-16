#include "monty.h"

/**
 * op_fun - executes the opcode
 * @opc: opcode to execute.
 * @stack: Pointer of the stack.
 * @line_number: line number.
 * Return: void.
 */
void op_fun(char *opc, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t line_op[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	for (i = 0; line_op[i].opcode != NULL; i++)
	{
		if (strcmp(opc, line_op[i].opcode) == 0)
		{
			line_op[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
	free(opc);
	exit(EXIT_FAILURE);
}
