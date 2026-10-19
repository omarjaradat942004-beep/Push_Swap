/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:06:39 by omajarad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/10/18 12:38:59 by omajarad         ###   ########.fr       */
=======
/*   Updated: 2026/10/18 16:21:32 by yal-sale         ###   ########.fr       */
>>>>>>> 584338c (gg)
/*                                                                            */
/* ************************************************************************** */

//Simple algorithm (O(n2 ))
#include "push_swap.h"

<<<<<<< HEAD
void	insert_sort(t_snode **stack_a)
=======
static t_snode	*find_min_node(t_snode **stack)
>>>>>>> 584338c (gg)
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
