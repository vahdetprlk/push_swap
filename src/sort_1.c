/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/04 18:51:21 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack **a, t_stack **b)
{
	int	size;

	size = (int)ft_stacksize(*a);
	if (!is_sorted(a, 'a'))
	{
		if (size == 2)
			sa(a);
		else if (size == 3)
			sort_three(a, 'a'); // eğer sadece a'yı sıralamak için gerekirse düzenle
		else
			divide(a, b);
		sort_a(a, b);
		sort_b(a, b);
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*iter;

	size = (int)ft_stacksize(*b);
	iter = *b;
	if (!is_sorted(b, 'b'))
	{
		if (size == 2)
			sb(b);
		else if (size == 3)
			sort_three(b, 'b'); // eğer sadece a'yı sıralamak için gerekirse düzenle
	}
	while (iter)
	{
		pa(a, b);
		iter = iter->next;
	}
	sort_a(a, b);
}

void	pre_divide(t_stack **a, int pivot)
{
	t_stack	*iter;
	int		tmp;

	tmp = 0;
	iter = (*a);
	while (iter->data != pivot)
	{
		tmp++;
		iter = iter->next;
	}
	while ((*a)->data != pivot)
	{
		if (tmp > (int)ft_stacksize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

void	divide(t_stack **a, t_stack **b)
{
	t_stack	*iter;
	int		pivot;
	int		tmp;

	tmp = 0;
	pivot = find_middle(a);
	pre_divide(a, pivot);
	iter = (*a)->next;
	while (iter != (*a))
	{
		tmp = ft_stacklast(*a)->data;
		if (pivot > tmp)
		{
			pb(a, b);
			if (tmp == iter->data)
				break ;
		}
		else
			ra(a);
	}
}
