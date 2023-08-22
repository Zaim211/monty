#include "monty.h"

/**
 * push - add element on top of stack
 * @stack: pointer to a pointer to the doubly linked list
 * @line_number: line where there is an error
 * @i: op_code
 * Return: void
*/
void push(stack_t **stack, char *i, unsigned int line_number)
{
	stack_t *new = NULL;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (i == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (j = 0; i[j]; j++)
	{
		if (i[0] == '-' && j == 0)
			continue;
		if (i[j] < 48 || i[j] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new->i = atoi(i);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * pall - print stack's elements
 * @line_number: will not be used , we use attribute not void
 * @stack: pointer to the head of the doubly linked list
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
