#include "monty.h"

/**
 * pall - print stack's elements
 * @line_number: will not be used , we usse attribute not void
 * @stack: pointer to the head of the doubly linked list
 * Return: void
*/
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
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
