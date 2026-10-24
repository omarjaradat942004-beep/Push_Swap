/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:10:38 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 16:56:45 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_printf_str_2(char *str)
{
	size_t	index;
	int		counter;

	if (!str)
	{
		if (write(2, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	index = 0;
	counter = 0;
	while (str[index])
	{
		if (write(2, &str[index], 1) == -1)
			return (-1);
		index++;
		counter++;
	}
	return (counter);
}

static int	strategy_of(char **argv, t_count *counters)
{
	char	**flags;
	int		index;
	int		flag;
	int		strategy;

	flags = flag_split();
	strategy = 3;
	index = 1;
	while (flags && index <= counters->counter)
	{
		flag = find_flag(argv[index], flags);
		if (flag >= 0 && flag <= 3)
			strategy = flag;
		index++;
	}
	if (flags)
		free_flag(flags);
	return (strategy);
}

static void	print_adaptive(float disorder)
{
	if (disorder < 0.2)
		ft_printf_str_2("[bench] strategy: Adaptive / O(n^2)\n");
	else if (disorder < 0.5)
		ft_printf_str_2("[bench] strategy: Adaptive / O(n sqrt(n))\n");
	else
		ft_printf_str_2("[bench] strategy: Adaptive / O(n log(n))\n");
}

static void	print_strategy(int strategy, float disorder)
{
	if (strategy == 0)
		ft_printf_str_2("[bench] strategy: Simple / O(n^2)\n");
	else if (strategy == 1)
		ft_printf_str_2("[bench] strategy: Medium / O(n sqrt(n))\n");
	else if (strategy == 2)
		ft_printf_str_2("[bench] strategy: Complex / O(n log(n))\n");
	else
		print_adaptive(disorder);
}

void	benchmark(char **argv, t_count *counters, t_op *operation)
{
	ft_printf_float(counters->disorder);
	ft_printf_str_2("\n");
	print_strategy(strategy_of(argv, counters), counters->disorder);
	print_op(operation);
}
