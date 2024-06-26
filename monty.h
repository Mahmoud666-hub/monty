#ifndef MONTY_H
#define MONTY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

/*extern stack_t *header;*/

void _open(char *s, stack_t *h);
char **tok(char m[], int a, char *delim);
void _push(stack_t **stack, unsigned int a);
void _Pall(stack_t **stack, unsigned int a);
void func(char **e, int a, stack_t **h);
int _atoi(char *w);
char *_strdup(const char *s);
void _free(char *s, char **e, stack_t *h);

#endif
