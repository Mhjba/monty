#include "monty.h"
/**
* op_fun - executes the opcode
* @stack: head linked list - stack
* @ptr: pointer
* @file: poiner to monty file
* @line_number: line_number
* Return: no return
*/

int op_fun(char *ptr, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *opc;

	instruction_t list_op[] = {
		{"push", _push},
		{"pall", _pall},
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