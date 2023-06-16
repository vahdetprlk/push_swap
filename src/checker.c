/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:33:26 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 23:17:21 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack **a, t_stack **b, int status)
{
	free_stacks(a, b);
	if (status)
		ft_printf("Error\n");
	exit(1);
}

void	run_rules(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(rule, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(rule, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(rule, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(rule, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(rule, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(rule, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(rule, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(rule, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(rule, "rrr\n"))
		rrr(a, b, 1);
	else if (!ft_strcmp(rule, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(rule, "pb\n"))
		pb(a, b, 1);
	else
		free_error(a, b, 1);
}

void	init_instructions(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		run_rules(str, a, b);
		str = NULL;
		str = get_next_line(0);
	}
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
		init_instructions(&a, &b);
		if (is_sorted(&a, 'a', ft_stacksize(a)))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stacks(&a, &b);
	}
	return (0);
}
