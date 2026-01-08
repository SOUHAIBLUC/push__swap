/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:39 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/06 09:55:40 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->head = 0;
	stack->size = 0;
}

bool	parse_input(char *str, t_game *game)
{
	long	value;
	t_node	*new_node;
	int		i;

	i = 0;
	while (str[i])
	{
		value = ft_atoi(str, &i);
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (value < INT_MIN || value > INT_MAX)
			return (false);
		if (stack_isdup(&game->a, value))
			return (false);
		new_node = node_new(value);
		if (!new_node)
			return (false);
		stack_push_back(&game->a, new_node);
	}
	return (true);
}

bool	stack_isdup(t_stack *a, int value)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		if (current->value == value)
			return (true);
		current = current->next;
	}
	return (false);
}
