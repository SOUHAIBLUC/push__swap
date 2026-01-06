/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:49 by marvin            #+#    #+#             */
/*   Updated: 2026/01/06 21:04:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


bool is_sorted(t_stack *stack)
{
    t_node *current;

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
int exec_instruction(char *line, t_game *game)
{
    if (ft_strcmp(line, "sa\n") == 0)
        sa(game);
    else if (ft_strcmp(line, "sb\n") == 0)
        sb(game);
    else if (ft_strcmp(line, "ss\n") == 0)
        ss(game);
    else if (ft_strcmp(line, "pa\n") == 0)
        pa(game);
    else if (ft_strcmp(line, "pb\n") == 0)
        pb(game);
    else if (ft_strcmp(line, "ra\n") == 0)
        ra(game);
    else if (ft_strcmp(line, "rb\n") == 0)
        rb(game);
    else if (ft_strcmp(line, "rr\n") == 0)
        rr(game);
    else if (ft_strcmp(line, "rra\n") == 0)
        rra(game);
    else if (ft_strcmp(line, "rrb\n") == 0)
        rrb(game);
    else if (ft_strcmp(line, "rrr\n") == 0)
        rrr(game);
    else
        return (-1);
    return (0);
}
int	read_and_execute(t_game *game)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (exec_instruction(line, game) == -1)
		{
			free(line);
			write(2, "Error\n", 6);
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}


int main(int argc, char **argv)
{
    t_game game;

    if (argc < 2)
        return (0);
    stack_init(&game.a);
    stack_init(&game.b);
    for (int i = 1; i < argc; i++)
    {
        if (!parse_input(argv[i], &game))
        {
            write(2, "Error\n", 6);
            stack_clear(&game.a);
            stack_clear(&game.b);
            return (1);
        }
    }

    if (read_and_execute(&game) == -1)
    {
        stack_clear(&game.a);
        stack_clear(&game.b);
        return (1);
    }

    if (is_sorted(&game.a) && game.b.size == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    stack_clear(&game.a);
    stack_clear(&game.b);
    return (0);
}