/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/05 21:41:35 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = (int)ft_stacksize(*a);
	size_b = (int)ft_stacksize(*b);
	if (size_a && !is_sorted(a, 'a'))
	{
		if (size_a == 2)
			sa(a);
		else if (size_a == 3)
		{
			sort_three_a(a, 'a');
			sort_b(b, a);
		}
		else
			divide_a(a, b);
		sort_a(a, b);
	}
	sort_b(b ,a);
}

void	sort_b(t_stack **b, t_stack **a)
{
	int	size;

	size = (int)ft_stacksize(*b);
	if (size && !is_sorted(b, 'b'))
	{
		if (size == 2)
			sb(b);
		else if (size == 3)
		{
			sort_three_b(b, 'b');
			while (0 < size)
			{
				pa(a, b);
				size--;
			}
		}
		else
			divide_b(b, a);
		sort_b(b, a);
	}
 	while (0 < size)
	{
		pa(a, b);
		size--;
	}
}

void	divide_a(t_stack **a, t_stack **b)
{
	int		pivot;
	int		tmp;
	int		count;

	tmp = 0;
	count = 0;
	pivot = find_middle(a);
	count = (int)ft_stacksize(*a);
	while (count--)
	{
		tmp = ft_stacklast(*a)->data;
		if (pivot > tmp)
			pb(a, b);
		else
			ra(a);
	}
}

void	divide_b(t_stack **b, t_stack **a)
{
	int		pivot;
	int		tmp;
	int		count;

	tmp = 0;
	count = 0;
	pivot = find_middle(b);
	count = (int)ft_stacksize(*b);
	while (count--)
	{
		tmp = ft_stacklast(*b)->data;
		if (pivot > tmp)
			pa(a, b);
		else
			rb(b);
	}
}

void	sort_three_b(t_stack **stack, char flag)
{
	if (!is_sorted(stack, flag))
	{
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data < ft_stacklast(*stack)->data)
		{
			rrb(stack);
			sb(stack);
		}
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data > ft_stacklast(*stack)->data)
			rrb(stack);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data > ft_stacklast(*stack)->data)
			sb(stack);
		if (find_min(stack) == ft_stacklast(*stack)->data
			&& (*stack)->data < (*stack)->next->data)
			rb(stack);
		if (find_min(stack) == ft_stacklast(*stack)->data
			&& (*stack)->data > (*stack)->next->data)
		{
			rb(stack);
			sb(stack);
		}
	}
}
