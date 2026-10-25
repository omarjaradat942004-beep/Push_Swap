/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:28:20 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/25 11:54:09 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bench_not_found(char **argv, char **result, int count)
{
	if (count != 2)
		return (0);
	if (find_flag(argv[1], result) == 4)
		return (0);
	if (find_flag(argv[2], result) == 4)
		return (0);
	return (1);
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
	int		count;
	char	**result;

	result = flag_split();
	index = 1;
	count = 0;
	while (index < argc)
	{
		if (find_flag(argv[index], result) >= 0)
			count++;
		index++;
	}
	if (find_flag(argv[count], result) < 0 && count > 0)
		return (free_flag(result), -1);
	if (bench_not_found(argv, result, count))
		return (free_flag(result), -1);
	free_flag(result);
	return (count);
}

static void	main_helper(t_count *counters, t_snode *stack_a,
		t_op *operations)
{
	t_snode	*stack_b;
	int		index;

	index = 0;
	stack_b = NULL;
	if (stack_a)
	{
		counters->disorder = compute_disorder(stack_a,
				get_stack_size(stack_a));
		if (!disorder_selecter(counters, &stack_a, &stack_b, operations)
			&& counters->disorder != 0.0f)
			adapter(&stack_a, &stack_b, counters, operations);
		if (counters->bench_count > 0)
		{
			while (index < counters->bench_count)
			{
				benchmark(counters->arg, counters, operations);
				index++;
			}
		}
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(counters);
	free(operations);
}

int	main(int argc, char **argv)
{
	t_snode	*stack_a;
	t_count	*counters;
	t_op	*operations;

	if (argc == 1)
		return (0);
	counters = malloc(sizeof(t_count));
	operations = malloc(sizeof(t_op));
	stack_a = NULL;
	if (!operations || !counters)
		return (free(counters), free(operations), 1);
	counters->arg = argvs(argv);
	counters->bench_count = 0;
	init(&operations);
	counters->counter = flag_count(argc, argv);
	if (counters->counter < 0 || counters->counter > 2
		|| parser(argc, argv, &stack_a, &counters->counter) == -1)
	{
		free_stack(&stack_a);
		free(counters);
		free(operations);
		return (ft_error(), 1);
	}
	main_helper(counters, stack_a, operations);
	return (0);
}
