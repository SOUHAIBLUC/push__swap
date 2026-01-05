#include "push_swap.h"

void sort_two(t_game *game)
{
    if (game->a.head->value > game->a.head->next->value)
        sa(game);
}

void sort_three(t_game *game)
{
    int a = game->a.head->value;
    int b = game->a.head->next->value;
    int c = game->a.head->next->next->value;

    if (a > b && b < c && a < c)
        sa(game);
    else if (a > b && b > c)
    {
        sa(game);
        rra(game);
    }
    else if (a > b && b < c && a > c)
        ra(game);
    else if (a < b && b > c && a < c)
    {
        sa(game);
        ra(game);
    }
    else if (a < b && b > c && a > c)
        rra(game);
}


void sort_five(t_game *game)
{
    int value;

    while (game->a.size > 3)
    {
        value = find_min_indix(game);
        if (value <= game->a.size / 2)
        {
            while (value--)
                ra(game);
        }
        else
        {
            value = game->a.size - value;
            while (value--)
                rra(game);
        }
        pb(game);
    }
    sort_three(game);
    while (game->b.size > 0)
        pa(game);
}

int find_min_indix(t_game *game)
{
    int     save;
    int     indix;
    int     min;
    t_node *tmp;

    indix = 0;
    min   = game->a.head->value;
    tmp   = game->a.head;
    while (tmp)
    {
        if (tmp->value < min)
        {
            min  = tmp->value;
            save = indix;
        }
        indix++;
        tmp = tmp->next;
    }
    return save;
}
