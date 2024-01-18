#include "monty.h"

/**
 * execute_command - excute commands
 * @line: the full command
 * @ln: line number
 * @head: head of the list
 * Return: no return
 */
void execute_command(char *line, int ln, stack_t **head)
{
	int i, neg = 1;
	char *a = "\n\t ", *value, *command;
	instruction_t command_lists[] = {
		{"push", add_node_stack}, {"pall", print_stack}, {"pint", top_print},
		{"pop", pop_stack}, {"swap", swap_stack}, {"add", add_stack},
		{"sub", sub_stack}, {"div", div_stack}, {NULL, NULL}
	};

	command = strtok(line, a);
	if (command == NULL || strcmp(command, "nop") == 0)
		return;
	if (strcmp(command, "push") == 0)
	{
		value = strtok(NULL, a);
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			neg = -1;
		}
		if (value == NULL || numbercheck(value) == 0)
		{
			free(line);
			error_f(*head, 4, ln);
		}
		add_node_stack(head, atoi(value) * neg);
		return;
	}
	for (i = 1; command_lists[i].opcode != NULL; i++)
	{
		if (strcmp(command, command_lists[i].opcode) == 0)
		{
			command_lists[i].f(head, ln);
			return;
		}
	}
	free(line);
	error_f(*head, 2, ln, command);
}
