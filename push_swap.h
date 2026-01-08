/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:50:42 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 18:51:14 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	long			size;
}					t_stack;

typedef struct s_game
{
	t_stack			a;
	t_stack			b;
}					t_game;

t_node				*node_new(int value);

long				ft_atoi(const char *str, int *i);
bool				parse_input(char *argv, t_game *game);

void				assign_indexes(t_game *game, int *arr);
void				push_swap(t_game *game);
void				push_back_to_a(t_game *game);
int					find_max_position(t_game *game);
void				push_chunks(t_game *game, int chunk);
int					get_chunk_size(int size);

bool				is_sorted(t_stack *stack);
void				ft_game_init(t_game *game, int argc, char **argv);
int					get_next_num(t_stack stack, int index, int chunk);
t_node				*stack_pop(t_stack *stack);
void				stack_clear(t_stack *stack);
void				stack_push_front(t_stack *stack, t_node *node);
void				stack_init(t_stack *stack);
int					*stack_to_array(t_game *game);
bool				stack_isdup(t_stack *a, int value);
void				stack_push_back(t_stack *stack, t_node *node);

int					ft_strcmp(const char *s1, const char *s2);

void				sort_less_six(t_game *game);
int					find_min_indix(t_game *game);
void				sort_two(t_game *game);
void				sort_three(t_game *game);
void				sort_five(t_game *game);
void				sort_array(int *arr, int size);

void				pa(t_game *game, bool print);
void				pb(t_game *game, bool print);
void				sa(t_game *game, bool print);
void				sb(t_game *game, bool print);
void				ss(t_game *game, bool print);
void				ra(t_game *game, bool print);
void				rb(t_game *game, bool print);
void				rr(t_game *game, bool print);
void				rra(t_game *game, bool print);
void				rrb(t_game *game, bool print);
void				rrr(t_game *game, bool print);

#endif
