/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:00:00 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/23 17:00:00 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_flag(char *arg, char **flags)
{
	int	index;

	index = 0;
	while (index < 5)
	{
		if (ft_strncmp(arg, flags[index], ft_strlen(flags[index]) + 1) == 0)
			return (index);
		index++;
	}
	return (-1);
}

static void	run_sort(int flag, t_snode **stack_a, t_snode **stack_b,
		t_op *operation)
{
	if (flag == 0)
		selection_sort(stack_a, stack_b, operation);
	else if (flag == 1)
		chunk_based_sort(stack_a, stack_b, operation);
	else if (flag == 2)
		radix_sort(stack_a, stack_b, operation);
}

static int	flags_only(t_count *counters, int bench)
{
	if (counters->counter == 0)
		return (0);
	if (bench == 2 && counters->counter == 2)
		return (0);
	if (bench == 1 && counters->counter == 1)
		return (0);
	return (1);
}

int	disorder_selecter(t_count *counters, t_snode **stack_a,
		t_snode **stack_b, t_op *operation)
{
	int		index;
	int		flag;
	int		bench;
	char	**res;

	bench = 0;
	res = flag_split();
	index = 1;
	while (index <= counters->counter)
	{
		flag = find_flag(counters->arg[index], res);
		if (flag >= 0 && flag <= 2)
			run_sort(flag, stack_a, stack_b, operation);
		else if (flag == 3)
			adapter(stack_a, stack_b, counters, operation);
		else if (flag == 4)
		{
			counters->bench_count++;
			bench++;
		}
		index++;
	}
	return (flags_only(counters, bench));
}
