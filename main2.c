#include "push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    t_game game;

    // Initialize stacks
    game.a.head = NULL;
    game.a.size = 0;
    game.b.head = NULL;
    game.b.size = 0;

    // Parse input
    if (parse_input(argc, argv, &game) == -1)
    {
        write(2, "Error\n", 6);
        return (1);
    }

    // Optional: print stack A to check correctness
    t_node *tmp = game.a.head;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }

    // Free stack memory here if needed

    return (0);
}
