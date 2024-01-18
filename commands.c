#include "monty.h"

/**
 * execute_command - excute commands
 * @line: the full command
 * @ln: line number
 * @head: head of the list
 * @type: push type (queue or stack)
 * Return: no return
 */
void execute_command(char *line, int ln, stack_t **head, int *type)
{
	int i;
	char *a = "\n\t ", *command;
	instruction_t command_lists[] = {
		{"pop", pop_stack}, {"div", div_stack}, {"pstr", pstr}, {"rotl", rotl},
		{"add", add_stack}, {"pall", print_stack}, {"swap", swap_stack},
		{"sub", sub_stack}, {"pint", top_print}, {"mul", mul_stack},
		{"mod", mod_stack}, {"pchar", pchar}, {"rotr", rotr}, {NULL, NULL}};

	command = strtok(line, a);
	if (command == NULL || strcmp(command, "nop") == 0 ||
	command[0] == '#')
		return;
	if (strcmp(command, "push") == 0)
	{
		pushit(strtok(NULL, a), head, ln, line, type);
		return;
	}
	if (strcmp(command, "queue") == 0)
	{
		*type = 2;
		return;
	}
	if (strcmp(command, "stack") == 0)
	{
		*type = 1;
		return;
	}
	for (i = 0; command_lists[i].opcode != NULL; i++)
	{
		if (strcmp(command, command_lists[i].opcode) == 0)
		{
			command_lists[i].f(head, ln);
			return;
		}
	}
	error_f(*head, 2, ln, command);
	free(line);
	exit(EXIT_FAILURE);
}
