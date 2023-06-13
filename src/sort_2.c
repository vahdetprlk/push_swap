/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:10:54 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/14 00:11:41 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
