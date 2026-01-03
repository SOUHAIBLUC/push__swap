#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

long ft_atoi(const char *str)
{
    int  i      = 0;
    int  sign   = 1;
    long result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (result * sign > 2147483647)
            return LONG_MAX;
        if (result * sign < -2147483648)
            return LONG_MAX;
        i++;
    }
    return (result * sign);
}

void ft_stack_print(t_stack *stack)
{
	t_node *tmp;
	tmp = stack->head;
    while (tmp != NULL)
    {
        printf("%d -> ", tmp->value);
		tmp = tmp->next;
    }
    printf("NULL\n");
}


void ft_game_init(t_game *game, int argc, char **argv)
{

    int i = 1;
    while (i < argc)
    {
		
		if (!parse_input(argc, &argv[i], game))
		{
			write(2, "Error\n", 6);
			stack_clear(&game->a);
			stack_clear(&game->b);
            break;
		}
		
		t_node *node = (ft_atoi(argv[i]));
		stack_push(&game->a, &node);
        i++;
    }
}

int main(int argc, char **argv)
{
	t_game game;
    if (argc < 2)
        return ;
   ft_game_init(&game, argc, argv);
   push_swap(&game);
   ft_stack_print(&game.a);
   
}