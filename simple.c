/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:06:39 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/22 20:47:32 by yal-sale         ###   ########.fr       */
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

void	selection_sort(t_snode **stack_a, t_snode **stack_b)
{
	write(1, "Selection_sort was used!\n", 25);
	t_snode	*min_node;

	while (!is_empty(stack_a))
	{
		min_node = find_min_node(stack_a);
		while (*stack_a != min_node)
			do_ra(stack_a);
		do_pb(stack_b, stack_a);
	}
	while (!is_empty(stack_b))
		do_pa(stack_a, stack_b);
}
