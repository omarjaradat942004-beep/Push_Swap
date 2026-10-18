/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:06:39 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/18 12:38:59 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Simple algorithm (O(n2 ))
#include "push_swap.h"

void	insert_sort(t_snode **stack_a)
{
	t_snode	*temp;
	t_snode	*stack_a_top;
	t_snode	*node;

	temp = NULL;
	while (!is_empty(stack_a))
	{
		stack_a_top = pop_node(stack_a);
		while (!is_empty(&temp) && temp->value  >  stack_a_top->value)
		{
			node = pop_node(&temp);
			if (!node)
				break ;
			push_node(stack_a, node);
		}
		push_node(&temp,stack_a_top);
	}
	while (!is_empty(&temp))
	{
		node = pop_node(&temp);
		if (!node)
			break ;
		push_node(stack_a, node);
	}
}
