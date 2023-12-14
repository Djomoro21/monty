#include "monty.h"

/**
 * push - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 *
 * Description: opcode and its push function
 * for stack, queues, LIFO, FIFO
 */
void push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
 * pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * pint - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 *
 * Description: opcode and its pint function
 * for stack, queues, LIFO, FIFO
 */
void pint(stack_t **stack, unsigned int line_number)
{
  if (*stack == NULL)
  {
      fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
  }
  printf("%d\n", (*stack)->n);
}
/**
 * pop - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 *
 * Description: opcode and its pop function
 * for stack, queues, LIFO, FIFO
 */
void pop(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (*stack == NULL)
  {
      fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
  }
  temp = *stack;
  *stack = (*stack)->next;
  if (*stack != NULL)
      (*stack)->prev = NULL;
  free(temp);
}
