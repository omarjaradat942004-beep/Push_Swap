/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:28:20 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/18 13:43:22 by omajarad         ###   ########.fr       */
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
        strings = ft_split(str,c);
	return (strings);
}	

static int	flag_count(int argc, char **argv)
{
	int     index;
	int	index2;
	int     count;
	char	**result;
	int	wrong_order;


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
		if (ft_strncmp(argv[count],result[index2],ft_strlen(result[index2])) == 0)
			wrong_order++;

		index2++;
	}
	if (wrong_order == 0 && count > 0)
		return (-1);
	if (bench_not_found(argv, result,count))
		return (-1);
	return (count);
}
int main(int argc, char **argv)
{
	t_snode *stack_a;
	int	counter;
	float	disorder;

	stack_a = NULL;
	counter = flag_count(argc, argv);
	if (counter > 2 || counter == -1)
		return(ft_printf_str("Error(flag overload)"), -1);
	parser(argc, argv, &stack_a, &counter);
	disorder = compute_disorder(stack_a, argc - counter);
	printf("disorder = %.2f",disorder);
}
