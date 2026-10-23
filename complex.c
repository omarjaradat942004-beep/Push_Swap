/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:40:56 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/23 14:28:27 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits_count;

	bits_count = 0;
	while (size >> bits_count)
		bits_count++;
	return (bits_count);
}

static void	push_or_rotate(t_snode **stack_a, t_snode **stack_b,
		t_op *operation, int bit)
{
	if ((((*stack_a)->index >> bit) & 1) == 0)
	{
		do_pb(stack_b, stack_a);
		operation->counters[4]++;
	}
	else
	{
		do_ra(stack_a);
		operation->counters[5]++;
	}
}

static void	refill_a(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	while (!is_empty(stack_b))
	{
		do_pa(stack_a, stack_b);
		operation->counters[3]++;
	}
}

void	radix_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	int	stack_size;
	int	max_bits;
	int	current_bit;
	int	count;

	write(1, "Radix_sort was used!\n", 21);
	stack_size = stack_rs_initial(stack_a);
	max_bits = get_max_bits(stack_size - 1);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		count = 0;
		while (count < stack_size)
		{
			push_or_rotate(stack_a, stack_b, operation, current_bit);
			count++;
		}
		refill_a(stack_a, stack_b, operation);
		current_bit++;
	}
}
