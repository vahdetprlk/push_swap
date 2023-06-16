/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 21:12:20 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_middle(int *pivot, t_stack **stack_a, int len)
{
	int		i;
	int		*tmp;
	t_stack	*iter;

	tmp = (int *)malloc(sizeof(int) * len);
	if (!tmp)
		return (0);
	i = 0;
	iter = ft_stacklast(*stack_a);
	while (i < len)
	{
		tmp[i] = iter->d;
		iter = iter->p;
		i++;
	}
	ft_sort_int_tmp(tmp, len);
	*pivot = tmp[len / 2];
	free(tmp);
	return (1);
}

int	is_sorted(t_stack **stack, char flag, int len)
{
	int		i;
	t_stack	*last;

	last = ft_stacklast(*stack);
	if (flag == 'a')
	{
		i = 1;
		while (i++ < len)
		{
			if (last->d > last->p->d)
				return (0);
			last = last->p;
		}
	}
	else if (flag == 'b')
	{
		i = 1;
		while (i++ < len)
		{
			if (last->d < last->p->d)
				return (0);
			last = last->p;
		}
	}
	return (1);
}

int	find_min(t_stack **stack)
{
	t_stack	*iter;
	int		min;

	iter = *stack;
	min = iter->d;
	while (iter->n)
	{
		if (iter->n->d < min)
			min = iter->n->d;
		iter = iter->n;
	}
	return (min);
}

void	sort_three_first(t_stack **stack, char flag)
{
	if (!is_sorted(stack, flag, 3))
	{
		if (find_min(stack) == (*stack)->n->d
			&& (*stack)->d < ft_stacklast(*stack)->d)
			ra(stack, 0);
		if (find_min(stack) == (*stack)->n->d
			&& (*stack)->d > ft_stacklast(*stack)->d)
			sa(stack, 0);
		if (find_min(stack) == (*stack)->d
			&& (*stack)->n->d > ft_stacklast(*stack)->d)
			rra(stack, 0);
		if (find_min(stack) == (*stack)->d
			&& (*stack)->n->d < ft_stacklast(*stack)->d)
		{
			ra(stack, 0);
			sa(stack, 0);
		}
		if (find_min(stack) == ft_stacklast(*stack)->d
			&& (*stack)->d < (*stack)->n->d)
		{
			rra(stack, 0);
			sa(stack, 0);
		}
	}
}
