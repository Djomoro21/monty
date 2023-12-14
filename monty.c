#include "monty.h"

/**
 * push - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 *
 * Description: opcode and its push function
 * for stack, queues, LIFO, FIFO
 */
void push(stack_t **stack, unsigned int line_number)
{
   stack_t *new;
   int number;

   if (line_number == 0)
   {
       fprintf(stderr, "L%d: usage: push integer\n", line_number);
       exit(EXIT_FAILURE);
   }

   number = atoi(line_number);
   new = malloc(sizeof(stack_t));
   if (new == NULL)
   {
       fprintf(stderr, "Error: malloc failed\n");
       exit(EXIT_FAILURE);
   }

   new->n = number;
   new->prev = NULL;
   new->next = *stack;
   if (*stack != NULL)
       (*stack)->prev = new;
   *stack = new;
}
/**
 * pall - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 *
 * Description: opcode and its pall function
 * for stack, queues, LIFO, FIFO
 */
void pall(stack_t **stack, unsigned int line_number)
{
   stack_t *temp = *stack;

   (void)line_number;
   while (temp != NULL)
   {
       printf("%d\n", temp->n);
       temp = temp->next;
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
/**
 * add - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 *
 * Description: opcode and its  function
 * for stack, queues, LIFO, FIFO
 */
void add(stack_t **stack, unsigned int line_number)
{
   int sum;

   if (*stack == NULL || (*stack)->next == NULL)
   {
       fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
       exit(EXIT_FAILURE);
   }

   sum = (*stack)->n + (*stack)->next->n;
   (*stack)->next->n = sum;
   pop(stack, line_number);
}
