/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:05:04 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/23 20:27:02 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*array_converter(t_snode *stack_a, int size)
{
	t_snode	*node;
	int		*arr;
	int		index;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	index = 0;
	node = stack_a;
	while (node && index < size)
	{
		arr[index] = node->value;
		node = node->next;
		index++;
	}
	return (arr);
}

static int	count_mistakes(int *ptr, int size, int *total_pairs)
{
	int	mistakes;
	int	index;
	int	index2;

	mistakes = 0;
	index = 0;
	while (index < size - 1)
	{
		index2 = index + 1;
		while (index2 < size)
		{
			(*total_pairs)++;
			if (ptr[index] > ptr[index2])
				mistakes++;
			index2++;
		}
		index++;
	}
	return (mistakes);
}

float	compute_disorder(t_snode *stack_a, int size)
{
	int	mistakes;
	int	total_pairs;
	int	*ptr;

	total_pairs = 0;
	ptr = array_converter(stack_a, size);
	if (!ptr || size < 2)
		return (free(ptr), 0.0f);
	mistakes = count_mistakes(ptr, size, &total_pairs);
	free(ptr);
	return ((float)mistakes / total_pairs);
}
