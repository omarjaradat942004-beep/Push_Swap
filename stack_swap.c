/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:13:35 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/24 18:21:03 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_snode **stack)
{
	t_snode	*first;
	t_snode	*second;

	if (is_empty(stack) || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	return (1);
}

void	do_sa(t_snode **st_a, t_op *operation)
{
	if (swap(st_a))
	{
		write(1, "sa\n", 3);
		operation->counters[0]++;
	}
}

void	do_sb(t_snode **st_b, t_op *operation)
{
	if (swap(st_b))
	{
		write(1, "sb\n", 3);
		operation->counters[1]++;
	}
}

void	do_ss(t_snode **st_a, t_snode **st_b, t_op *operation)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap(st_a);
	swapped_b = swap(st_b);
	if (swapped_a || swapped_b)
	{
		write(1, "ss\n", 3);
		operation->counters[2]++;
	}
}
