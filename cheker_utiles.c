/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:26:14 by so-ait-l          #+#    #+#             */
/*   Updated: 2026/01/07 16:26:32 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	stack_push_front(t_stack *stack, t_node *node)
{
	if (stack == NULL || node == NULL)
		return ;
	node->next = stack->head;
	stack->head = node;
	stack->size++;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = NULL;
	stack->size--;
	return (tmp);
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack->head;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack->head = NULL;
}

void	stack_push_back(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (stack == NULL || node == NULL)
		return ;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->size++;
		return ;
	}
	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	stack->size++;
}
