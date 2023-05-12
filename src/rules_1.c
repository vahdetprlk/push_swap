/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:27:45 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/13 00:56:23 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*temp;

	if ((*stack)->next->next == NULL)
	{
		temp = (*stack)->next;
		(*stack)->next = NULL;
		temp->next = *stack;
		*stack = temp;
	}
	else
	{
		iter = *stack;
		while (iter->next->next != NULL)
			iter = iter->next;
		temp = iter->next;
		temp->next = iter;
		iter->next = NULL;
		iter = *stack;
		while (iter->next->next != NULL)
			iter = iter->next;
		iter->next = temp;
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
