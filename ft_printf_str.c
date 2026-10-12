/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:20:01 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/12 16:40:53 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_str(char *str)
{
	size_t	index;
	int		counter;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	index = 0;
	counter = 0;
	while (str[index])
	{
		if (write(1, &str[index], 1) == -1)
			return (-1);
		index++;
		counter++;
	}
	return (counter);
}
