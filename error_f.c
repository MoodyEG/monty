#include "monty.h"

/**
 * error_f - prints error to stderr
 * @code: error code
 * Return: no return
 */
void error_f(int code, ...)
{
	va_list info;

	va_start(info, code);
	switch (code)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n",
			va_arg(info, char *));
			break;
		case 2:
			fprintf(stderr, "L%d: unknown instruction %s\n",
			va_arg(info, int), va_arg(info, char *));
			break;
		case 3:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
	}
	va_end(info);
	free_stack();
	exit(EXIT_FAILURE);
}
