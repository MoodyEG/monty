#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack.
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void add_stack(stack_t **head, unsigned int ln)
{
	int i;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		error_f2(*head, 8, ln);
	i = (*head)->n;
	i += ((*head)->next)->n;
	pop_stack(head, ln);
	(*head)->n = i;
}

/**
 * sub_stack - subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void sub_stack(stack_t **head, unsigned int ln)
{
	int i;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		error_f2(*head, 9, ln);
	i = ((*head)->next)->n;
	i = i - (*head)->n;
	pop_stack(head, ln);
	(*head)->n = i;
}

/**
 * div_stack - divides the second top element of the
 * stack by the top element of the stack.
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void div_stack(stack_t **head, unsigned int ln)
{
	int i;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		error_f2(*head, 10, ln);
	if ((*head)->n == 0)
		error_f2(*head, 11, ln);
	i = ((*head)->next)->n;
	i = i / (*head)->n;
	pop_stack(head, ln);
	(*head)->n = i;
}
