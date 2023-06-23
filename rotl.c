#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the rotl function is called.
 * Return: None
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
