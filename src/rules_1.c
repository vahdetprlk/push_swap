/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:27:45 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/12 00:09:16 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*last;

	if ((*stack)->next->next == NULL)
	{
		(*stack)->prev = (*stack)->next;
		(*stack)->prev->prev = NULL;
		(*stack)->prev->next = (*stack);
		(*stack)->next = NULL;
		(*stack) = (*stack)->prev;
	}
	else
	{
		iter = *stack;
		last = ft_stacklast(*stack);
		iter = last->prev;
		last->next = iter;
		iter->next = NULL;
		iter->prev->next = last;
		last->prev = iter->prev;
		iter->prev = last;
	}
}

void	sa(t_stack **a)
{
	if (ft_stacksize(*a) > 1)
	{
		swap_top(a);
		printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	if (ft_stacksize(*b) > 1)
	{
		swap_top(b);
		printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*b) > 1 && ft_stacksize(*b) > 1)
	{
		swap_top(a);
		swap_top(b);
		printf("ss\n");
	}
}

void	pa(t_stack **a, t_stack**b)
{
	if (ft_stacksize(*b) > 0)
	{
		push(a, pop(b));
		printf("pa\n");
	}
}
