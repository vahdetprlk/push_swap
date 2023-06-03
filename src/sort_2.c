/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:12:52 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/04 00:09:02 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	size_t	count;
	t_stack	*iter;
	t_stack	*tmp;

	tmp = NULL;
	iter = *stack;
	while (iter != NULL)
	{
		push(&tmp, iter->data);
		iter = iter->next;
	}
	bubble_sort(&tmp);
	iter = stack;
		ortadaki sayıyı bul kaçıncı indexte hesapla kaçıncı indexteki hangi sayı ise o ortanca sayının int değeridir
	return (1);
}
