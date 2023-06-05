/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:12:52 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/04 21:01:43 by vparlak          ###   ########.fr       */
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

int	is_sorted(t_stack **stack, char flag)
{
	t_stack	*iter;

	if (stack)
	{
		iter = *stack;
		while (iter->next)
		{
			if ((iter->data < iter->next->data && flag == 'a')
				|| (iter->data > iter->next->data && flag == 'b'))
				return (0);
			iter = iter->next;
		}
		return (1);
	}
	return (0);
}

void	sort_three(t_stack **stack, char flag)
{
	if (!is_sorted(stack, flag))
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

void	bubble_sort(t_stack **stack)
{
	int		tmp;
	t_stack	*iter_i;
	t_stack	*iter_j;

	iter_i = *stack;
	while (iter_i)
	{
		iter_j = iter_i->next;
		while (iter_j)
		{
			if (iter_i->data < iter_j->data)
			{
				tmp = iter_i->data;
				iter_i->data = iter_j->data;
				iter_j->data = tmp;
			}
			iter_j = iter_j->next;
		}
		iter_i = iter_i->next;
	}
}

int	find_middle(t_stack **stack)
{
	int		rvalue;
	int		i;
	int		size;
	t_stack	*iter;
	t_stack	*tmp;

	i = 0;
	tmp = NULL;
	iter = *stack;
	while (iter != NULL)
	{
		push(&tmp, iter->data);
		iter = iter->next;
	}
	bubble_sort(&tmp);
	iter = tmp;
	size = (int)ft_stacksize(tmp) / 2;
	while (i < size)
	{
		iter = iter->next;
		i++;
	}
	rvalue = iter->data;
	return (rvalue);
}
