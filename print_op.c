/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:50:10 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 17:07:05 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	digit_count_2(long numb)
{
	int	counter;

	counter = 0;
	if (numb < 0)
	{
		counter++;
		numb = -numb;
	}
	while (numb > 9)
	{
		counter++;
		numb /= 10;
	}
	counter++;
	return (counter);
}

static int	ft_printf_decimal_2(int num)
{
	int		counter;
	long	numb;
	char	*str;

	numb = (long)num;
	counter = digit_count_2(numb);
	str = ft_itoa(num);
	if (write(2, str, counter) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

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

char	**flag_split_3(void)
{
	char	*str;
	char	**strings;
	char	c;

	str = "[bench] sa: , sb: , ss: , pa: , pb: ,"
		"[bench] ra: , rb: , rr: , rra: , rrb: , rrr: ";
	c = ',';
	strings = ft_split(str, c);
	return (strings);
}

void	print_op(t_op *operation)
{
	int		total;
	int		index;
	char	**res;

	index = 0;
	total = 0;
	while (index < 11)
		total += operation->counters[index++];
	ft_printf_str_2("[bench] total_ops: ");
	ft_printf_decimal_2(total);
	ft_printf_str_2("\n");
	index = 0;
	res = flag_split_3();
	while (index < 11)
	{
		ft_printf_str_2(res[index]);
		ft_printf_decimal_2(operation->counters[index++]);
		if (index == 5)
			ft_printf_str_2("\n");
	}
	ft_printf_str_2("\n");
	free_flag(res);
}
