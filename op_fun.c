#include "monty.h"
/**
 * op_fun - execute the monty instructions.
 * @stack: Pointer of the stack.
 * @line_number: integer.
 * @opcd: charackter.
 */
void op_fun(stack_t **stack, unsigned int line_number, char *opcd)
{
	int i = 0;

	instruction_t list_op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (list_op[i].opcode != NULL)
	{
		if (strcmp(opcd, list_op[i].opcode) == 0)
		{
			list_op[i].f(stack, line_number);
			return;
		}
		i++;
	}
	if (list_op[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcd);
		exit(EXIT_FAILURE);
		op_free((*stack));
	}
}

