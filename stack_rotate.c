/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:12:37 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/27 20:59:39 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_snode **stack)
{
	t_snode	*taken_node;
	t_snode	*temp_head;

	if (is_empty(stack) || !(*stack)->next)
		return (0);
	taken_node = pop_node(stack);
	temp_head = *stack;
	while (temp_head->next != NULL)
		temp_head = temp_head->next;
	temp_head->next = taken_node;
	taken_node->prev = temp_head;
	taken_node->next = NULL;
	return (1);
}

void	do_ra(t_snode **st_a, t_op *operation)
{
	if (rotate(st_a))
	{
		if (operation->print_control == 1)
			write(1, "ra\n", 3);
		operation->counters[5]++;
	}
}

void	do_rb(t_snode **st_b, t_op *operation)
{
	if (rotate(st_b))
	{
		if (operation->print_control == 1)
			write(1, "rb\n", 3);
		operation->counters[6]++;
	}
}

void	do_rr(t_snode **st_a, t_snode **st_b, t_op *operation)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(st_a);
	rotated_b = rotate(st_b);
	if (rotated_a || rotated_b)
	{
		if (operation->print_control == 1)
			write(1, "rr\n", 3);
		operation->counters[7]++;
	}
}
