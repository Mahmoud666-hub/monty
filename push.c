#include"monty.h"
/**
 * _push - add new part to stack
 * @stack: parameter
 * @a: number of lines
*/
void _push(stack_t **stack, unsigned int a)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->n = a;
	new->prev = NULL;
	new->next = NULL;

	if ((*stack) == NULL)
	{
		(*stack) = new;
		return;
	}
	else
	{
		new->next = (*stack);
		(*stack) = new;
		return;
	}
}

/**
 * _Pall - print all parts of the stack
 * @stack: parameter
 * @a: number of lines
*/
void _Pall(stack_t **stack, unsigned int a)
{
	stack_t *g = *stack;
	(void)a;
	while (g != NULL)
	{
		printf("%d\n", (g)->n);
		g = (g)->next;
	}
}

/**
 * _strdup - copy string
 * @s: parameter
 * Return: pointer
*/
char *_strdup(const char *s)
{
	int i = 0;
	char *a = NULL;

	if (s != NULL)
	{
		a = malloc(sizeof(strlen(s) + 1));
		if (a == NULL)
		{
			return (NULL);
		}

		while (s[i] != '\0')
		{
			a[i] = s[i];
			i++;
		}
		a[i] = '\0';
	}
	return (a);
}
