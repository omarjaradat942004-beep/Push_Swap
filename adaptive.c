/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:54:59 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/19 18:54:59 by omajarad         ###   ########.fr       */
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
		ft_printf_str("strategy = complex / O(n log(n))\n");
}
