#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct my_s - OUR opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct my_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} my_t;

extern stack_t *head;
extern int ln;

/*commands handling*/
void execute_command(char *line,  int line_number, stack_t **head, int *pt);

/*stack handling*/
void add_node_stack(stack_t **head, unsigned int n);
void add_q(stack_t **head, unsigned int n);
void print_stack(stack_t **head, unsigned int n);
void top_print(stack_t **head, unsigned int n);
void pop_stack(stack_t **head, unsigned int ln);
void swap_stack(stack_t **head, unsigned int ln);
int pushit(char *value, stack_t **head, int ln, char *line, int *type);
void free_stack(stack_t *head);

/*maths*/
void add_stack(stack_t **head, unsigned int ln);
void sub_stack(stack_t **head, unsigned int ln);
void div_stack(stack_t **head, unsigned int ln);
void mul_stack(stack_t **head, unsigned int ln);
void mod_stack(stack_t **head, unsigned int ln);

/*strings*/
void pchar(stack_t **head, unsigned int ln);
void pstr(stack_t **head, unsigned int ln);
void rotl(stack_t **head, unsigned int ln);
void rotr(stack_t **head, unsigned int ln);

/*error handling*/
void error_f(stack_t *head, int code, ...);
void error_f2(stack_t *head, int code, ...);

/*other tools*/
int numbercheck(char *input);

#endif /*MONTY_H*/
