#include "monty.h"

/**
 * pstr - Prints the string contained in the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the pstr function is called (unused).
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current != NULL && current->n != 0 && current->n >= 0 &&
			current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
