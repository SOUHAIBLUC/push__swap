/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:17:19 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 13:04:13 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->head || stack->head->next == NULL)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

void	sa(t_game *game, bool print)
{
	swap(&game->a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_game *game, bool print)
{
	swap(&game->b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_game *game, bool print)
{
	swap(&game->a);
	swap(&game->b);
	if (print)
		write(1, "ss\n", 3);
}
