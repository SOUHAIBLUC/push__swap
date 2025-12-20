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

#endif