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

static void	put_chr(int c)
{
	write(2, &c, 1);
}

void	ft_printf_float(double num)
{
	int	x;

	x = (int)(num * 10000);
	write(2, "[bench] disorder:  ", 19);
	put_chr((x / 1000) + '0');
	put_chr((x / 100) % 10 + '0');
	put_chr('.');
	put_chr((x / 10) % 10 + '0');
	put_chr((x % 10) + '0');
	put_chr('%');
}
