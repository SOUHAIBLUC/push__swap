/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:28 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 17:47:40 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long	ft_atoi(const char *str, int *i)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (str[*i] < '0' || str[*i] > '9')
		return (LONG_MAX);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (LONG_MAX);
		(*i)++;
	}
	if (!(str[*i] == '\0' || str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		return (LONG_MAX);
	return (result * sign);
}

int	find_max_position(t_game *game)
{
	t_node	*current;
	int		max;
	int		pos;
	int		i;

	current = game->b.head;
	max = current->index;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	get_next_num(t_stack stack, int index, int chunk)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack.head;
	while (current)
	{
		if (current->index <= index + chunk)
			return (i);
		i++;
		current = current->next;
	}
	return (i);
}

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size < 2)
		return (true);
	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}