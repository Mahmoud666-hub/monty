#include"monty.h"
/**
 *  _open - open file and read
 * @s: parameter
 * @h: parameter
*/
void _open(char *s, stack_t *h)
{
	FILE *p;
	char **e = NULL;
	char m[100];
	int i = 0, r = 1, a = 0;

	p = fopen(s, "r");
	if (!p)
	{
		fprintf(stderr, "Error: Can't open file %s\n", s);
		exit(EXIT_FAILURE);
	}

	fread(m, 100, 1, p);
   /*printf("%s",m);*/
	fclose(p);
	while (m[i] != '\0')
	{
		if (m[i] == '\n')
		{
			r = 1;
		}
		else
		{
			a = a + r;
			r = 0;
		}
		i++;
	}
	/*printf("\n%d\n", a);*/
	if (a != 0)
	{
	e = tok(m, a, "\n");
	func(e, a, &h);
	_free(NULL, e, h);
	e = NULL;
	}
}




/**********************/



/**
 * tok - tokanize file in to lines
 * @m: parameter
 * @a: number of lines
 * @delim: parameter
 * Return: pointer
*/
char **tok(char m[], int a, char *delim)
{
	char *u = NULL;
	char **e = NULL;
	int i = 0;

	e = malloc((a + 2) * sizeof(char *));
	i = 0;
	u = strtok(m, delim);

	while (u != NULL)
	{
		e[i] = _strdup(u);
		u = NULL;
		i++;
		u = strtok(NULL, delim);
	}
	e[i] = NULL;

	return (e);
}


/***********************************/

/**
 * func - find suitable function
 * @e: parameter
 * @a: number of lines
 * @h: parameter
*/
void func(char **e, int a, stack_t **h)
{
	char *u = NULL;
	int g = 0, i = 0;
	instruction_t arr_fun[] = {{"push", _push}, {"pall", _Pall}};
	(void)a;

			while (e[i] != NULL)
	{
				if ((e[i])[strlen(e[i]) - 1] == '$')
					(e[i])[strlen(e[i]) - 1] = '\0';

			u = strtok(e[i], " ");
		if ((strcmp(u, arr_fun[0].opcode)) == 0)
		{
			u = strtok(NULL, " ");
			if (u == NULL)
			{
				_free(NULL, e, NULL);
				fprintf(stderr, "L%d: usage: push integer\n", (i + 1));
				exit(EXIT_FAILURE);
			}
			g = _atoi(u);
			if (g == -1241)
			{
				_free(NULL, e, NULL);
				fprintf(stderr, "L%d: usage: push integer\n", (i + 1));
				exit(EXIT_FAILURE);
			}
		 _push(h, g);
		}
		else if ((strcmp(u, arr_fun[1].opcode)) == 0)
		{
			_Pall(h, 0);
		}
		else
		{
			printf("error\n");
		}
	i++;
	}

}


/**
 * _atoi - convert string to integer.
 * @w: parameter
 * Return: integer
*/
int _atoi(char *w)
{
	int q = 0, i = 0, e = 0;
	int a = 1;

	while (w[i] != '\0')
	{
		if (w[i] > '9')
		{
			return (-1241);
		}
		else if (w[i] < '0')
		{
			return (-1241);
		}
		i++;
		e++;
		if (e != 1)
		{
			a *= 10;
		}
	}
	i = 0;

	if (e != 0)
	{
	while (e != 0)
	{
	if (e == 1)
	{
		q = q + (w[i] - '0');
		return (q);
	}
	else
	q = q + ((w[i] - '0') * a);
	a /= 10;
	i++;
	e--;
	}
	}
	return (q);
}
