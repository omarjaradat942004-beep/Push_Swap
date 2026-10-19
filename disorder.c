/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:05:04 by omajarad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/10/18 15:25:51 by omajarad         ###   ########.fr       */
=======
/*   Updated: 2026/10/18 17:51:52 by yal-sale         ###   ########.fr       */
>>>>>>> 584338c (gg)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
<<<<<<< HEAD
static int	*array_converter(t_snode *stack_a, int size)
{
	t_snode	*node;
	int	*arr;
	int	index;
=======

static int	*array_converter(t_snode *stack_a, int size)
{
	t_snode	*node;
	int		*arr;
	int		index;
>>>>>>> 584338c (gg)

	node = stack_a;
	arr = malloc(sizeof(int) * size);
	while (node && index < size - 1)
	{
		arr[index] = node->value;
		node = node->next;
		index++;
	}
	return (arr);
}

float	compute_disorder(t_snode *stack_a, int size)
{
	int	mistakes;
	int	total_pairs;
	int	index;
	int	index2;
	int	*ptr;

	mistakes = 0;
	total_pairs = 0;
	index = 0;
	ptr = array_converter(stack_a, size);
	while (index < size - 1)
	{
		index2 = index + 1;
		while (index2 < size - 1)
		{
			total_pairs++;
			if (ptr[index] > ptr[index2])
				mistakes++;
			index2++;
		}
		index++;
	}
	free(ptr);
	return ((float)mistakes / total_pairs);
}
