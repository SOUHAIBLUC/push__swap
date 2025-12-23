/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:00 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/12/23 15:28:04 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Rotate functions
void ra(t_node **a)
{
    if (!*a || !(*a)->next)
        return;
    t_node *first = *a;
    *a = first->next;
    t_node *current = *a;
    while (current->next)
        current = current->next;
    current->next = first;
    first->next = NULL;
    write(1, "ra\n", 3);
}

void rb(t_node **b)
{
    if (!*b || !(*b)->next)
        return;
    t_node *first = *b;
    *b = first->next;
    t_node *current = *b;
    while (current->next)
        current = current->next;
    current->next = first;
    first->next = NULL;
    write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b)
{
    if (*a && (*a)->next)
    {
        t_node *first = *a;
        *a = first->next;
        t_node *current = *a;
        while (current->next)
            current = current->next;
        current->next = first;
        first->next = NULL;
    }
    if (*b && (*b)->next)
    {
        t_node *first = *b;
        *b = first->next;
        t_node *current = *b;
        while (current->next)
            current = current->next;
        current->next = first;
        first->next = NULL;
    }
    write(1, "rr\n", 3);
}

// Reverse rotate functions
void rra(t_node **a)
{
    if (!*a || !(*a)->next)
        return;
    t_node *current = *a;
    t_node *prev = NULL;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = *a;
    *a = current;
    write(1, "rra\n", 4);
}

void rrb(t_node **b)
{
    if (!*b || !(*b)->next)
        return;
    t_node *current = *b;
    t_node *prev = NULL;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = *b;
    *b = current;
    write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b)
{
    if (*a && (*a)->next)
    {
        t_node *current = *a;
        t_node *prev = NULL;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        current->next = *a;
        *a = current;
    }
    if (*b && (*b)->next)
    {
        t_node *current = *b;
        t_node *prev = NULL;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        current->next = *b;
        *b = current;
    }
    write(1, "rrr\n", 4);
}