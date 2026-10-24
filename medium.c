/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:32:52 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/24 20:08:12 by omajarad         ###   ########.fr       */
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

static void	pushing_stack_b(t_snode **stack_a, t_snode **stack_b,
		t_op *operation)
{
	t_snode	*max_node;
	int		node_pos;
	int		stack_size;

	while (!is_empty(stack_b))
	{
		max_node = find_max_node(stack_b);
		stack_size = get_stack_size(*stack_b);
		node_pos = get_node_pos(*stack_b, max_node);
		while (*stack_b != max_node)
		{
			if (node_pos <= (stack_size / 2))
				do_rb(stack_b, operation);
			else
				do_rrb(stack_b, operation);
		}
		do_pa(stack_a, stack_b, operation);
	}
}

void	chunk_based_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation)
{
	int		chunk_size;
	int		chunk_max;
	int		pushed;

	chunk_size = (ft_sqrt(stack_rs_initial(stack_a)) * 3) / 2;
	chunk_max = chunk_size;
	pushed = 0;
	while (!is_empty(stack_a))
	{
		if ((*stack_a)->index < chunk_max)
		{
			do_pb(stack_b, stack_a, operation);
			pushed++;
			if ((*stack_b)->index < (chunk_max - (chunk_size / 2)))
				do_rb(stack_b, operation);
			if (pushed == chunk_max)
				chunk_max += chunk_size;
		}
		else
			do_ra(stack_a, operation);
	}
	pushing_stack_b(stack_a, stack_b, operation);
}
