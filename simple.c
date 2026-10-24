/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:06:39 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 18:27:16 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_snode	*find_min_node(t_snode **stack)
{
	t_snode	*min_node;
	t_snode	*current;

	min_node = *stack;
	current = *stack;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	selection_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	t_snode	*min_node;
	int		stack_size;
	int		node_pos;

	while (!is_empty(stack_a))
	{
		min_node = find_min_node(stack_a);
		if ((*stack_a)->next == min_node)
			do_sa(stack_a, operation);
		stack_size = get_stack_size(*stack_a);
		node_pos = get_node_pos(*stack_a, min_node);
		while (*stack_a != min_node)
		{
			if (node_pos <= (stack_size / 2))
				do_ra(stack_a, operation);
			else
				do_rra(stack_a, operation);
		}
		do_pb(stack_b, stack_a, operation);
	}
	while (!is_empty(stack_b))
		do_pa(stack_a, stack_b, operation);
}
