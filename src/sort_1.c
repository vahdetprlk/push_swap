/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/05 00:49:38 by vparlak          ###   ########.fr       */
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
			sort_three(a, 'a');
		else
			divide(a, b);
		sort_a(a, b);
		sort_b(a, b);
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
	printf("--\n");
}

void	divide(t_stack **a, t_stack **b)
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
