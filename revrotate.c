#include "push_swap.h"

void stack_rev_rotate(t_stack *stack)
{
    if (stack == NULL || stack->head == NULL)
        return;
    t_node *current = stack->head;
    t_node *prev = NULL;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = stack->head;
    stack->head = current;
}

void rra(t_game *game)
{
    stack_rev_rotate(&game->a);
    write(1, "rra\n", 4);
}

void rrb(t_game *game)
{
    stack_rev_rotate(&game->b);
    write(1, "rrb\n", 4);
}

void rrr(t_game *game)
{
    stack_rev_rotate(&game->a);
    stack_rev_rotate(&game->b);
    write(1, "rrr\n", 4);
}