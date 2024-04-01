#include "monty.h"
/**
 * f_sp - this function is to add the top two elements for the stack
 * @head: head of stack
 * @counter: The number of line
 * Return: there is no return
*/
void f_sp (stack_t **head, unsigned int counter)
{
	stack_t *h;

	int len = 0, axa;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
    free_stack(*head);
    free(bus.content);
    fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	h = *head;
  
	axa = h->n;
  
	h->n = h->next->n;
  
	h->next->n = axa;
}
