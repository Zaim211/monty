#include "monty.h"

/**
 * push - add element on top of stack
 * @stack: pointer to a pointer to the doubly linked list
 * @line_number: line where there is an error
 * @n: op_code
 * Return: void
*/
void push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *new = NULL;
	int j;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (j = 0; n[j]; j++)
	{
		if (n[0] == '-' && j == 0)
			continue;
		if (n[j] < 48 || n[j] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
