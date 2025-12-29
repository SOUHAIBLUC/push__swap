#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_list
{
    int *t_list_a;
    int *t_list_b;
    int size_a;
    int size_b;
    int capacity_a;
    int capacity_b;
} t_list;

void    push(t_node **list, int value);
int     pop(t_node **list);
t_node  *create_node(int value);
void    free_list(t_node **list);

// Move functions
void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

#endif