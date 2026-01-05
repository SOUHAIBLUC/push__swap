#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void ft_stack_print(char *str, t_stack *stack)
{

    t_node *tmp;
    printf("%s : ", str);
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
    stack_init(&game->a);
    stack_init(&game->b);
    while (i < argc)
    {

        if (!parse_input(argv[i], game))
        {
            stack_clear(&game->a);
            stack_clear(&game->b);
            break;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_game game;
    if (argc < 2)
        return 0;
    ft_game_init(&game, argc, argv);
    if (game.a.head == NULL)
    {
        write(1, "Error\n", 6);
        return 0;
    }

    push_swap(&game);

    return 0;
}