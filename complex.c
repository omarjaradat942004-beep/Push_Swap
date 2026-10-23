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

static int	stack_rs_initial(t_snode **stack)
{
	t_snode	*current;
	t_snode	*compare;
	int		stack_rank;
	int		stack_size;

	current = *stack;
	stack_size = 0;
	while (current)
	{
		stack_rank = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->value < current->value)
				stack_rank++;
			compare = compare->next;
		}
		current->index = stack_rank;
		stack_size++;
		current = current->next;
	}
	return (stack_size);
}

static int	get_max_bits(int size)
{
	int	bits_count;

	bits_count = 0;
	while (size >> bits_count)
		bits_count++;
	return (bits_count);
}

void	radix_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	write(1, "Radix_sort was used!\n", 21);
	int stack_size;
	int	max_bits;
	int	current_bit;
	int count;

	stack_size = stack_rs_initial(stack_a);
	max_bits = get_max_bits(stack_size - 1);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		count = 0;
		while (count < stack_size)
		{
			if ((((*stack_a)->index >> current_bit) & 1) == 0)
			{
				do_pb(stack_b, stack_a);
				operation->counters[4]++;
			}
			else
			{
				do_ra(stack_a);
				operation->counters[5]++;
			}
			count++;
		}
		while (!is_empty(stack_b))
		{
			do_pa(stack_a, stack_b);
			operation->counters[3]++;
		}
		current_bit++;
	}
}
