#include "monty.h"
/**
 * pall - Pfdgdfg dfgdst
 * @stack: Dofdgfdg dfgdgdlist
 * @line_number: Filfdgdfg dfgfdgution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push - Insdfgdg dgdgdflist
 * @stack: Doudfgdg dgfdgist
 * @line_number: Fifdgdfg ddgdgecution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (var.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * pint - Prdfgd dgdgdde
 * @stack: Dodgdgfd dgdfgist
 * @line_number: Figdd dfgdggution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - Degdd gdfgdfgdgst
* @stack: Dogdfgd gdgdgdst
* @line_number: Fgdfgd dgdgdgution
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
