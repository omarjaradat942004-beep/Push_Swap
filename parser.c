/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:12:30 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/12 16:40:07 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser(int argc, char **argv)
{
	int     index;
        int     index2;
        int     exit;
        int     num;


        num = 0;
        exit = 0;
        index = 1;
        if (argc == 1)
        {
                ft_printf_str("there is no valid arguments");
                return (0);
        }
        while (index < argc)
        {
                index2 = 0;
                if (argv[index][0] == '-' || argv[index][0] == '+')
                                index2++;
                if (!argv[index][index2])
                {
                        ft_printf_str("Error has occured (invalid arguments detected)");
                        return (-1);
                }
                while (argv[index][index2])
                {
                        if (!ft_isdigit(argv[index][index2]))
                                exit = -1;
                        index2++;
                }
                index++;
        }
        if (exit == -1)
        {
                ft_printf_str("Error has occured (invalid arguments detected)");
                return (-1);
        }
        index = 1;
        while (index < argc)
        {
                num = ft_atoi(argv[index],&exit);
                if (exit == -1)
                {
                        ft_printf_str("Error has occured (int overflow)");
                        return (-1);
                }
                ft_printf_decimal(num);
                index++;
        }
	return (0);
}
