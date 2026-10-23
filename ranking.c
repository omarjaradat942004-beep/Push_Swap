/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:32:52 by yal-sale          #+#    #+#             */
/*   Updated: 2026/10/23 14:21:48 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_rs_initial(t_snode **stack)
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
