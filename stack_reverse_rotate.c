/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:58:25 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/24 17:52:02 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_snode **stack)
{
	t_snode	*temp_head;

	if (is_empty(stack) || !(*stack)->next)
		return (0);
	temp_head = *stack;
	while (temp_head->next != NULL)
		temp_head = temp_head->next;
	temp_head->prev->next = NULL;
	temp_head->next = *stack;
	temp_head->prev = NULL;
	(*stack)->prev = temp_head;
	*stack = temp_head;
	return (1);
}

void	do_rra(t_snode **st_a, t_op *operation)
{
	if (reverse_rotate(st_a))
	{
		write(1, "rra\n", 4);
		operation->counters[8]++;
	}
}

void	do_rrb(t_snode **st_b, t_op *operation)
{
	if (reverse_rotate(st_b))
	{
		write(1, "rrb\n", 4);
		operation->counters[9]++;
	}
}

void	do_rrr(t_snode **st_a, t_snode **st_b, t_op *operation)
{
	int	reversed_a;
	int	reversed_b;

	reversed_a = reverse_rotate(st_a);
	reversed_b = reverse_rotate(st_b);
	if (reversed_a || reversed_b)
	{
		write(1, "rrr\n", 4);
		operation->counters[10]++;
	}
}
