/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:39:02 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/27 20:59:20 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_snode **stack1, t_snode **stack2)
{
	t_snode	*top_node;

	top_node = pop_node(stack2);
	if (!top_node)
		return (0);
	push_node(stack1, top_node);
	return (1);
}

void	do_pa(t_snode **st_a, t_snode **st_b, t_op *operation)
{
	if (push(st_a, st_b))
	{
		if (operation->print_control == 1)
			write(1, "pa\n", 3);
		operation->counters[3]++;
	}
}

void	do_pb(t_snode **st_b, t_snode **st_a, t_op *operation)
{
	if (push(st_b, st_a))
	{
		if (operation->print_control == 1)
			write(1, "pb\n", 3);
		operation->counters[4]++;
	}
}
