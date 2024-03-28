#include"monty.h"
/**
 * _push - 
*/
void _push(stack_t **stack, unsigned int a)
{
    int d = 0;
    stack_t *new = NULL;
    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->n = a;
    new->prev = NULL;
    new->next = NULL;

    if (header == NULL)
    {
        header = new;
        return;
    }
    else
    {
        new->next = header;
        header = new;
        return;
    }
    
}

/***/
void _Pall(stack_t **stack, unsigned int a)
{
    (void)a;
    /*if (*stack != NULL)
    {
    printf("%d", (*stack)->n);
    }
    else
    printf("sorry\n");*/

    while ((*stack) != NULL)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }
}
