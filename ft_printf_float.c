/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:34:07 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/19 19:34:07 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_ch(int c)
{
	write(1,&c,1);
}

void	ft_printf_float(double num)
{
	int	x;
	float	y;
	int	z;

	x = (int)num;
	y = num - x;
	y *= 100;
	z = (int)y;
	ft_printf_str("disorder:  ");
	if (x < 10)
	{
		if (x == 0)
			put_ch('0');
		else
		{
			put_ch('0');
                	put_ch(x + '0');
		}
	}
	else
	{
		put_ch((x / 10) + '0');
                put_ch((x % 10) + '0');
	}
	put_ch('.');	
	put_ch((z / 10) + '0');
	put_ch((z % 10) + '0');
	put_ch('%');
}
