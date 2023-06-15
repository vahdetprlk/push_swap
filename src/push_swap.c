/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:00:34 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 00:49:33 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**str_list;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		str_list = add_to_list(argc, argv);
		check_arguments(str_list);
		init_stack_a(&a, str_list);
		ft_sort(&a, &b, (int)ft_stacksize(a));
		free_stacks(&a, &b);
	}
	return (0);
}
