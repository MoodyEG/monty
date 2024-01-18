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
 * top_print - prints the top element of a stack_t list.
 * @head: our list
 * @ln: line number
 * Return: the number of nodes
 */
void top_print(stack_t **head, unsigned int ln)
{
	if (*head == NULL || head == NULL)
		error_f(*head, 5, ln);
	printf("%d\n", (*head)->n);
}

/**
 * swap_stack -  swaps the top two elements of the stack.
 * @head: head of the list
 * @ln: line number
 * Return: no return
 */
void swap_stack(stack_t **head, unsigned int ln)
{
	int i;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		error_f2(*head, 7, ln);
	i = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = i;
	/* sec = (*head)->next; */
	/* (*head)->next = sec->next; */
	/* (*head)->prev = sec; */
	/* sec->prev = NULL; */
	/* sec->next = *head; */
	/* *head = sec; */

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
