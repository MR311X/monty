#include "monty.h"

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
