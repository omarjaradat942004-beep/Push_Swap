/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:22:52 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/29 17:47:47 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_op **operations)
{
	int	index;

	index = 0;
	while (index < 11)
	{
		(*operations)->counters[index] = 0;
		index++;
	}
	(*operations)->print_control = 1;
}

int	get_total_op(t_op *operation)
{
	int	index_of_op;
	int	total;

	index_of_op = 0;
	total = 0;
	while (index_of_op < 11)
	{
		total += operation->counters[index_of_op];
		index_of_op++;
	}
	return (total);
}
