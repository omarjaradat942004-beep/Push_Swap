/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:32:52 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/23 14:21:48 by omajarad         ###   ########.fr       */
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

static int	ft_sqrt(int num)
{
	int	i;

	i = 1;
	while ((i * i) <= num)
		i++;
	return (i - 1);
}

static t_snode	*find_max_node(t_snode **stack)
{
	t_snode	*max_node;
	t_snode	*current;

	if (is_empty(stack))
		return (NULL);
	max_node = *stack;
	current = *stack;
	while (current)
	{
		if (current->index > max_node->index)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	chunk_based_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	write(1, "Chunk_sort was used!\n", 21);
	int		chunk_size;
	int		chunk_max;
	int		pushed;

	chunk_size = ft_sqrt(stack_rs_initial(stack_a));
	chunk_max = chunk_size;
	pushed = 0;
	while (!is_empty(stack_a))
	{
		if ((*stack_a)->index < chunk_max)
		{
			do_pb(stack_b, stack_a);
			operation->counters[4]++;
			pushed++;
			if (pushed == chunk_max)
				chunk_max += chunk_size;
		}
		else
		{
			do_ra(stack_a);
			operation->counters[5]++;
		}
	}
	while (!is_empty(stack_b))
	{
		while ((*stack_b) != find_max_node(stack_b))
		{
			do_rb(stack_b);
			operation->counters[6]++;
		}
		do_pa(stack_a, stack_b);
		operation->counters[3]++;
	}
}
