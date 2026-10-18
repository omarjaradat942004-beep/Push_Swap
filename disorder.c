/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:05:04 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/18 13:51:38 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int	*array_converter(t_snode *stack_a, int size)
{
	t_snode	*node;
	int	*arr;
	int	index;

	index = 0;
	arr = malloc(sizeof(int) * size);
	while (index < size - 1)
	{
		node = pop_node(&stack_a);
		arr[index] = node->value;
		index++;
	}
	return (arr);
}

float	compute_disorder(t_snode *stack_a, int size)
{
	//int	mistakes;
	//int	total_pairs;
	int	index;
	//int	index2;
	int	*ptr;

	//mistakes = 0;
	//total_pairs = 0;
	index = 0;
	//index2 = index + 1;
	ptr = array_converter(stack_a, size);
	while (index < size - 1)
	{
		printf("%d ",ptr[index]);
		index++;
	}
	free(ptr);
	return (0);
}
