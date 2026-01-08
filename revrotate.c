/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:50 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 13:06:51 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rev_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	if (stack == NULL || stack->head == NULL || stack->head->next == NULL)
		return ;
	current = stack->head;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->head;
	stack->head = current;
}

void	rra(t_game *game, bool print)
{
	stack_rev_rotate(&game->a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_game *game, bool print)
{
	stack_rev_rotate(&game->b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_game *game, bool print)
{
	stack_rev_rotate(&game->a);
	stack_rev_rotate(&game->b);
	if (print)
		write(1, "rrr\n", 4);
}
