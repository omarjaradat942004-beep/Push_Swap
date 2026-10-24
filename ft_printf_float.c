/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:34:07 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/22 13:21:31 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_chr(char c)
{
	if (write(2, &c, 1) == -1)
		return ;
}

static void	put_int(int n)
{
	if (n >= 10)
		put_int(n / 10);
	put_chr(n % 10 + '0');
}

void	ft_printf_float(double num)
{
	int	x;

	x = (int)(num * 10000 + 0.5);
	if (write(2, "[bench] disorder: ", 18) == -1)
		return ;
	put_int(x / 100);
	put_chr('.');
	put_chr((x % 100) / 10 + '0');
	put_chr(x % 10 + '0');
	put_chr('%');
}
