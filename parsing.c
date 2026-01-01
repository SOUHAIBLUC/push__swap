#include "push_swap.h"

int is_valid_number(const char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] < '0' || str[i] > '9')
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != '\0' && str[i] != ' ')
        return (0);
    return (1);
}

int parse_input(int argc, char **argv, t_game *game)
{
    int i;
    long value;
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

            
            if (!is_valid_number(&argv[argc][i]))
                return (-1);

            value = ft_atoi(&argv[argc][i]);
            if (value < -2147483648 || value > 2147483647)
                return (-1);
            
            if (has_duplicate(&game->a, (int)value))
                return (-1);

            new_node = node_new((int)value);
            if (!new_node)
                return (-1);
            stack_push(&game->a, new_node);

        
            if (argv[argc][i] == '-' || argv[argc][i] == '+')
                i++;
            while (argv[argc][i] >= '0' && argv[argc][i] <= '9')
                i++;
        }
    }
    return (0);
}

int has_duplicate(t_stack *a, int value)
{
    t_node *current = a->head;

    while (current)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}