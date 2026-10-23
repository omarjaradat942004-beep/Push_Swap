/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:06:39 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/23 14:18:41 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Simple algorithm (O(n2 ))
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

	write(1, "Selection_sort was used!\n", 25);
	while (!is_empty(stack_a))
	{
		min_node = find_min_node(stack_a);
		while (*stack_a != min_node)
		{
			do_ra(stack_a);
			operation->counters[5]++;
		}
		do_pb(stack_b, stack_a);
		operation->counters[4]++;
	}
	while (!is_empty(stack_b))
	{
		do_pa(stack_a, stack_b);
		operation->counters[3]++;
	}
}
