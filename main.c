#include "monty.h"

/**
 * main - Entry point of the Monty program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	char line[MAX_LINE_LENGTH], *opcode, *argument;
	unsigned int line_number = 0;
	FILE *file;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for stack\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	stack->n = 0;
	stack->prev = NULL;
	stack->next = NULL;
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';/*Remove trailing \n char*/
		opcode = strtok(line, " ");
		argument = strtok(NULL, " ");
		if (opcode == NULL) /* Skip blank lines */
			continue;
		instruction.opcode = opcode; /* Find opcode function */
		/* Handle push opcode separately */
		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL || !is_integer(argument))
			{
				fprintf(stderr, "L%u: usage: push integer\n",
						line_number);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			stack->n = atoi(argument);
		}
		instruction.f = get_opcode_function(opcode);
		if (instruction.f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcode);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		instruction.f(&stack, line_number);/*Execute opcode function*/
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
