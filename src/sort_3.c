/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:11:54 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/14 00:12:54 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
