/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:49 by marvin            #+#    #+#             */
/*   Updated: 2026/01/07 18:48:26 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	game_clear(t_game *game)
{
	stack_clear(&game->a);
	stack_clear(&game->b);
}

int	exec_instruction(char *line, t_game *game)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(game, false);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(game, false);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(game, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(game, false);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(game, false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(game, false);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(game, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(game, false);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(game, false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(game, false);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(game, false);
	else
		return (-1);
	return (0);
}

int	read_and_execute(t_game *game)
{
	char	line[10];
	int		size;

	while (true)
	{
		size = read(0, &line, 9);
		if (size == 0)
			break ;
		line[size] = '\0';
		if (exec_instruction(line, game) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (0);
	ft_game_init(&game, argc, argv);
	if (read_and_execute(&game) == -1)
	{
		game_clear(&game);
		return (1);
	}
	if (is_sorted(&game.a) && game.b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	game_clear(&game);
	return (0);
}
