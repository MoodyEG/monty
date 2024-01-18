#include "monty.h"

/**
 * main - our main interpeter
 * @argc: number of arguments
 * @argv: the arguments
 * Return: 0 on success. 1 on failure
 */
int main(int argc, char **argv)
{
	stack_t *head;
	char *line = NULL;
	int ln = 1;
	size_t len = 0;
	ssize_t read;
	FILE *text;

	head = NULL;
	if (argc != 2)
		error_f(head, 0);
	text = fopen(argv[1], "r");
	if (text == NULL)
		error_f(head, 1, argv[1]);
	while (1)
	{
		read = getline(&line, &len, text);
		if (read == -1)
			break;
		execute_command(line, ln, &head);
		ln++;
	}
	free(line);
	fclose(text);
	free_stack(head);

	return (0);
}
