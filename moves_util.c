/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:17:19 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/12/20 14:17:53 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap functions
void sa(t_node **a)
{
    if (!*a || !(*a)->next)
        return;
    t_node *first = *a;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    write(1, "sa\n", 3);
}

void sb(t_node **b)
{
    if (!*b || !(*b)->next)
        return;
    t_node *first = *b;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b)
{
    if (*a && (*a)->next)
    {
        t_node *first = *a;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        *a = second;
    }
    if (*b && (*b)->next)
    {
        t_node *first = *b;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        *b = second;
    }
    write(1, "ss\n", 3);
}

// Push functions
void pa(t_node **a, t_node **b)
{
    if (!*b)
        return;
    int val = pop(b);
    push(a, val);
    write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b)
{
    if (!*a)
        return;
    int val = pop(a);
    push(b, val);
    write(1, "pb\n", 3);
}