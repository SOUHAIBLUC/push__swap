/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:13 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 17:41:34 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_game *game)
{
	if (game->a.head->value > game->a.head->next->value)
		sa(game, true);
}

void	sort_three(t_game *game)
{
	int	a;
	int	b;
	int	c;

	a = game->a.head->value;
	b = game->a.head->next->value;
	c = game->a.head->next->next->value;
	if (a > b && b < c && a < c)
		sa(game, true);
	else if (a > b && b > c)
	{
		sa(game, true);
		rra(game, true);
	}
	else if (a > b && b < c && a > c)
		ra(game, true);
	else if (a < b && b > c && a < c)
	{
		sa(game, true);
		ra(game, true);
	}
	else if (a < b && b > c && a > c)
		rra(game, true);
}
void	five_sort(t_game *game)
{
	int	value;

	while (game->a.size > 3)
	{
		value = find_min_indix(game);
		if (value <= game->a.size / 2)
		{
			while (value)
			{
				ra(game, true);
				value--;
			}
		}
		else
		{
			value = game->a.size - value;
			while (value)
			{
				rra(game, true);
				value--;
			}
		}
		pb(game, true);
	}
}

void	sort_five(t_game *game)
{
	five_sort(game);
	sort_three(game);
	while (game->b.size > 0)
		pa(game, true);
}

int	find_min_indix(t_game *game)
{
	int		save;
	int		indix;
	int		min;
	t_node	*tmp;

	save = 0;
	indix = 0;
	min = game->a.head->value;
	tmp = game->a.head;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			save = indix;
		}
		indix++;
		tmp = tmp->next;
	}
	return (save);
}
