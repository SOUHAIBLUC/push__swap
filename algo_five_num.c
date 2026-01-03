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

void sort_four(t_game *game)
{
    int x;
    int min;
    int max;
    t_node *tmp;

    pb(game);
    sort_three(game);
    x = game->b.head->value;
    min = game->a.head->value;
    max = game->a.head->value;
    tmp = game->a.head;
    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    if (x < min || x > max)
    {
        while (game->a.head->value != min)
            ra(game);
        pa(game);
    }
    else
    {
        while (!(game->a.head->value < x &&
                 game->a.head->next->value > x))
            ra(game);
        pa(game);
    }
}
void sort_five(t_game *game)
{
    int x;
    int min;
    int max;
    t_node *tmp;


    pb(game);
  
    sort_four(game);

  
    x = game->b.head->value;

    min = game->a.head->value;
    max = game->a.head->value;
    tmp = game->a.head;
    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }

    if (x < min || x > max)
    {
        while (game->a.head->value != min)
            ra(game);
        pa(game);
    }
    else
    {
        while (!(game->a.head->value < x &&
                 game->a.head->next->value > x))
            ra(game);
        pa(game);
    }
}
