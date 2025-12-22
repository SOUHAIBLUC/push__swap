#include "push_swap.h"

t_node *create_node(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}
void push(t_node **list, int value)
{
    t_node *new_node = create_node(value);
    if (!new_node)
        return;
    new_node->next = *list;
    *list = new_node;
}
int pop(t_node **list)
{
    if (*list == NULL)
        return -1;
    t_node *temp = *list;
    int popped_value = temp->value;
    *list = (*list)->next;
    free(temp);
    return popped_value;
}
void free_list(t_node **list)
{
    t_node *current = *list;
    t_node *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *list = NULL;
}