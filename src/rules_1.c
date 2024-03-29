/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:27:45 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 23:19:12 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*last;

	if ((*stack)->n->n == NULL)
	{
		(*stack)->p = (*stack)->n;
		(*stack)->p->p = NULL;
		(*stack)->p->n = (*stack);
		(*stack)->n = NULL;
		(*stack) = (*stack)->p;
	}
	else
	{
		iter = *stack;
		last = ft_stacklast(*stack);
		iter = last->p;
		last->n = iter;
		iter->n = NULL;
		iter->p->n = last;
		last->p = iter->p;
		iter->p = last;
	}
}

void	sa(t_stack **a, int is_printed)
{
	if (ft_stacksize(*a) > 1)
	{
		swap_top(a);
		if (!is_printed)
			ft_printf("sa\n");
	}
}

void	sb(t_stack **b, int is_printed)
{
	if (ft_stacksize(*b) > 1)
	{
		swap_top(b);
		if (!is_printed)
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b, int is_printed)
{
	if (ft_stacksize(*b) > 1 && ft_stacksize(*b) > 1)
	{
		swap_top(a);
		swap_top(b);
		if (!is_printed)
			ft_printf("ss\n");
	}
}

void	pa(t_stack **a, t_stack**b, int is_printed)
{
	if (ft_stacksize(*b) > 0)
	{
		push(a, pop(b));
		if (!is_printed)
			ft_printf("pa\n");
	}
}
