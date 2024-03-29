/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:00:57 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 21:10:54 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*last;

	iter = *stack;
	*stack = iter->n;
	iter->n = NULL;
	last = ft_stacklast(*stack);
	last->n = iter;
	(*stack)->p = NULL;
	last->n->p = last;
}

void	rra(t_stack **a, int is_printed)
{
	if (ft_stacksize(*a) > 1)
	{
		rotate_reverse(a);
		if (!is_printed)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, int is_printed)
{
	if (ft_stacksize(*b) > 1)
	{
		rotate_reverse(b);
		if (!is_printed)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b, int is_printed)
{
	if (ft_stacksize(*a) && ft_stacksize(*b))
	{
		rotate_reverse(a);
		rotate_reverse(b);
		if (!is_printed)
			ft_printf("rrr\n");
	}
}
