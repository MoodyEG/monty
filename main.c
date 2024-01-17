#include "monty.h"
stack_t *head = NULL;
int line_number = 1;
/**
 * main - our interpeter
 * @argc: number of arguments
 * @argv: the arguments
 * Return: 0 on success. 1 on failure
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *text;

	if (argc != 2)
		error_f(0);
	text = fopen(argv[1], "r");
	if (text == NULL)
		error_f(1, argv[1]);
	while (1)
	{
		read = getline(&line, &len, text);
		if (read == -1)
			break;
		execute_command(line, line_number);
		line_number++;
	}
	free_stack();

	return (0);
}
