/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:54:59 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/22 20:35:53 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adapter(t_snode **stack_a, t_snode **stack_b, float disorder)
{
	if (disorder < 0.2)
		selection_sort(stack_a, stack_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_based_sort(stack_a, stack_b);
	else if (disorder >= 0.5)
		radix_sort(stack_a, stack_b);
}
