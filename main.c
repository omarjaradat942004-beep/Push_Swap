/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:28:20 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/20 21:29:36 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	bench_not_found(char **argv, char **result, int count)
{
	int	index;

	index = 0;
	if (count == 2 && (ft_strlen(argv[1]) == ft_strlen(result[4])
			&& ft_strncmp(argv[1], result[4], ft_strlen(result[4])) == 0))
		index++;
	if (count == 2 && (ft_strlen(argv[2]) == ft_strlen(result[4])
			&& ft_strncmp(argv[2], result[4], ft_strlen(result[4])) == 0))
		index++;
	if (count == 2 && index == 0)
		return (1);
	return (0);
}

char	**flag_split(void)
{
	char	*str;
	char	**strings;
	char	c;

	str = "--simple,--medium,--complex,--adaptive,--bench";
	c = ',';
	strings = ft_split(str, c);
	return (strings);
}

static int	flag_count(int argc, char **argv)
{
	int		index;
	int		index2;
	int		count;
	char	**result;
	int		wrong_order;

	wrong_order = 0;
	result = flag_split();
	index = 1;
	count = 0;
	while (index < argc)
	{
		index2 = 0;
		while (index2 < 5)
		{
			if (ft_strlen(argv[index]) == ft_strlen(result[index2])
				&& ft_strncmp(argv[index], result[index2], ft_strlen(result[index2])) == 0)
				count++;
			index2++;
		}
		index++;
	}
	index2 = 0;
	while (index2 < 5)
	{
		if (ft_strlen(argv[count]) == ft_strlen(result[index2])
                                && ft_strncmp(argv[count], result[index2], ft_strlen(result[index2])) == 0)
			wrong_order++;
		index2++;
	}
	if (wrong_order == 0 && count > 0)
		return (-1);
	if (bench_not_found(argv, result, count))
		return (-1);
	return (count);
}
static int	disorder_selecter(char **argv, int counter, t_snode **stack_a, t_snode **stack_b)
{
	int	index;
	int	index2;
	char	**res;
	int	adaptive;

	adaptive = 0;
	res = flag_split();
	index = 1;
	while (index <= counter)
	{
		index2 = 0;
		while (index2 < 5)
		{
			if (ft_strlen(argv[index]) == ft_strlen(res[index2])
                                && ft_strncmp(argv[index], res[index2], ft_strlen(res[index2])) == 0)
			{
				if (index2 == 0)
					selection_sort(stack_a, stack_b);
					//ft_printf_str("strategy = simple / O(n^2)\n");
				else if (index2 == 1)
					chunk_based_sort(stack_a, stack_b);
					//ft_printf_str("strategy = medium / O(n sqrt(n))\n");
				else if (index2 == 2)
					ft_printf_str("strategy = complex / O(n log(n))\n");
				else if (index2 == 3)
					ft_printf_str("strategy = adaptive\n");
				else if (index2 == 4)
				{
					ft_printf_str("call the bench function\n");
					adaptive++;
				}
				else
					adaptive++;
				break ;
			}
			index2++;
		}
		index++;
	}
	if ((adaptive == 2 && counter == 2) || (adaptive == 1 && counter == 1) || (counter == 0))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_snode	*stack_a;
	t_snode	*stack_b;
	int		counter;
	float	disorder;

	stack_a = NULL;
	stack_b = NULL;
	counter = flag_count(argc, argv);
	if (argc == 1)
		return (ft_printf_str("No arguments\n"), 0);
	if (counter > 2 || counter == -1)
		return (ft_printf_str("Error(flag overload)\n"), -1);
	parser(argc, argv, &stack_a, &counter);
	if (argc - counter - 1 == 1)
		return (0);
	disorder = compute_disorder(stack_a, argc - counter);
	if (disorder == 0.0)
		return (0);
	ft_printf_float(disorder);
	ft_printf_str("\n");
	if(!disorder_selecter(argv, counter, &stack_a, &stack_b))
		adapter(&stack_a, &stack_b, disorder);
	//Test if stack_a was sorted successfully
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
}
