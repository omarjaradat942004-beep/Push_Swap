/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:54:59 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/23 13:53:30 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adapter(t_snode **stack_a, t_snode **stack_b, t_count *counters)
{
	if (counters->disorder < 0.2)
		selection_sort(stack_a, stack_b);
	else if (counters->disorder >= 0.2 && counters->disorder < 0.5)
		chunk_based_sort(stack_a, stack_b);
	else if (counters->disorder >= 0.5)
		radix_sort(stack_a, stack_b);
}
