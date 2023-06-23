#include "monty.h"

/**
 * mul - Multiplies the second element on top of the stack with the top element
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the mul function is called.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = (*stack)->next;

	second_top->n *= top->n;

	*stack = second_top;
	second_top->prev = NULL;

	free(top);
}
