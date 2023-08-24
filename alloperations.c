#include "monty.h"

/**
 * operation_push - add element on top of stack
 * @stack: pointer to a pointer to the doubly linked list
 * @line_number: line where there is an error
 * @n: op_code
 * Return: void
*/
void operation_push(stack_t **stack, char *n, unsigned int line_number)
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
/**
 * operation_pall - print stack's elements
 * @line_number: will not be used , we usse attribute not void
 * @stack: pointer to the head of the doubly linked list
 * Return: void
*/
void operation_pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
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

/**
 * nop - do nothing
 * @stack: pointer to pointer to the doubly linked list
 * @line_number: number of lines in the file
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pint - print the int at the top of stack
 * @stack: double pointer th the head
 * @line_number: number of lines
 * Return: void
*/
void pint(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the last inserted element
 * @line_number: number of lines  in the file
 * @stack: pointer to the pointer to the head
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *to_the_end;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		to_the_end = *stack;
		*stack = (*stack)->next;
		free(to_the_end);
	}
}
