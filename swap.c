#include "monty.h"

/**
* swap - swaps the value of the top two elements to the stack
* @stack: pointer that point to stack
* @line_number: line number of instruction
* Return: void
**/
void swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->op;
	(*stack)->op = (*stack)->next->op;
	(*stack)->next->op = x;
}
