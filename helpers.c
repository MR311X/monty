#include "monty.h" 

/* Helper function to check if a string is a valid integer */
int is_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    if (*str == '\0')
        return 0;

    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/* Helper function to retrieve the opcode function */
void (*get_opcode_function(char *opcode))(stack_t **stack, unsigned int line_number)
{
    int i;

    instruction_t instructions[] = {
	{"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL}
    };

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
            return instructions[i].f;
    }

    return NULL;
}

/* Helper function to free the stack */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    while (current != NULL)
    {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
}
