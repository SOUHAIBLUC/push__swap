#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
# include <stdbool.h>

typedef struct s_node
{
    int             value;
    int             index;
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


long ft_atoi(const char *str, int *i);
bool parse_input(char *argv, t_game *game);

void assign_indexes(t_game *game, int *arr);
void push_swap(t_game *game);
void push_back_to_a(t_game *game);
int find_max_position(t_game *game);
void push_chunks(t_game *game, int chunk);
int get_chunk_size(int size);

t_node *stack_pop(t_stack *stack);
void stack_clear(t_stack *stack);
void stack_push_front(t_stack *stack, t_node *node);
void stack_init(t_stack *stack);
int *stack_to_array(t_game *game);
bool stack_isdup(t_stack *a, int value);
void stack_push_back(t_stack *stack, t_node *node);

int find_min_indix(t_game *game);
void sort_two(t_game *game);
void sort_three(t_game *game);
void sort_four(t_game *game);
void sort_five(t_game *game);
void sort_array(int *arr, int size);

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