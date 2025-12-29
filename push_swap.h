#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *head;
    long   size;
} t_stack;

typedef struct s_game
{
    t_stack a;
    t_stack b;
} t_game;

t_node *node_new(int value);
void stack_push(t_stack *stack, t_node *node);
t_node *stack_pop(t_stack *stack);
void stack_clear(t_stack *stack);

void pa(t_game *game);
void pb(t_game *game);
void sa(t_game *game);
void sb(t_game *game);
void ss(t_game *game);
void ra(t_game *game);
void rb(t_game *game);
void rr(t_game *game);
void rra(t_game *game);
void rrb(t_game *game);
void rrr(t_game *game);

#endif