/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/03 16:48:02 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack **stack)
{
	t_stack	*iter;
	int		min;

	iter = *stack;
	min = iter->data;
	while (iter->next)
	{
		if (iter->next->data < min)
			min = iter->next->data;
		iter = iter->next;
	}
	return (min);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*iter;

	if (stack)
	{
		iter = *stack;
		while (iter->next)
		{
			if (iter->data < iter->next->data)
				return (0);
			iter = iter->next;
		}
		return (1);
	}
	return (0);
}

void	sort_three(t_stack **stack)
{
	if (!is_sorted(stack))
	{
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data < ft_stacklast(*stack)->data)
			ra(stack);
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data > ft_stacklast(*stack)->data)
			sa(stack);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data > ft_stacklast(*stack)->data)
			rra(stack);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data < ft_stacklast(*stack)->data)
		{
			ra(stack);
			sa(stack);
		}
		if (find_min(stack) == ft_stacklast(*stack)->data
			&& (*stack)->data < (*stack)->next->data)
		{
			rra(stack);
			sa(stack);
		}
	}
}
