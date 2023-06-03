/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:46:50 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/28 00:39:00 by vparlak          ###   ########.fr       */
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
	t_stack	*iter;
	t_stack	*temp;

	if ((*stack)->next->next == NULL)
	{
		temp = (*stack)->next;
		temp->next = *stack;
		(*stack)->next = NULL;
		*stack = temp;
	}
	else
	{
		iter = *stack;
		while (iter->next->next != NULL)
			iter = iter->next;
		iter->next->next = *stack;
		*stack = iter->next;
		iter->next = NULL;
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
