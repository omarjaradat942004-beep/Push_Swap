/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:38:24 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/12 16:38:50 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	digit_count(long numb)
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

int	ft_printf_decimal(int num)
{
	int		counter;
	long	numb;
	char	*str;

	numb = (long)num;
	counter = digit_count(numb);
	str = ft_itoa(num);
	if (write(1, str, counter) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (counter);
}
