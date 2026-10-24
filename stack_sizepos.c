/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sizepos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:24:29 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/24 20:06:58 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_snode *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_node_pos(t_snode *stack, t_snode *target_node)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (target_node == stack)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
