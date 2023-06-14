/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:00:34 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/14 23:17:45 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(char **str_list)
{
	if (!is_int_list(str_list))
		error_case("Error", 0);
	else if (!is_duplicate(str_list))
		error_case("Error", 0);
}

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
