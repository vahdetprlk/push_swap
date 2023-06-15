/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:33:26 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 01:29:27 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_instructions(char **rule_list)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_printf("%s", str);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	char	**str_list;
	char	*rule_list;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		str_list = add_to_list(argc, argv);
		check_arguments(str_list);
		init_stack_a(&a, str_list);
		init_instructions(&rule_list);
		ft_printf("%s", rule_list);
		free_stacks(&a, &b);
	}
	return (0);
}
