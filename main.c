/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:28:20 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/17 16:05:03 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


char	**flag_split(void)
{
	char	*str;
	char	**strings;
	char	c;

	str = "--simple,--medium,--complex,--adaptive,--bench";
        c = ',';
        strings = ft_split(str,c);
	return (strings);
}	

static int	flag_count(int argc, char **argv)
{
	int     index;
	int	index2;
	int     count;
	char	**result;
	int	wrong_order;


	wrong_order = 0;
	result = flag_split();
	index = 1;
	count = 0;
	while (index < argc)
	{
		index2 = 0;
		while (index2 < 5)
		{
			if (ft_strncmp(argv[index],result[index2],ft_strlen(result[index2])) == 0)
				count++;
			index2++;
		}
		index++;
	}
	index2 = 0;
	while (index2 < 5)
	{
		if (ft_strncmp(argv[count],result[index2],ft_strlen(result[index2])) == 0)
			wrong_order++;
		index2++;
	}
	if (wrong_order != 1)
		return (-1);
	return (count);
}
int main(int argc, char **argv)
{
	t_snode *stack_a;
	int	counter;
	//t_snode	*current;

	stack_a = NULL;
	counter = flag_count(argc, argv);
	if (counter > 2 || counter == -1)
		return(ft_printf_str("Error(flag overload)"), -1);
	printf("the number of flags is :%d\n",counter);
	parser(argc, argv, &stack_a, &counter);
	/*
	if 
	insert_sort(&stack_a);
	current  = stack_a;
	while (!is_empty(&current))
	{
		printf("%d\n",current->value);
		current = current->next;
	}
	*/
}
