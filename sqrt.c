/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:33:27 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/14 16:05:29 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int	ft_round(float num)
{
	int	whole;
	int	decimal;

	whole = (int)num;
	decimal = num - whole;
	if (decimal < 0.5)
		return (whole);
	return (whole + 1);

}
int	sqare_root(int num)
{
	int	index;

	index = 0;
	while (index <= num)
	{
		if (index * index == num)
			return (index);
		index++;
	}
	return (-1);
}

int main()
{
	printf("%d",sqare_root(101));

}
