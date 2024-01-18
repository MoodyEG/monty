#include "monty.h"

/**
 * numbercheck - check if the inupt is a  number
 * @input: our input
 * Return: Returns 1 if input is a number, Returns 0 otherwise
 */
int numbercheck(char *input)
{
	int i = 0;

	while (input[i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
