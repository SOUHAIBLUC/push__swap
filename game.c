/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:35:47 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 15:40:51 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_game_init(t_game *game, int argc, char **argv)
{
	int	i;

	i = 1;
	stack_init(&game->a);
	stack_init(&game->b);
	while (i < argc)
	{
		if (!parse_input(argv[i], game))
		{
			stack_clear(&game->a);
			stack_clear(&game->b);
			break ;
		}
		i++;
	}
}
