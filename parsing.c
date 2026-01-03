#include "push_swap.h"

int parse_input(int argc, char **argv, t_game *game)
{
    int     i;
    long    value;
    t_node *new_node;

    while (argc-- > 1)
    {
        i = 0;
        while (argv[argc][i])
        {
            while (argv[argc][i] == ' ')
                i++;
            if (argv[argc][i] == '\0')
                break;
            value = ft_atoi(&argv[argc][i]);
            if (value < -2147483648 || value > 2147483647)
                return -1;
            if (has_duplicate(&game->a, value))
                return -1;
            new_node = node_new(value);
            if (!new_node)
                return -1;
            stack_push(&game->a, new_node);
        }
    }
    return 0;
}

int has_duplicate(t_stack *a, int value)
{
    t_node *current = a->head;

    while (current)
    {
        if (current->value == value)
            return 1;
        current = current->next;
    }
    return 0;
}
