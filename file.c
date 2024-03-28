#include"monty.h"
stack_t *header = NULL;
/***/
void _open(char *s)
{
    FILE *p;
    char **e = NULL;
    size_t t = 0;
    char m[120];
    int i = 0, r = 1, a = 0;
    p = fopen(s, "r");
    if (!p)
    {
        fprintf(stderr, "Error: Can't open file %s\n", s);
        exit(EXIT_FAILURE);
    }
    
    t = fread(m, 120, 1, p);

   // printf("%s",m);
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
    //printf("\n%d\n", a);
    if (a != 0)
    {
    e = tok(m, a, "\n");
    func(e, NULL, a);
    }
}




/**********************/




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
        e[i] = strdup(u);
        i++;
        u = strtok(NULL, delim);
    }
    e [i] = NULL;

    /*i = 0;
    while (e[i] != NULL)
    {
        printf("1----(%s\n", e[i]);
        i++;
    }*/
    
    return (e);
}




/***********************************/

void func(char**e, char m[], int a)
{
    char *u = NULL;
    stack_t *stack = NULL;
    int g = 0, i = 0;
    instruction_t arr_fun[] = {{"push", _push},{"pall", _Pall}};

    while (e[i] != NULL)
    {
        if ((e[i])[strlen(e[i]) - 1] == '$')
            {
                (e[i])[strlen(e[i]) - 1] = '\0';
            }

            u = strtok(e[i], " ");

            //printf("{%d}--u--- (%s)\n", i, u);

        if ((strcmp(u, arr_fun[0].opcode)) == 0)
        {
            u = strtok(NULL, " ");
            if (u == NULL)
            {
                fprintf(stderr, "L<line_number>: usage: push integer\n");

                exit(EXIT_FAILURE);
            }

            //printf("v---{%s}\n", u);
            {
            g = _atoi(u);
            if (g == -1241)
            {
                printf("v-,--{%s}\n", u);
                fprintf(stderr, "L<line_number>: usage: push integer\n");
                exit(EXIT_FAILURE);
            }
            
            //printf("{%d}\n", g);

            _push(&header, g);
            }

        }
        else if ((strcmp(u, arr_fun[1].opcode)) == 0)
        {

            _Pall(&header, 0);

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
 * @h: parameter
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

/*int main(int ac, char **av)
{
    char *m = NULL;
    _open(av[1]);

    return (0);
}*/