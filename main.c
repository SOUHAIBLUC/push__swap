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
t_node *find_min_from(t_node *start)
{
    t_node *min_node = start;
    t_node *current = start->next;
    
    while (current != NULL)
    {
        if (current->value < min_node->value)
            min_node = current;
        current = current->next;
    }
    return min_node;
}
void algorithm(t_stack *stack)
{
    t_node *tmp;
    tmp = stack->head;
    while (tmp != NULL)
    {
        t_node *min_node = find_min_from(tmp);
        if (min_node != tmp)
        {
            int helper = tmp->value;
            tmp->value = min_node->value;
            min_node->value = helper;
        }
        
        tmp = tmp->next;
    }
    

}


void ft_game_init(t_game *game, int argc, char **argv)
{
	if (argc < 2)
        return ;
    int i = 1;
    while (i < argc)
    {
		long check;
		check = ft_atoi(argv[i]);
		if (check == LONG_MAX)
		{
			write(2, "Error\n", 6);
			stack_clear(&game->a);
			stack_clear(&game->b);
		}
		
		t_node *node = (ft_atoi(argv[i]));
		stack_push(&game->a, &node);
        i++;
    }
}

int main(int argc, char **argv)
{
	t_game game;
   ft_game_init(&game, argc, argv);
   algorithm(&game.a);
   ft_stack_print(&game.a);
   
}