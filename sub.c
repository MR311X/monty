#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the sub function is called.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = (*stack)->next;

	second_top->n -= top->n;

	*stack = second_top;
	second_top->prev = NULL;

	free(top);
}
