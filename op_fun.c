#include "monty.h"
/**
* op_fun -function for the opcode.
* @ptr: pointer.
* @stack: ponter of the stack.
* @line_number: line_number.
* Return: integer.
*/

int op_fun(char *ptr, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *opc;

	instruction_t list_op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}};

	opc = strtok(ptr, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	var.mp = strtok(NULL, " \n\t");
	while (list_op[i].opcode && opc)
	{
		if (strcmp(opc, list_op[i].opcode) == 0)
		{	list_op[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opc && list_op[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
		exit(EXIT_FAILURE); }
	return (1);
}
