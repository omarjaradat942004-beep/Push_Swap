/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:00:00 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/27 22:11:18 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_flag(char *arg, char **flags)
{
	int	index;

	index = 0;
	while (flags[index])
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

static int	skip_sorted(int flag, t_count *counters)
{
	if (counters->disorder == 0.0f && flag < 4)
		return (-1);
	return (flag);
}

static int	flags_only(t_count *counters, char **res, t_op *operation)
{
	int	index;
	int	flag;
	int	mods;

	index = 1;
	mods = 0;
	operation->print_control = 1;
	while (index <= counters->counter)
	{
		flag = find_flag(counters->arg[index], res);
		if (flag == 4)
			counters->bench_count++;
		if (flag >= 4)
			mods++;
		index++;
	}
	return (mods != counters->counter);
}

int	disorder_selecter(t_count *counters, t_snode **stack_a,
		t_snode **stack_b, t_op *operation)
{
	int		index;
	int		flag;
	int		has_strat;
	char	**res;

	res = flag_split();
	has_strat = flags_only(counters, res, operation);
	index = 1;
	while (index <= counters->counter)
	{
		flag = skip_sorted(find_flag(counters->arg[index], res), counters);
		if (flag >= 0 && flag <= 2)
			run_sort(flag, stack_a, stack_b, operation);
		else if (flag == 3)
			adapter(stack_a, stack_b, counters, operation);
		index++;
	}
	free_flag(res);
	return (has_strat);
}
