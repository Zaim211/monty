#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: the stack
 * Return: void
 **/
void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

/**
 * len - length of stack
 * @stack: pointer that point to stack
 * Return: unsigned int
 **/
unsigned int len(stack_t **stack)
{
	stack_t *current;
	unsigned int lent = 0;

	current = *stack;
	while (current)
	{
		current = current->next;
		lent++;
	}
	return (lent);
}