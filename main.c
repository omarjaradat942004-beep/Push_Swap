/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:28:20 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/16 22:44:33 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	t_snode *stack_a;
	t_snode	*current;

	stack_a = NULL;

	parser(argc, argv, &stack_a);
	insert_sort(&stack_a);
	current  = stack_a;
	while (!is_empty(&current))
	{
		printf("%d\n",current->value);
		current = current->next;
	}
}
