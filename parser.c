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

static int	find_invalid(int argc, char **argv, int *flag_num)
{
	int	index;

	index = *flag_num + 1;
	while (index < argc)
	{
		if (check_arg(argv[index]) == -1)
			return (-1);
		index++;
	}
	return (0);
}

static int	has_value(t_snode *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	parser(int argc, char **argv, t_snode **stack_a, int *flag_num)
{
	int		index;
	int		error;
	int		num;
	t_snode	*node;

	if (find_invalid(argc, argv, flag_num) == -1)
		return (-1);
	index = argc - 1;
	while (index > *flag_num)
	{
		num = ft_atoi(argv[index], &error);
		if (error == -1 || has_value(*stack_a, num))
			return (-1);
		node = new_node(num);
		if (!node)
			return (-1);
		push_node(stack_a, node);
		index--;
	}
	return (0);
}
