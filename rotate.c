/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:53 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 13:06:29 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reve_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*current;

	if (stack == NULL || stack->head == NULL || stack->head->next == NULL)
		return ;
	first = stack->head;
	stack->head = first->next;
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

// Rotate functions
void	ra(t_game *game, bool print)
{
	reve_stack(&game->a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_game *game, bool print)
{
	reve_stack(&game->b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_game *game, bool print)
{
	reve_stack(&game->a);
	reve_stack(&game->b);
	if (print)
		write(1, "rr\n", 3);
}
