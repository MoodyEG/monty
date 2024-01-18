#include "monty.h"

/**
 * pop_stack -  deletes the node at top
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void pop_stack(stack_t **head, unsigned int ln)
{
	stack_t *temp, *del;

	if ((*head) == NULL)
		error_f(*head, 6, ln);
	temp = *head;
	del = temp->next;
	free(temp);
	if (del != NULL)
		del->prev = NULL;
	*head = del;
}
