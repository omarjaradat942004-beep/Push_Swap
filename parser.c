/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:12:30 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/12 18:29:36 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg(char *arg)
{
	int	index;

	index = 0;
	if (arg[index] == '-' || arg[index] == '+')
		index++;
	if (!arg[index])
		return (-1);
	while (arg[index])
	{
		if (!ft_isdigit(arg[index]))
			return (-1);
		index++;
	}
	return (0);
}

static int	find_invalid(int argc, char **argv, int *exit)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (check_arg(argv[index]) == -1)
		{
			*exit = -1;
			ft_printf_str("Error: invalid arguments");
			return (-1);
		}
		index++;
	}
	return (0);
}

int	parser(int argc, char **argv)
{
	int	index;
	int	exit;
	int	num;

	exit = 0;
	if (argc == 1)
		return (ft_printf_str("No valid arguments"), 0);
	if (find_invalid(argc, argv, &exit) == -1)
		return (-1);
	index = 1;
	while (index < argc)
	{
		num = ft_atoi(argv[index], &exit);
		if (exit == -1)
			return (ft_printf_str("Error: int overflow"), -1);
		ft_printf_decimal(num);
		write(1, "\n", 1);
		index++;
	}
	return (0);
}
