/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:28:20 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 21:03:45 by omajarad         ###   ########.fr       */
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

void	main_helper(t_count *counters, t_snode *stack_a,
		t_snode *stack_b, t_op *operations)
{
	if (!disorder_selecter(counters, &stack_a, &stack_b, operations))
		adapter(&stack_a, &stack_b, counters, operations);
	if (counters->bench_count > 0)
	{
		while (counters->bench_count > 0)
		{
			benchmark(counters->arg, counters, operations);
			counters->bench_count--;
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
	t_snode	*stack_b;
	t_count	*counters;
	t_op	*operations;

	counters = malloc(sizeof(t_count));
	operations = malloc(sizeof(t_op));
	if (!operations || !counters)
		return (-1);
	counters->arg = argvs(argv);
	counters->bench_count = 0;
	init(&operations);
	stack_a = NULL;
	stack_b = NULL;
	counters->counter = flag_count(argc, argv);
	if (argc == 1 || counters->counter > 2 || counters->counter == -1)
		return (ft_printf_str("Error\n"), -1);
	parser(argc, argv, &stack_a, &counters->counter);
	if (argc - counters->counter - 1 == 0)
		return (ft_printf_str("Error\n") ,0);
	counters->disorder = compute_disorder(stack_a, argc - counters->counter);
	if (counters->disorder == 0.0)
		return (0);
	main_helper(counters, stack_a, stack_b, operations);
	return (0);
}
