#include"monty.h"
/**
 * main - monty program
 * @argc: number of arguments
 * @argv: arguments
 * Return: integer
*/
int main(int argc, char *argv[])
{
	stack_t *header = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv[1], header);
	return (0);
}

/**
 * _free - clean heap
 * @s: input string
 * @e: after tok
 * @h: parameter
*/
void _free(char *s, char **e, stack_t *h)
{
	int n = 0;

	stack_t *r;

	r = h;

	if (s != NULL)
	{
		free(s);
	}

	if (e != NULL)
	{
		for (n = 0; e[n] != NULL; n++)
		{
			free(e[n]);
		}

		free(e);
	}

	if (h != NULL)
	{
		while (h != NULL)
		{
		h = h->next;
		free(r);
		r = h;
		}
	}
}
