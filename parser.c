/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:12:30 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 20:35:13 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_duplicate(int argc, char **argv, int *flag_num)
{
	int	inx;
	int	inx2;

	inx = *flag_num + 1;
	while (inx < argc - 1)
	{
		inx2 = inx + 1;
		while (inx2 < argc)
		{
			if (ft_strncmp(argv[inx], argv[inx2],
					ft_strlen(argv[inx]) + 1) == 0)
				return (1);
			inx2++;
		}
		inx++;
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
			ft_printf_str("Error\n");
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
	if (find_invalid(argc, argv, &exit, flag_num) == -1)
		return (-1);
	if (argc - *flag_num - 1 == 1)
		return (0);
	index = argc - 1;
	while (index > *flag_num)
	{
		num = ft_atoi(argv[index], &exit);
		if (exit == -1)
			return (ft_printf_str("Error\n"), -1);
		if (find_duplicate(argc, argv, flag_num))
			return (ft_printf_str("Error\n"), -1);
		push_node(stack_a, new_node(num));
		index--;
	}
	return (0);
}
