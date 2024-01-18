#include "monty.h"

/**
 * error_f - prints error to stderr
 * @code: error code
 * @head: the head to free
 * Return: no return
 */
void error_f(stack_t *head, int code, ...)
{
	va_list info;
	int line = 0;
	char *name;

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
			line = va_arg(info, int);
			name = va_arg(info, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, name);
			va_end(info);
			free_stack(head);
			return;
		case 3:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(info, int));
			break;
		case 5:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(info, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(info, int));
			break;
	}
	va_end(info);
	free_stack(head);
	exit(EXIT_FAILURE);
}

/**
 * error_f2 - prints error to stderr
 * @code: error code
 * @head: the head to free
 * Return: no return
 */
void error_f2(stack_t *head, int code, ...)
{
	va_list info;

	va_start(info, code);
	switch (code)
	{
		case 7:
			fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(info, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(info, int));
			break;
		case 9:
			fprintf(stderr, "L%d: can't sub, stack too short\n", va_arg(info, int));
			break;
		case 10:
			fprintf(stderr, "L%d: can't div, stack too short\n", va_arg(info, int));
			break;
		case 11:
			fprintf(stderr, "L%d: division by zero\n", va_arg(info, int));
			break;
		case 12:
			fprintf(stderr, "L%d:  can't mul, stack too short\n", va_arg(info, int));
			break;
		case 13:
			fprintf(stderr, "L%d:  can't mod, stack too short\n", va_arg(info, int));
			break;
		case 14:
			fprintf(stderr, "L%d: can't pchar, value out of range\n",
			va_arg(info, int));
			break;
		case 15:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(info, int));
			break;
	}
	va_end(info);
	free_stack(head);
	exit(EXIT_FAILURE);
}
