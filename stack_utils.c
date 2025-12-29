#include "push_swap.h"

t_node *node_new(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next  = NULL;
    return new_node;
}

void stack_push(t_stack *stack, t_node *node)
{
    if (stack == NULL || node == NULL)
        return;
    node->next = stack;
    stack->head = node;
    stack->size++;
}

t_node *stack_pop(t_stack *stack)
{
    if (stack == NULL || stack->head == NULL)
        return -1;
    t_node *tmp = stack->head;
    stack->head = tmp->next;
    tmp->next = NULL;
    stack->size--;
    return tmp;
}

void stack_clear(t_stack *stack)
{
    t_node *current = stack->head;
    t_node *tmp;
    while (current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    stack->head = NULL;
}