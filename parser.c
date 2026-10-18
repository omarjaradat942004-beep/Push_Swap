/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:12:30 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/18 12:35:14 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_duplicate(int argc, char **argv, int *flag_num)
{
	int	index;
	int	index2;

	index = *flag_num + 1;
	while (index < argc - 1)
	{
		index2 = index + 1;
		while (index2 < argc)
		{
			if (ft_strlen(argv[index]) == ft_strlen(argv[index2])
    				&& ft_strncmp(argv[index], argv[index2], ft_strlen(argv[index])) == 0)
				return (1);
			index2++;
		}
		index++;
	}
	return (0);
}

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

static int	find_invalid(int argc, char **argv, int *exit, int *flag_num)
{
	int	index;

	index = *flag_num + 1;
	while (index < argc)
	{
		if (check_arg(argv[index]) == -1)
		{
			*exit = -1;
			ft_printf_str("Error: invalid arguments\n");
			return (-1);
		}
		index++;
	}
	return (0);
}

int	parser(int argc, char **argv, t_snode **stack_a, int *flag_num)
{
	int	index;
	int	exit;
	int	num;

	exit = 0;
	if (argc == 1)
		return (ft_printf_str("No arguments\n"), 0);
	if (find_invalid(argc, argv, &exit, flag_num) == -1)
		return (-1);
	index = argc - 1;
	while (index > *flag_num)
	{
		num = ft_atoi(argv[index], &exit);
		if (exit == -1)
			return (ft_printf_str("Error: int overflow\n"), -1);
		if (find_duplicate(argc, argv, flag_num))
			return (ft_printf_str("Error: duplicate detected\n"), -1);
		push_node(stack_a, new_node(num));
		write(1, "\n", 1);
		index--;
	}
	return (0);
}
