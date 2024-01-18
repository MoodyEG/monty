#include "monty.h"

/**
 * pushit - push the value depending on the type
 * @value: the value of the item to be instered
 * @head: head of the list
 * @ln: line number
 * @line: line to be freed
 * @type: push type (queue or stack)
 * Return: no return
 */
int pushit(char *value, stack_t **head, int ln, char *line, int *type)
{
	int neg = 1;

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
	if (*type == 1)
		add_node_stack(head, atoi(value) * neg);
	else if (*type == 2)
		add_q(head, atoi(value) * neg);

	return (0);
}

/**
 * add_q - adds a new node at the end of a stack_t list.
 * @head: our list
 * @n: content of the node to be added
 * Return: no return
 */
void add_q(stack_t **head, unsigned int n)
{
	stack_t *temp, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_f(*head, 3);
	new->n = n;
	new->next = NULL;
	temp = *head;
	if (temp)
	{
		while ((temp)->next)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
}
