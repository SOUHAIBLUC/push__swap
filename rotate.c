#include "push_swap.h"

void reve_stack(t_stack *stack)
{

    if (stack == NULL || stack->head == NULL || stack->head->next == NULL)
        return;
    t_node *first   = stack->head;
    stack->head     = first->next;
    t_node *current = stack->head;
    while (current->next)
        current = current->next;
    current->next = first;
    first->next   = NULL;
}

// Rotate functions
void ra(t_game *game)
{
    reve_stack(&game->a);
    write(1, "ra\n", 3);
}

void rb(t_game *game)
{
    reve_stack(&game->b);
    write(1, "rb\n", 3);
}

void rr(t_game *game)
{
    reve_stack(&game->a);
    reve_stack(&game->b);
    write(1, "rr\n", 3);
}
