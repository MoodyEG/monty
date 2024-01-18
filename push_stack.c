#include "monty.h"

/**
 * add_node_stack - adds a new node at the beginning of a stack_t list.
 * @head: our list
 * @n: content of the node to be added
 * Return:  the address of the new element
 */
void add_node_stack(stack_t **head, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_f(*head, 3);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

/**
 * print_stack - prints all the elements of a stack_t list.
 * @head: our list
 * @n: ignored value
 * Return: the number of nodes
 */
void print_stack(stack_t **head, unsigned int n)
{
	stack_t *temp;

	(void)n;
	temp = *head;
	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_stack - frees a stack_t list.
 * @head: head of the list
 * Return: no return
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
