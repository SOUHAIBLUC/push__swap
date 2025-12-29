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

void swap(t_stack *stack) {
  if (!stack || !stack->head || stack->head->next == NULL)
    return;
  t_node *first = stack->head;
  t_node *second = first->next;
  first->next = second->next;
  second->next = first;
  stack->head = second;
}
// Swap functions
void sa(t_game *game) {
  swap(&game->a);
  write(1, "sa\n", 3);
}

void sb(t_game *game) {
  swap(&game->b);
  write(1, "sb\n", 3);
}

void ss(t_game *game) {
  swap(&game->a);
  swap(&game->b);
  write(1, "ss\n", 3);
}