#include "push_swap.h"

void push(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->head == NULL || stack_a->size == 0)
        return;
    t_node *tmp = stack_pop(stack_a);
    stack_push_front(stack_b, tmp);
}

// Push functions
void pa(t_game *game)
{

    push(&game->b, &game->a);
    write(1, "pa\n", 3);
}

void pb(t_game *game)
{

   push(&game->a, &game->b);
    write(1, "pb\n", 3);
}