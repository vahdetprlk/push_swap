/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:17:35 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/11 14:25:20 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bastir(t_stack *stack)
{
	t_stack	*iter;

	iter = stack;
	while (!(iter == NULL))
	{
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}
