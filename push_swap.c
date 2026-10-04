/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:00:26 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/04 14:50:24 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	initialize(Stack *stack)
{
	stack->top = -1;
}

int	is_full(Stack  *stack)
{
	return (stack->top >= MAX_SIZE - 1);
}

int     is_empty(Stack  *stack)
{
        return (stack->top == -1);
}

void	push(Stack * stack, int value)
{
	if (is_full(stack))
	{
		printf("the stack is full(stack overflow)");
		return ;
	}
	stack->arr[++stack->top] = value;
	printf("Pushed %d onto the stack\n", value);
}

int	pop(Stack *stack)
{
	int	popped;

	if (is_empty(stack))
	{
		printf("the stack is empty");
		return -1;
	}
	popped = stack->arr[stack->top];
	stack->top--;
	return (popped);
}

int	peak(Stack *stack)
{
	if (is_empty(stack))
	{
		printf("the stack is empty");
		return -1;
	}
	return (stack->arr[stack->top]);

}
int main()
{
	Stack stack;

	initialize(&stack);

	push(&stack, 6);
	push(&stack, 1);
	push(&stack, 4);
	printf("%d",peak(&stack));
}
