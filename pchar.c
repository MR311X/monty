#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
    int ascii_value;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    ascii_value = (*stack)->n;

    if (ascii_value < 0 || ascii_value > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", ascii_value);
}
