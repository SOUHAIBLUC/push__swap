/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_arry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:23 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/06 09:55:24 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_game *game)
{
	int		*arr;
	int		i;
	t_node	*current;

	arr = malloc(sizeof(int) * game->a.size);
	if (!arr)
		return (NULL);
	i = 0;
	current = game->a.head;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indexes(t_game *game, int *arr)
{
	t_node	*current;
	int		i;

	current = game->a.head;
	while (current)
	{
		i = 0;
		while (i < game->a.size)
		{
			if (arr[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
