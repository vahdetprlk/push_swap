/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:46:50 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 21:10:41 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack**b, int is_printed)
{
	if (ft_stacksize(*a) > 0)
	{
		push(b, pop(a));
		if (!is_printed)
			ft_printf("pb\n");
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if ((*stack)->n->n == NULL)
	{
		(*stack)->p = (*stack)->n;
		(*stack)->n = NULL;
		(*stack)->p->p = NULL;
		(*stack)->p->n = *stack;
		*stack = (*stack)->p;
	}
	else
	{
		last = ft_stacklast(*stack);
		last->n = *stack;
		*stack = last;
		last->p->n = NULL;
		(*stack)->p = NULL;
		(*stack)->n->p = *stack;
	}
}

void	ra(t_stack **a, int is_printed)
{
	if (ft_stacksize(*a) > 0)
	{
		rotate(a);
		if (!is_printed)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **b, int is_printed)
{
	if (ft_stacksize(*b) > 0)
	{
		rotate(b);
		if (!is_printed)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack**b, int is_printed)
{
	if (ft_stacksize(*a) > 0 && ft_stacksize(*b) > 0)
	{
		rotate(a);
		rotate(b);
		if (!is_printed)
			ft_printf("rr\n");
	}
}
