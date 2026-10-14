/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:03:45 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/14 10:57:04 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H



#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

#include <stdlib.h>
#include <unistd.h>
typedef struct list
{
        int     top;
        int     arr[MAX_SIZE];
}Stack;

int	ft_atoi(const char *nptr, int *error);
int	ft_isdigit(int c);
int	ft_printf_str(char *str);
int	ft_printf_decimal(int num);
int	parser(int argc, char **argv);
char	*ft_itoa(int n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
