#include "push_swap.h"

int get_chunk_size(int size)
{
    if (size <= 10)
        return (5);
    if (size <= 100)
        return (13);
    return (30);
}

void push_chunks(t_stack *a, t_stack *b, int chunk)
{
    int i;

    i = 0;
    while (a->head)
    {
        if (a->head->index <= i)
        {
            pb(a, b);
            rb(b);
            i++;
        }
        else if (a->head->index <= i + chunk)
        {
            pb(a, b);
            i++;
        }
        else
            ra(a);
    }
}
int find_max_position(t_stack *b)
{
    t_node  *current;
    int     max;
    int     pos;
    int     i;

    current = b->head;
    max = current->index;
    pos = 0;
    i = 0;

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
    return (pos);
}
void push_back_to_a(t_stack *a, t_stack *b)
{
    int size;
    int pos;
    int half;

    size = b->size;
    while (b->size > 0)
    {
        pos = find_max_position(b);
        half = b->size / 2;
        if (pos <= half)
        {
            while (pos-- > 0)
                rb(b);
        }
        else
        {
            pos = b->size - pos;
            while (pos-- > 0)
                rrb(b);
        }
        pa(a, b);
    }
}

void push_swap(t_stack *a, t_stack *b)
{
    int *arr;
    int chunk;

    arr = stack_to_array(a, a->size);
    if (!arr)
        return ;

    sort_array(arr, a->size);
    assign_indexes(a, arr, a->size);
    free(arr);

    chunk = get_chunk_size(a->size);
    push_chunks(a, b, chunk);
    push_back_to_a(a, b);
}
