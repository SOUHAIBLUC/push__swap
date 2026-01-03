#include "push_swap.h"

int get_chunk_size(int size)
{
    if (size <= 10)
        return 5;
    if (size <= 100)
        return 13;
    return 30;
}

void push_chunks(t_game *game, int chunk)
{
    int i;

    i = 0;
    while (game->a.head)
    {
        if (game->a.head->index <= i)
        {
            pb(game);
            rb(game);
            i++;
        }
        else if (game->a.head->index <= i + chunk)
        {
            pb(game);
            i++;
        }
        else
            ra(game);
    }
}

int find_max_position(t_game *game)
{
    t_node *current;
    int     max;
    int     pos;
    int     i;

    current = game->b.head;
    max     = current->index;
    pos     = 0;
    i       = 0;

    while (current)
    {
        if (current->index > max)
        {
            max = current->index;
            pos = i;
        }
        current = current->next;
        i++;
    }
    return pos;
}

void push_back_to_a(t_game *game)
{
    int size;
    int pos;
    int half;

    size = game->b.size;
    while (game->b.size > 0)
    {
        pos  = find_max_position(game);
        half = game->b.size / 2;
        if (pos <= half)
        {
            while (pos-- > 0)
                rb(game);
        }
        else
        {
            pos = game->b.size - pos;
            while (pos-- > 0)
                rrb(game);
        }
        pa(game);
    }
}

void push_swap(t_game *game)
{
    int *arr;
    int  chunk;

    if (game->a.size == 2)
        sort_two(game);
    if (game->a.size == 3)
        sort_three(game);
    if (game->a.size == 4)
        sort_four(game);
    if (game->a.size == 5)
        sort_five(game);
    else
    {
        arr = stack_to_array(game);
        if (!arr)
            return;

        sort_array(arr, game->a.size);
        assign_indexes(game, arr);
        free(arr);

        chunk = get_chunk_size(game->a.size);
        push_chunks(game, chunk);
        push_back_to_a(game);
    }
}
