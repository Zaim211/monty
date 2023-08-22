#include "monty.h"

/**
 * pint - print the int at the top of stack
 *
 * @stack: double pointer th the head
 * @line_number: number of lines
 *
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
