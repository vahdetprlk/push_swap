/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:46:50 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/12 00:09:37 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack**b)
{
	if (ft_stacksize(*a) > 0)
	{
		push(b, pop(a));
		printf("pb\n");
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if ((*stack)->next->next == NULL)
	{
		(*stack)->prev = (*stack)->next;
		(*stack)->next = NULL;
		(*stack)->prev->prev = NULL;
		(*stack)->prev->next = *stack;
		*stack = (*stack)->prev;
	}
	else
	{
		last = ft_stacklast(*stack);
		last->next = *stack;
		*stack = last;
		last->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next->prev = *stack;
	}
}

void	ra(t_stack **a)
{
	if (ft_stacksize(*a) > 0)
	{
		rotate(a);
		printf("ra\n");
	}
}

void	rb(t_stack **b)
{
	if (ft_stacksize(*b) > 0)
	{
		rotate(b);
		printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack**b)
{
	if (ft_stacksize(*a) > 0 && ft_stacksize(*b) > 0)
	{
		rotate(a);
		rotate(b);
		printf("rr\n");
	}
}
