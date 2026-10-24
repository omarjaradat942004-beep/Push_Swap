/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:45:40 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 20:39:21 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_flag(char **str)
{
	int	index;

	index = 0;
	while (str[index] != NULL)
	{
		free(str[index]);
		index++;
	}
	free(str);
}

void	free_stack(t_snode **stack)
{
	t_snode	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
