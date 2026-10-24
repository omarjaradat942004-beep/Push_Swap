/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:00:26 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/24 20:23:32 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_snode	*new_node(int value)
{
	t_snode	*node;

	node = malloc(sizeof(t_snode));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	is_empty(t_snode **stack)
{
	return (!stack || !*stack);
}

void	push_node(t_snode **stack, t_snode *node)
{
	if (!stack || !node)
	{
		ft_printf_str("The stack is full already!\n");
		return ;
	}
	node->next = *stack;
	node->prev = NULL;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

t_snode	*pop_node(t_snode **stack)
{
	t_snode	*popped_node;

	if (is_empty(stack))
	{
		ft_printf_str("The stack is empty!\n");
		return (NULL);
	}
	popped_node = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	popped_node->next = NULL;
	return (popped_node);
}

int	peak(t_snode **stack)
{
	if (is_empty(stack))
	{
		ft_printf_str("The stack is empty!\n");
		return (-1);
	}
	return ((*stack)->value);
}
