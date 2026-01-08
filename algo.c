/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:17 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 17:50:13 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 10)
		return (5);
	if (size <= 100)
		return (13);
	return (30);
}

void	push_chunks(t_game *game, int chunk)
{
	int	i;

	i = 0;
	while (game->a.head)
	{
		if (game->a.head->index <= i)
		{
			pb(game, true);
			rb(game, true);
			i++;
		}
		else if (game->a.head->index <= i + chunk)
		{
			pb(game, true);
			i++;
		}
		else if (get_next_num(game->a, i, chunk) <= game->a.size / 2)
			ra(game, true);
		else
			rra(game, true);
	}
}

void	sort_less_six(t_game *game)
{
	if (game->a.size == 1)
		return ;
	if (game->a.size == 2)
	{
		sort_two(game);
		return ;
	}
	if (game->a.size == 3)
	{
		sort_three(game);
		return ;
	}
	if (game->a.size <= 5)
	{
		sort_five(game);
		return ;
	}
}

void	push_back_to_a(t_game *game)
{
	int	pos;
	int	half;

	while (game->b.size > 0)
	{
		pos = find_max_position(game);
		half = game->b.size / 2;
		if (pos <= half)
		{
			while (pos-- > 0)
				rb(game, true);
		}
		else
		{
			pos = game->b.size - pos;
			while (pos-- > 0)
				rrb(game, true);
		}
		pa(game, true);
	}
}

void	push_swap(t_game *game)
{
	int	*arr;
	int	chunk;

	if (is_sorted(&game->a))
		return ;
	if (game->a.size <= 5)
		return (sort_less_six(game));
	arr = stack_to_array(game);
	if (!arr)
		return ;
	sort_array(arr, game->a.size);
	assign_indexes(game, arr);
	free(arr);
	chunk = get_chunk_size(game->a.size);
	push_chunks(game, chunk);
	push_back_to_a(game);
}
