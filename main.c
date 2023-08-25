#include "monty.h"

/**
* main - main function
* @argc: number of command line arguments
* @argv: list of command line arguments
* Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
**/
int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *mf;
	char *buff = NULL, *opcode, *n;
	size_t size = 0;
	int line_number = 0;
	stack_t *stack = NULL, *current;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	mf = fopen(argv[1], "r");
	if (mf == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(1);
	}
	while ((getline(&buff, &size, mf)) != -1)
	{
		line_number++;
		opcode = strtok(buff, DELIMITER);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIMITER);
			push(&stack, n, line_number);
		}
		else
			find_opcode(&stack, opcode, line_number);
	}
	fclose(mf);
	free(buff);
	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	return (0);
}
