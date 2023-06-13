/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/13 20:38:14 by vparlak          ###   ########.fr       */
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
			ra(stack);
		if (find_min(stack) == (*stack)->n->d
			&& (*stack)->d > ft_stacklast(*stack)->d)
			sa(stack);
		if (find_min(stack) == (*stack)->d
			&& (*stack)->n->d > ft_stacklast(*stack)->d)
			rra(stack);
		if (find_min(stack) == (*stack)->d
			&& (*stack)->n->d < ft_stacklast(*stack)->d)
		{
			ra(stack);
			sa(stack);
		}
		if (find_min(stack) == ft_stacklast(*stack)->d
			&& (*stack)->d < (*stack)->n->d)
		{
			rra(stack);
			sa(stack);
		}
	}
}

void	sort_three_a_i(t_stack **a, t_stack **b, int len)
{
	while (len != 3 || !(ft_stacklast(*a)->d < ft_stacklast(*a)->p->d
			&& ft_stacklast(*a)->p->d < ft_stacklast(*a)->p->p->d))
	{
		if (len == 3 && ft_stacklast(*a)->d > ft_stacklast(*a)->p->d
			&& ft_stacklast(*a)->p->p->d)
			sa(a);
		else if (len == 3 && !(ft_stacklast(*a)->p->p->d > ft_stacklast(*a)->d
				&& ft_stacklast(*a)->p->p->d > ft_stacklast(*a)->p->d))
		{
			pb(a, b);
			len--;
		}
		else if (ft_stacklast(*a)->d > ft_stacklast(*a)->p->d)
			sa(a);
		else if (len++)
			pa(a, b);
	}
}

void	sort_three_a(t_stack **a, t_stack **b, int len)
{
	if (len == 3 && ft_stacksize(*a) == 3)
		sort_three_first(a, 'a');
	else if (len == 2)
	{
		if (ft_stacklast(*a)->d > ft_stacklast(*a)->p->d)
			sa(a);
	}
	else if (len == 3)
	{
		sort_three_a_i(a, b, len);
	}
}

void	sort_small_b_i(t_stack **b, t_stack **a, int len)
{
	while (len || !(ft_stacklast(*a)->d < ft_stacklast(*a)->p->d
			&& ft_stacklast(*a)->p->d < ft_stacklast(*a)->p->p->d))
	{
		if (len == 1 && ft_stacklast(*a)->d > ft_stacklast(*a)->p->d)
			sa(a);
		else if ((len == 1
				|| (len >= 2
					&& ft_stacklast(*b)->d > ft_stacklast(*b)->p->d)
				|| (len == 3
					&& ft_stacklast(*b)->d > ft_stacklast(*b)->p->p->d)))
		{
			pa(a, b);
			len--;
		}
		else
			sb(b);
	}
}

void	sort_small_b(t_stack **b, t_stack **a, int len)
{
	if (len == 1)
		pa(a, b);
	else if (len == 2)
	{
		if (ft_stacklast(*b)->d < ft_stacklast(*b)->p->d)
			sb(b);
		while (len--)
			pa(a, b);
	}
	else if (len == 3)
	{
		sort_small_b_i(b, a, len);
	}
}

void	ft_sort(t_stack **a, t_stack **b, int len)
{
	if (!is_sorted(a, 'a', len))
	{
		if (len == 2)
			sa(a);
		else if (len == 3)
			sort_three_first(a, 'a');
		else
			sort_a(a, b, len, 0);
	}
}

int	sort_a(t_stack **a, t_stack **b, int len, int count)
{
	int	pivot;
	int	i;

	if (is_sorted(a, 'a', len))
		return (1);
	i = len;
	if (len <= 3)
	{
		sort_three_a(a, b, len);
		return (1);
	}
	if (!find_middle(&pivot, a, len))
		return (0);
	while (len != i / 2 + i % 2)
	{
		if (ft_stacklast(*a)->d < pivot && (len--))
			pb(a, b);
		else if (++count)
			ra(a);
	}
	while ((i / 2 + i % 2) != (int)ft_stacksize(*a) && count--)
		rra(a);
	return (sort_a(a, b, (i / 2 + i % 2), 0)
		&& sort_b(b, a, i / 2, 0));
	return (1);
}

int	sort_b(t_stack **b, t_stack **a, int len, int count)
{
	int	pivot;
	int	i;

	if (!count && is_sorted(b, 'b', len))
		while (len--)
			pa(a, b);
	if (len <= 3)
	{
		sort_small_b(b, a, len);
		return (1);
	}
	i = len;
	if (!find_middle(&pivot, b, len))
		return (0);
	while (len != i / 2)
	{
		if (ft_stacklast(*b)->d >= pivot && (len--))
			pa(a, b);
		else if (++count)
			rb(b);
	}
	while (i / 2 != (int)ft_stacksize(*b) && count--)
		rrb(b);
	return (sort_a(a, b, (i / 2 + i % 2), 0)
		&& sort_b(b, a, i / 2, 0));
}
