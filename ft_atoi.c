/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:51:27 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/18 17:49:58 by yal-sale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	get_sign(const char *nptr, int *index)
{
	int	sign;

	sign = 1;
	if (nptr[*index] == '-' || nptr[*index] == '+')
	{
		if (nptr[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

static long	limit_range(int sign)
{
	if (sign == 1)
		return (INT_MAX);
	return (2147483648L);
}

static int	check_overflow(int value, int digit, long limit)
{
	if (value > (limit - digit) / 10)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, int *error)
{
	int		index;
	int		sign;
	int		value;
	int		digit;
	long	limit;

	*error = 0;
	index = 0;
	value = 0;
	while (nptr[index] == ' ' || (nptr[index] >= 9 && nptr[index] <= 13))
		index++;
	sign = get_sign(nptr, &index);
	limit = limit_range(sign);
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		digit = nptr[index] - '0';
		if (check_overflow(value, digit, limit))
			return (*error = -1, 0);
		value = value * 10 + digit;
		index++;
	}
	return (value * sign);
}
