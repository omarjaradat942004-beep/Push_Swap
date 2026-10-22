/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:22:52 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/22 14:53:02 by omajarad         ###   ########.fr       */
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
}
