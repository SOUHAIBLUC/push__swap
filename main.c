/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:55:35 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 17:10:04 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void	ft_stack_print(char *str, t_stack *stack)
{
	t_node	*tmp;

	printf("%s : ", str);
	tmp = stack->head;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (0);
	ft_game_init(&game, argc, argv);
	if (game.a.head == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	push_swap(&game);
	stack_clear(&game.a);
	stack_clear(&game.b);
	return (0);
}
