/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:18:16 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/26 12:25:44 by omajarad         ###   ########.fr       */
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

static void	small_sort_helper(int size, t_snode **stack_a, t_op *operation)
{
	if (size == 3 && (*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		do_ra(stack_a, operation);
	else if (size == 3 && (*stack_a)->next->value > (*stack_a)->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
		do_rra(stack_a, operation);
}

t_snode	*small_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	int	size;

	size = get_stack_size(*stack_a);
	while (size > 3)
	{
		while (*stack_a != find_min_node(stack_a))
		{
			if (get_node_pos(*stack_a, find_min_node(stack_a)) <= size / 2)
				do_ra(stack_a, operation);
			else
				do_rra(stack_a, operation);
		}
		do_pb(stack_b, stack_a, operation);
		size--;
	}
	small_sort_helper(size, stack_a, operation);
	if ((*stack_a)->value > (*stack_a)->next->value)
		do_sa(stack_a, operation);
	while (!is_empty(stack_b))
		do_pa(stack_a, stack_b, operation);
	return (*stack_a);
}
