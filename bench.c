/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:10:38 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/22 15:13:34 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t   digit_count_2(long numb)
{
        int     counter;

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

static int     ft_printf_decimal_2(int num)
{
        int             counter;
        long    numb;
        char    *str;

        numb = (long)num;
        counter = digit_count_2(numb);
        str = ft_itoa(num);
        if (write(2, str, counter) == -1)
        {
                free(str);
                return (-1);
        }
        free(str);
	return(0);

}

static int     ft_printf_str_2(char *str)
{
        size_t  index;
        int             counter;

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

static char    **flag_split_2(void)
{
        char    *str;
        char    **strings;
        char    c;

        str = "--simple,--medium,--complex,--adaptive,--bench";
        c = ',';
        strings = ft_split(str, c);
        return (strings);
}

void	benchmark(int argc, char **argv, int counter, float disorder)
{
	char	**str;
	int	index;
	int	index2;

	str = flag_split_2();
	ft_printf_float(disorder);
	ft_printf_str_2("\n");
	if (counter == 1)
		ft_printf_str_2("strategy = adaptive\n");
	else
	{
		index = 1;
		while (index <= counter)
		{
                	index2 = 0;
                	while (index2 < 3)
                	{
                        	if (ft_strlen(argv[index]) == ft_strlen(str[index2])
                                	&& ft_strncmp(argv[index], str[index2], ft_strlen(str[index2])) == 0)
                        	{
					if (index2 == 0)
						ft_printf_str_2("[bench] strategy: Simple / O(n^2)\n");
					else if (index2 == 1)
						ft_printf_str_2("[bench] strategy: Medium / O(n sqrt(n))\n");
					else if (index2 == 2)
						ft_printf_str_2("[bench] strategy: Complex / O(n log(n))\n");
				}
                        }
                        index2++;
                }
                index++;
	}
	ft_printf_decimal_2(argc);
}
