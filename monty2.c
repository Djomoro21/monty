#include "monty.h"

/**
 * swap - Degfrfe gdfgdfgd gfst
 * @stack: Dodfdfvd gbfbd gdfgdst
 * @line_number: Fifdf gfdg fgdgdgtion
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - add gegeg gfer gfdfgdstack
 * @stack: Dodfgdfg gdfgd fbdfgdst
 * @line_number: Fidgdf gfdgfgd gfdfgtion
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}


