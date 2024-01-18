#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void pchar(stack_t **head, unsigned int ln)
{
	if (*head == NULL || head == NULL)
		error_f2(*head, 15, ln);
	if ((*head)->n < 0 || (*head)->n > 127)
		error_f2(*head, 14, ln);
	printf("%c\n", (*head)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void pstr(stack_t **head, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	if (*head == NULL || head == NULL)
		printf("\n");
	temp = *head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void rotl(stack_t **head, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	*head = (*head)->next;
	((*head)->prev)->next = NULL;
	(*head)->prev = NULL;
}

/**
 * rotr - rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * @head: our list
 * @ln: line number
 * Return: no return
 */
void rotr(stack_t **head, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(temp->prev)->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
