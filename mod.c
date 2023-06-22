#include "monty.h"

void modulus(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *second_top;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    second_top = (*stack)->next;

    if (top->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    second_top->n %= top->n;

    *stack = second_top;
    second_top->prev = NULL;

    free(top);
}
