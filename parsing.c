#include "push_swap.h"

bool parse_input(char *str, t_game *game)
{
    long    value;
    t_node *new_node;

    int i = 0;
    while (str[i])
    {

        value = ft_atoi(str, &i);

        while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
            i++;

        if (value < INT_MIN || value > INT_MAX)
            return false;
        if (stack_isdup(&game->a, value))
            return false;
        new_node = node_new(value);
        if (!new_node)
            return false;
        stack_push_back(&game->a, new_node);
    }

    return true;
}

bool stack_isdup(t_stack *a, int value)
{
    t_node *current = a->head;

    while (current)
    {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}
