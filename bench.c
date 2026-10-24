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

static char	**flag_split_2(void)
{
	char	*str;
	char	**strings;
	char	c;

	str = "--simple,--medium,--complex,--adaptive";
	c = ',';
	strings = ft_split(str, c);
	return (strings);
}

void	print_else(char **argv, char **str)
{
	if (ft_strncmp(argv[1], str[0], ft_strlen(str[0]) + 1) == 0
		|| ft_strncmp(argv[2], str[0], ft_strlen(str[0]) + 1) == 0)
		ft_printf_str_2("[bench] strategy: Simple / O(n^2)\n");
	else if (ft_strncmp(argv[1], str[1], ft_strlen(str[1]) + 1) == 0
		|| ft_strncmp(argv[2], str[1], ft_strlen(str[1]) + 1) == 0)
		ft_printf_str_2("[bench] strategy: Medium / O(n^2)\n");
	else if (ft_strncmp(argv[1], str[2], ft_strlen(str[2]) + 1) == 0
		|| ft_strncmp(argv[2], str[2], ft_strlen(str[2]) + 1) == 0)
		ft_printf_str_2("[bench] strategy: Complex / O(n^2)\n");
}

void	benchmark(char **argv, t_count *counters, t_op *operation)
{
	char	**str;

	str = flag_split_2();
	ft_printf_float(counters->disorder);
	ft_printf_str_2("\n");
	if (counters->bench_count == counters->counter)
	{
		if (counters->disorder < 0.2)
			ft_printf_str_2("[bench] strategy: Adaptive / O(n^2)\n");
		else if (counters->disorder >= 0.2 && counters->disorder < 0.5)
			ft_printf_str_2("[bench] strategy: Adaptive / O(n sqrt(n))\n");
		else if (counters->disorder >= 0.5)
			ft_printf_str_2("[bench] strategy: Adaptive / O(n log(n))\n");
	}
	else
		print_else(argv, str);
	free_flag(str);
	print_op(operation);
}
